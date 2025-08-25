/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:58:33 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/22 13:46:39 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (dstsize >= dest_len)
		src_len += dest_len;
	else
		src_len += dstsize;
	if (dstsize > dest_len)
	{
		while (src[i] && dest_len < dstsize - 1)
		{
			dst[dest_len] = src[i];
			dest_len++;
			i++;
		}
	}
	dst[dest_len] = '\0';
	return (src_len);
}
