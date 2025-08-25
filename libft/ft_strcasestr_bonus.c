/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:14:51 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/30 12:33:25 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *big, const char *little)
{
	size_t	little_len;

	little_len = (size_t)ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && *little)
	{
		big = ft_strchr(big, little[0]);
		if (big)
		{
			if (!ft_strncasecmp(big, little, little_len))
				return ((char *)big);
		}
		else
			break ;
		big++;
	}
	return (NULL);
}
