/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:10:16 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/30 14:20:54 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		str[i] = ft_tolower(str[i]);
	i = 0;
	while (str[i])
	{
		while (!ft_isalnum(str[i]) && str[i])
			i++;
		if (str[i] && ft_islower(str[i]) && !ft_isalnum(str[i - 1])
			&& !ft_isupper(str[i - 1]) && !ft_isdigit(str[i - 1]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
