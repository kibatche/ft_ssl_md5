/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:09:26 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/15 11:52:53 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	unsigned char	char_cpy;
	unsigned char	*b_cpy;

	b_cpy = (unsigned char *)b;
	char_cpy = (unsigned char)c;
	while (len--)
	{
		if (*b_cpy == char_cpy)
			return (b_cpy);
		b_cpy++;
	}
	return (NULL);
}
