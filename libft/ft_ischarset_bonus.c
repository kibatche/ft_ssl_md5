/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:05:18 by chbadad           #+#    #+#             */
/*   Updated: 2022/01/09 12:25:38 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function to determine if c is from the charset charset
 *
 * @param c
 * @param charset
 * @return int (1) if true, (0) if false
 */
int	ft_ischarset(int c, const char *charset)
{
	while (*charset)
	{
		if ((unsigned char)c == *charset)
			return (1);
		charset++;
	}
	return (0);
}
