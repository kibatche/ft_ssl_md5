/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:55:58 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/15 14:18:48 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*b1_cpy;
	unsigned char	*b2_cpy;

	b1_cpy = (unsigned char *)b1;
	b2_cpy = (unsigned char *)b2;
	if (len == 0)
		return (0);
	while (--len && *b1_cpy == *b2_cpy)
	{
		b1_cpy++;
		b2_cpy++;
	}
	return ((int)(*b1_cpy - *b2_cpy));
}
