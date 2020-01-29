/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenmodifs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:58:22 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 09:57:50 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int64_t		ft_dilen(va_list *args, t_printf *flags)
{
	int64_t		mod;

	if (flags->len & LC_L)
		mod = va_arg(*args, long int);
	else if (flags->len & LC_H)
		mod = (short)va_arg(*args, int);
	else if (flags->len & LC_LL)
		mod = va_arg(*args, int64_t);
	else if (flags->len & LC_HH)
		mod = (signed char)va_arg(*args, int);
	else
		mod = va_arg(*args, int);
	return (mod);
}

uint64_t	ft_ouxxlen(va_list *args, t_printf *flags)
{
	uint64_t	mod;

	if (flags->len & LC_L)
		mod = va_arg(*args, unsigned long int);
	else if (flags->len & LC_H)
		mod = va_arg(*args, unsigned int);
	else if (flags->len & LC_LL)
		mod = va_arg(*args, uint64_t);
	else if (flags->len & LC_HH)
		mod = va_arg(*args, unsigned int);
	else
		mod = va_arg(*args, unsigned int);
	return (mod);
}

double		ft_flen(va_list *args, t_printf *flags)
{
	double	mod;

	if (flags->len & LC_L)
		mod = va_arg(*args, double);
	else if (flags->len & UC_L)
		mod = va_arg(*args, long double);
	else
		mod = va_arg(*args, double);
	return (mod);
}
