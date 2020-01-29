/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fscpp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:47:15 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 09:39:04 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*f_spec(va_list *args, t_printf *flags, char *res)
{
	double fnum;

	fnum = ft_flen(args, flags);
	if (flags->rprec == 1)
		flags->prec = 6;
	res = ft_ftoa((ABS(fnum)), flags->prec, 0, flags);
	res = ft_fhan(flags, res, fnum);
	return (res);
}

char	*s_spec(va_list *args, t_printf *flags, char *res)
{
	char *s;
	char *temp;

	s = va_arg(*args, char *);
	if (s)
		res = ft_strdup(s);
	else
		res = ft_strdup("(null)");
	if (flags->rprec == 1)
		flags->prec = ft_strlen_int(res);
	if (flags->prec >= 0)
	{
		temp = ft_strndup(res, flags->prec);
		free(res);
		res = temp;
	}
	if (flags->width > ft_strlen_int(res))
		res = ft_fixwidth(flags, res);
	return (res);
}

char	*c_spec(va_list *args, t_printf *flags, char *res)
{
	int c;
	int i;

	c = va_arg(*args, int);
	ft_fixwidthi(flags, c);
	if (flags->width == 0)
		flags->width = 1;
	res = ft_strnew(flags->width);
	i = -1;
	while (++i < flags->width)
		res[i] = '$';
	return (res);
}

char	*p_spec(va_list *args, t_printf *flags, char *res)
{
	void *address;
	char *temp;

	address = va_arg(*args, void *);
	temp = ft_itoa_base((unsigned long long)address, 16, 0);
	res = ft_strjoin("0x", temp);
	free(temp);
	if (flags->width > ft_strlen_int(res))
		res = ft_fixwidth(flags, res);
	return (res);
}

char	*pr_spec(t_printf *flags, char *res)
{
	res = ft_strdup("%");
	if (flags->width > ft_strlen_int(res))
		res = ft_fixwidth(flags, res);
	return (res);
}
