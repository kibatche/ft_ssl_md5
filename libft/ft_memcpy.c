/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:51:14 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/09 11:43:16 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*dst_cpy;
	const char	*src_cpy;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_cpy = (char *)dst;
	src_cpy = (const char *)src;
	while (len--)
		*(dst_cpy++) = *(src_cpy++);
	return (dst);
}
