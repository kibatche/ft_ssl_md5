/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:55:14 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/29 14:00:20 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_utf8_twobytes(unsigned int c)
{
	char	*bytes;

	bytes = ft_memalloc(3);
	bytes[0] = (c >> 6) | 192;
	bytes[1] = (c & 63) | 128;
	return (bytes);
}

static char	*ft_utf8_threebytes(unsigned int c)
{
	char	*bytes;

	bytes = ft_memalloc(4);
	bytes[0] = (c >> 12) | 224;
	bytes[1] = (c >> 6 & 63) | 128;
	bytes[2] = (c & 63) | 128;
	return (bytes);
}

static char	*ft_utf8_fourbytes(unsigned int c)
{
	char	*bytes;

	bytes = ft_memalloc(5);
	bytes[0] = (c >> 18) | 240;
	bytes[1] = ((c >> 12) & 63) | 128;
	bytes[2] = ((c >> 6) & 63) | 128;
	bytes[3] = (c & 63) | 128;
	return (bytes);
}

void	ft_putwchar_fd(int c, int fd)
{
	char	*bytes;
	wchar_t	d;

	d = (unsigned int)c;
	if (d < 128)
	{
		write(fd, &c, 1);
		return ;
	}
	else if (d < 2048)
		bytes = ft_utf8_twobytes(d);
	else if (d < 65536)
		bytes = ft_utf8_threebytes(d);
	else if (d < 1114112)
		bytes = ft_utf8_fourbytes(d);
	write(fd, bytes, ft_strlen(bytes));
}
