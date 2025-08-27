/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:25:02 by chbadad           #+#    #+#             */
/*   Updated: 2021/05/30 16:45:00 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strtrim(char *s1)
{
	int		i;
	char	*cpy;
	char	*res;

	cpy = ft_strndup(s1, ft_strlen(s1));
	i = 0;
	while (cpy[i] && cpy[i] != '\n')
		i++;
	if (cpy[i] == '\n')
		i++;
	res = ft_strndup(&cpy[i], ft_strlen(&cpy[i]));
	free(cpy);
	return (res);
}

int	ft_newline_chr(char *s)
{
	int		i;
	char	c;

	c = '\n';
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdupcat(char *s1, char *s2, char **save)
{
	char	*res;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	if (*save)
		free(*save);
	return (res);
}

char	*ft_strndup(const char *str, size_t len)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = (char *)malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	while (str[i] && len--)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
