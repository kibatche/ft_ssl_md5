/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:48:20 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/29 14:01:12 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_cpy;
	unsigned int	i;
	size_t			len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	s_cpy = (char *)malloc(sizeof(char) * len + 1);
	if (!s_cpy)
		return (NULL);
	i = -1;
	while (++i < len)
		s_cpy[i] = f(i, s[i]);
	s_cpy[i] = 0;
	return (s_cpy);
}
