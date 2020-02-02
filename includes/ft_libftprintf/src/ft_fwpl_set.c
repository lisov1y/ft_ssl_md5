/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwpl_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:06:43 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 12:08:29 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_sflag(char *format, int *i, t_printf *flags)
{
	while (format[*i] && ft_cflag(format[*i]))
	{
		if (format[*i] == '-')
			flags->flag |= MINUS;
		else if (format[*i] == '+')
			flags->flag |= PLUS;
		else if (format[*i] == ' ')
			flags->flag |= SPACE;
		else if (format[*i] == '#')
			flags->flag |= HASH;
		else if (format[*i] == '0')
			flags->flag |= ZERO;
		*i = *i + 1;
	}
}

void	ft_swidth(char *format, int *i, t_printf *flags)
{
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		flags->width = (flags->width * 10) + format[*i] - '0';
		*i = *i + 1;
	}
}

void	ft_sprec(char *format, int *i, t_printf *flags)
{
	*i = *i + 1;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		flags->prec = (flags->prec * 10) + format[*i] - '0';
		*i = *i + 1;
	}
}

void	ft_slen(char *format, int *i, t_printf *flags)
{
	if (format[*i] == 'l' && format[*i + 1] != 'l')
	{
		flags->len |= LC_L;
		*i = *i + 1;
	}
	else if (format[*i] == 'h' && format[*i + 1] != 'h')
	{
		flags->len |= LC_H;
		*i = *i + 1;
	}
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
	{
		flags->len |= LC_LL;
		*i = *i + 2;
	}
	else if (format[*i] == 'h' && format[*i + 1] == 'h')
	{
		flags->len |= LC_HH;
		*i = *i + 2;
	}
	else if (format[*i] == 'L')
	{
		flags->len |= UC_L;
		*i = *i + 1;
	}
}

void	ft_sspec(char *format, int *i, t_printf *flags)
{
	if (format[*i] == 'd' || format[*i] == 'i')
		flags->spec = 'd';
	else if (format[*i] == 'o' || format[*i] == 'O')
		flags->spec = 'o';
	else if (format[*i] == 'u' || format[*i] == 'U')
		flags->spec = 'u';
	else if (format[*i] == 'x')
		flags->spec = 'x';
	else if (format[*i] == 'X')
		flags->spec = 'X';
	else if (format[*i] == 'f')
		flags->spec = 'f';
	else if (format[*i] == 's')
		flags->spec = 's';
	else if (format[*i] == 'c' || format[*i] == 'C')
		flags->spec = 'c';
	else if (format[*i] == 'p')
		flags->spec = 'p';
	else if (format[*i] == '%')
		flags->spec = '%';
	*i = *i + 1;
}
