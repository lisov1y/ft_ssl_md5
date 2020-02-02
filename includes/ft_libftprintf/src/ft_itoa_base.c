/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:00:58 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/17 18:35:16 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_numlen_base(uintmax_t nb, int base)
{
	int		l;

	if (nb <= 0)
	{
		l = 1;
		nb *= -1;
	}
	else
		l = 0;
	while (nb)
	{
		l++;
		nb /= base;
	}
	return (l);
}

int		ft_valcheck(uint64_t n, int uc)
{
	if (n <= 9)
		return (48);
	else if (n >= 10 && n <= 15)
	{
		if (uc)
			return (55);
		else
			return (87);
	}
	return (0);
}

char	*ft_itoa_base(uint64_t n, int base, int uc)
{
	char	*s;
	int		len;

	len = ft_numlen_base(n, base);
	if (!(s = ft_strnew(len)))
		return (NULL);
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		s[--len] = n % base + ft_valcheck((n % base), uc);
		n /= base;
	}
	return (s);
}
