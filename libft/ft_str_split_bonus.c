/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_split_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:42:42 by chbadad           #+#    #+#             */
/*   Updated: 2021/09/13 14:52:18 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_wrds(char const *s, char *sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && ft_ischarset(*s, sep))
			s++;
		if (!ft_ischarset(*s, sep) && *s)
		{
			count++;
			while (!ft_ischarset(*s, sep) && *s)
				s++;
		}
	}
	return (count);
}

static char	*ft_strdup_split(char const *s, char *sep, char **tab, int j)
{
	int		i;
	char	*word;

	i = 0;
	while (!ft_ischarset(s[i], sep) && s[i])
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
	while (s[i] && !ft_ischarset(s[i], sep))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_str_split(char const *s, char *sep)
{
	int		i;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (nb_wrds(s, sep) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && ft_ischarset(*s, sep))
			s++;
		if (!ft_ischarset(*s, sep) && *s)
		{
			tab[i] = ft_strdup_split(s, sep, tab, i);
			if (tab[i] == NULL)
				return (NULL);
			i++;
			while (!ft_ischarset(*s, sep) && *s)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
