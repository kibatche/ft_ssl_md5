/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:01:01 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/16 14:17:10 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	if (!number || !size)
		return (malloc(0));
	ptr = malloc(number * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * number);
	return (ptr);
}
