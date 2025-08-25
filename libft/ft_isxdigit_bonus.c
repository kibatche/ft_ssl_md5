/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:43:20 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/29 12:24:48 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isxdigit(int c)
{
	const char	*base_up;
	const char	*base_low;

	base_up = "0123456789ABCDEF";
	base_low = "0123456789abcdef";
	if (ft_ischarset(c, base_up) || ft_ischarset(c, base_low))
		return (1);
	return (0);
}
