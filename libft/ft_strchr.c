/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:14:29 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/15 15:47:34 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_py;
	char	*s_cpy;
	int		i;

	i = 0;
	s_cpy = (char *)s;
	c_py = (char)c;
	while (s_cpy[i])
	{
		if (s_cpy[i] == c_py)
			return (&s_cpy[i]);
		i++;
	}
	if (c_py == 0)
		return (&s_cpy[i]);
	return (NULL);
}
