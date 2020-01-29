/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dioux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:02:48 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 10:52:51 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*di_spec(va_list *args, t_printf *flags, char *res)
{
	int64_t val;

	val = ft_dilen(args, flags);
	if (flags->rprec == 0 && flags->prec == 0 && val == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_vl((ABS(val)));
	if (flags->prec > ft_strlen_int(res))
		res = ft_fixprec((flags->prec - ft_strlen_int(res)), res);
	res = ft_dihan(flags, res, val);
	return (res);
}

char	*o_spec(va_list *args, t_printf *flags, char *res)
{
	uint64_t val;

	val = ft_ouxxlen(args, flags);
	if (flags->rprec == 0 && flags->prec == 0 && val == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_base(val, 8, 0);
	if (flags->prec > ft_strlen_int(res))
		res = ft_fixprec((flags->prec - ft_strlen_int(res)), res);
	res = ft_ohan(flags, res, val);
	return (res);
}

char	*u_spec(va_list *args, t_printf *flags, char *res)
{
	uint64_t val;

	val = ft_ouxxlen(args, flags);
	if (flags->rprec == 0 && flags->prec == 0 && val == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_base(val, 10, 0);
	if (flags->prec > ft_strlen_int(res))
		res = ft_fixprec((flags->prec - ft_strlen_int(res)), res);
	if (flags->width > ft_strlen_int(res))
		res = ft_fixwidth(flags, res);
	return (res);
}

char	*xx_spec(va_list *args, t_printf *flags, char *res)
{
	uint64_t val;

	val = ft_ouxxlen(args, flags);
	if (flags->rprec == 0 && flags->prec == 0 && val == 0)
		res = ft_strdup("");
	else if (flags->spec == 'x')
		res = ft_itoa_base(val, 16, 0);
	else if (flags->spec == 'X')
		res = ft_itoa_base(val, 16, 1);
	if (flags->prec > ft_strlen_int(res))
		res = ft_fixprec((flags->prec - ft_strlen_int(res)), res);
	res = ft_xxhan(flags, res, val);
	return (res);
}
