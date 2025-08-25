/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:05:11 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/30 11:32:38 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;
	size_t			i;

	s1_cpy = (unsigned char *)ft_strdup(s1);
	s2_cpy = (unsigned char *)ft_strdup(s2);
	i = 0;
	while (s1_cpy[i++])
		s1_cpy[i] = ft_tolower(s1_cpy[i]);
	i = 0;
	while (s2_cpy[i++])
		s2_cpy[i] = ft_tolower(s2_cpy[i]);
	return (ft_strcmp((const char *)s1_cpy, (const char *)s2_cpy));
}
