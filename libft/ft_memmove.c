/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:05:02 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/09 11:40:21 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_cpy;
	const char	*src_cpy;
	int			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_cpy = (char *)dst;
	src_cpy = (const char *)src;
	if (src_cpy < dst_cpy)
	{
		i = (int)len;
		while (i--)
			*(dst_cpy + i) = *(src_cpy + i);
	}
	else
	{
		i = -1;
		while (++i < (int)len)
			*(dst_cpy + i) = *(src_cpy + i);
	}
	return (dst);
}
