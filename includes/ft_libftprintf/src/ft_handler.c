/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:41:17 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 13:17:22 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_dihan(t_printf *flags, char *res, int64_t n)
{
	if ((flags->flag & PLUS || flags->flag & SPACE || n < 0) &&
			(((uint64_t)n >= (uint64_t)-9223372036854775807) ||
			(int64_t)n >= 0))
	{
		if ((flags->flag & ZERO) && flags->prec == 0)
		{
			flags->width -= 1;
			if (flags->width > ft_strlen_int(res))
				res = ft_fixwidth(flags, res);
			res = ft_fixps(flags, res, n);
		}
		else
		{
			res = ft_fixps(flags, res, n);
			if (flags->width > ft_strlen_int(res))
				res = ft_fixwidth(flags, res);
		}
	}
	else if (flags->width > ft_strlen_int(res))
		res = ft_fixwidth(flags, res);
	return (res);
}

char	*ft_ohan(t_printf *flags, char *res, uint64_t n)
{
	if (flags->flag & HASH)
	{
		if (flags->width >= 0 && flags->prec == 0 &&
				flags->rprec == 0)
			res = ft_fixhash(flags, res, n);
		else if (flags->width == 0 && flags->prec > 0 &&
				(ft_numlen_base(n, 8) < ft_numlen_base(n, 10)))
			res = ft_fixhash(flags, res, n);
		else if (flags->width > 0 && flags->rprec == 1)
			res = ft_fixhash(flags, res, n);
		else if (flags->width >= 0 && flags->prec < ft_strlen_int(res))
			res = ft_fixhash(flags, res, n);
		else if (flags->prec == 0 && n == 0 && flags->rprec == 1)
			res = ft_fixhash(flags, res, n);
		else if (flags->width == 0 && flags->prec > 0 && n > 0 &&
				(ft_numlen_base(n, 8) != ft_numlen_base(n, 10)))
			res = ft_fixhash(flags, res, n);
	}
	if (flags->width > ft_strlen_int(res))
		res = ft_fixwidth(flags, res);
	return (res);
}

char	*ft_xxhan(t_printf *flags, char *res, uint64_t n)
{
	if (flags->flag & HASH)
	{
		if ((flags->flag & ZERO) && flags->prec == 0 && n > 0)
		{
			flags->width -= 2;
			if (flags->width > ft_strlen_int(res))
				res = ft_fixwidth(flags, res);
			res = ft_fixhash(flags, res, n);
		}
		else
		{
			res = ft_fixhash(flags, res, n);
			if (flags->width > ft_strlen_int(res))
				res = ft_fixwidth(flags, res);
		}
	}
	else if (flags->width > ft_strlen_int(res))
		res = ft_fixwidth(flags, res);
	return (res);
}

char	*ft_fhan(t_printf *flags, char *res, double n)
{
	if (flags->flag & PLUS || flags->flag & SPACE || n < 0)
	{
		if ((flags->flag & ZERO) && flags->prec == 0)
		{
			flags->width -= 1;
			if (flags->width > ft_strlen_int(res))
				res = ft_fixwidth(flags, res);
			res = ft_fixfloat(flags, res, n);
		}
		else
		{
			res = ft_fixfloat(flags, res, n);
			if (flags->width > ft_strlen_int(res))
				res = ft_fixwidth(flags, res);
		}
	}
	else if (flags->width > ft_strlen_int(res))
		res = ft_fixwidth(flags, res);
	return (res);
}

char	*ft_fixfloat(t_printf *flags, char *res, double n)
{
	if (flags->flag & PLUS && n >= 0)
		res = ft_apptstr(res, 1, '+', 1);
	else if (n < 0)
		res = ft_apptstr(res, 1, '-', 1);
	else if (flags->flag & SPACE)
		res = ft_apptstr(res, 1, ' ', 1);
	return (res);
}
