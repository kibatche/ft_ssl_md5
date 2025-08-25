/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_by_level_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myhuong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:21:01 by myhuong           #+#    #+#             */
/*   Updated: 2021/11/28 15:30:39 by myhuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	level_count(t_btree *node, int level)
{
	int	left_level;
	int	right_level;

	if (!node)
		return (level);
	if (!node->left && !node->right)
		return (level);
	++level;
	left_level = level_count(node->left, level);
	right_level = level_count(node->right, level);
	if (left_level > right_level)
		return (left_level);
	else
		return (right_level);
}

static int	has_next(t_btree *node)
{
	int	nb;

	nb = 0;
	if (node->left)
		nb++;
	if (node->right)
		nb++;
	return (nb);
}

static int	queue_maker(t_btree ***new_queue, t_btree **queue, int size_queue)
{
	t_btree	*node;
	int		new_size;
	int		i;

	i = 0;
	new_size = 0;
	while (i < size_queue)
		new_size += has_next(queue[i++]);
	*new_queue = malloc(sizeof(t_btree *) * new_size);
	if (!*new_queue)
		return (-1);
	i = 0;
	while (i < new_size)
	{
		node = *queue++;
		if (node->left)
			(*new_queue)[i++] = node->left;
		if (node->right)
			(*new_queue)[i++] = node->right;
	}
	return (new_size);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_btree	***wait_q;
	int		nb_level;
	int		size;
	int		i;
	int		j;

	if (root && applyf)
		applyf(root->item, 0, 1);
	nb_level = level_count(root, 0);
	wait_q = malloc(sizeof(t_btree **) * nb_level);
	if (!wait_q || !nb_level)
		return (free(wait_q));
	i = 0;
	size = queue_maker(wait_q, &root, 1);
	while (i < nb_level && size != -1)
	{
		j = -1;
		while (++j < size)
			applyf((wait_q[i])[j]->item, i + 1, (j == 0));
		if (i + 1 != nb_level)
			size = queue_maker(wait_q + i + 1, wait_q[i], size);
		free(wait_q[i++]);
	}
	free(wait_q);
}
