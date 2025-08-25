/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:40:26 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/30 14:19:49 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strins(char *dst, char *src)
{
	char	*dst_cpy;

	dst_cpy = ft_memalloc(ft_strlen(dst) + ft_strlen(src) + 1);
	ft_strlcpy(dst_cpy, src, ft_strlen(src) + 1);
	ft_strlcat(dst_cpy, dst, ft_strlen(dst) + ft_strlen(src) + 1);
	return (dst_cpy);
}
