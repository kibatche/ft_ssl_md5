/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:11:19 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/25 14:01:21 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*s2;
	unsigned int	len;

	if (!s1)
		return (NULL);
	while (*s1 && ft_ischarset((int)*s1, set))
		s1++;
	if (!*s1)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	while (ft_ischarset(s1[--len], set))
		continue ;
	len += 1;
	s2 = (char *)malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}
