/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:42:42 by chbadad           #+#    #+#             */
/*   Updated: 2021/09/02 16:18:16 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_wrds(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == sep)
			s++;
		if (*s != sep && *s)
		{
			count++;
			while (*s != sep && *s)
				s++;
		}
	}
	return (count);
}

static char	*ft_strdup_split(char const *s, char sep, char **tab, int j)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != sep && s[i])
		i++;
	word = (char *)malloc(sizeof(char) * i + 1);
	if (!word)
	{
		i = -1;
		while (++i < j)
			free(tab[i]);
		free(tab);
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != sep)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (nb_wrds(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c && *s)
		{
			tab[i] = ft_strdup_split(s, c, tab, i);
			if (tab[i] == NULL)
				return (NULL);
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
