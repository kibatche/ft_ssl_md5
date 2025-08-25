/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:49:19 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/30 13:21:38 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s, const char *append, size_t count)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (append[i] && count--)
	{
		s[len + i] = append[i];
		i++;
	}
	s[len + i] = '\0';
	return (s);
}
