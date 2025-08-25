/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myhuong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:54:10 by myhuong           #+#    #+#             */
/*   Updated: 2021/11/28 15:31:06 by myhuong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_level(t_btree *node, int level)
{
	int	left_level;
	int	right_level;

	if (!node)
		return (level);
	if (!node->left && !node->right)
		return (level);
	++level;
	left_level = count_level(node->left, level);
	right_level = count_level(node->right, level);
	if (left_level > right_level)
		return (left_level);
	else
		return (right_level);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (count_level(root, 0));
}
