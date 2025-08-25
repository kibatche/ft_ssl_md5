/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:50:40 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/30 12:12:49 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t		little_len;

	little_len = (size_t)ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && *little)
	{
		big = ft_strchr(big, little[0]);
		if (big)
		{
			if (!ft_strncmp(big, little, little_len))
				return ((char *)big);
		}
		else
			break ;
		big++;
	}
	return (NULL);
}
