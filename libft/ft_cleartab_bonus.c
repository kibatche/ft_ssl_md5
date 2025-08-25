/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleartab_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:23:39 by etran             #+#    #+#             */
/*   Updated: 2021/12/29 12:22:47 by etran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function description :
** clears len elements from tab, then clears the tab itself
*/

void	*ft_cleartab(void **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(tab[i++]);
	free(tab);
	return (0);
}
