/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:27:41 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/15 15:33:11 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_py;
	char	*s_cpy;
	int		i;
	int		j;

	s_cpy = (char *)s;
	c_py = (char)c;
	i = 0;
	j = -1;
	while (s_cpy[i])
	{
		if (s_cpy[i] == c_py)
			j = i;
		i++;
	}
	if (j != -1)
		return (&s_cpy[j]);
	if (c_py == 0)
		return (&s_cpy[i]);
	return (NULL);
}
