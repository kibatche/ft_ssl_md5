/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:24:47 by etran             #+#    #+#             */
/*   Updated: 2021/11/26 15:11:21 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)
			(void *, void *))
{
	t_btree	*tmp;
	int		ret;

	if (!root)
		return ;
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	ret = cmpf(item, (*root)->item);
	if (ret < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else if (ret > 0)
		btree_insert_data(&(*root)->right, item, cmpf);
	else
	{
		tmp = (*root)->right;
		(*root)->right = btree_create_node(item);
		(*root)->right->right = tmp;
	}
}
