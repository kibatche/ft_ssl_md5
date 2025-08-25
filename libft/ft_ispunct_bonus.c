/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:20:22 by chbadad           #+#    #+#             */
/*   Updated: 2021/04/01 11:35:06 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ispunct(int c)
{
	return (((unsigned char)c >= 32 && (unsigned char)c <= 47)
		|| ((unsigned char)c >= 58 && (unsigned char)c <= 64)
		|| ((unsigned char)c >= 91 && (unsigned char)c <= 96)
		|| ((unsigned char)c >= 123 && (unsigned char)c <= 126));
}
