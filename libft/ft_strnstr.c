/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:50:40 by chbadad           #+#    #+#             */
/*   Updated: 2021/05/22 15:35:34 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		little_len;
	size_t		len_cpy;
	const char	*big_cpy;

	big_cpy = big;
	len_cpy = len;
	little_len = (size_t)ft_strlen(little);
	if (!*little)
		return ((char *)big);
	if (len == 0 || !*big)
		return (NULL);
	while (len-- >= little_len && *big && *little)
	{
		big = ft_strchr(big, little[0]);
		if (big)
		{
			if (!ft_strncmp(big, little, little_len)
				&& ((big - big_cpy) + little_len) <= len_cpy)
				return ((char *)big);
		}
		else
			break ;
		big++;
	}
	return (NULL);
}
