/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:42:11 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/30 14:20:31 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s, const char *append)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	while (append[j])
	{
		s[j + i] = append[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}
