/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:04:24 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/29 12:25:08 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	const char	*spaces;

	spaces = " \t\n\r\v\f";
	if (ft_ischarset(c, spaces))
		return (1);
	return (0);
}
