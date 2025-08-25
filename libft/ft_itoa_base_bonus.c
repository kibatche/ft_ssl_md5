/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:21:48 by chbadad           #+#    #+#             */
/*   Updated: 2021/03/29 12:58:05 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long long nb, int base)
{
	int	count;

	count = 2;
	if (nb < 0)
	{
		nb *= -1;
		count += 1;
	}
	while (nb >= base)
	{
		nb /= base;
		count++;
	}
	return (count);
}

static char	*ft_itoazero(void)
{
	char	*convert;
	int		i;

	i = 0;
	convert = (char *)malloc(sizeof(char) * 2);
	if (!convert)
		return (NULL);
	convert[i++] = '0';
	convert[i] = 0;
	return (convert);
}

static void	ft_end_of_charray(char *str, int i, int sign)
{
	if (sign == -1)
		str[i++] = '-';
	str[i] = 0;
	ft_strrev(str);
}

char	*ft_itoa_base(long long n, int base)
{
	int		i;
	int		sign;
	char	*s_n;

	if (n == 0)
		return (ft_itoazero());
	sign = 1;
	i = 0;
	s_n = (char *)malloc(sizeof(char) * ft_count(n, base));
	if (!s_n)
		return (NULL);
	if (n < 0 && base == 10)
		sign *= -1;
	while (ft_abs((long)n))
	{
		if (ft_abs((long)n) % base < 10)
			s_n[i++] = ft_abs((long)n % base) + '0';
		else
			s_n[i++] = ft_abs((long)n % base) + 'A' - 10;
		n = ft_abs((long)n / base);
	}
	ft_end_of_charray(s_n, i, sign);
	return (s_n);
}
