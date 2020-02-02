/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:24:11 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 12:07:07 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse(va_list *args, char *format, int *i, int *len)
{
	char		*res;
	t_printf	*flags;

	res = NULL;
	if (!(flags = ft_init()))
		return ;
	ft_extract(format, i, flags);
	if (flags->spec == '\0')
	{
		free(flags);
		return ;
	}
	res = ft_dispatcher(args, flags, res);
	if (flags->spec != 'c')
		ft_putstr(res);
	*len += ft_strlen(res);
	free(res);
	free(flags);
}

void	ft_extract(char *format, int *i, t_printf *flags)
{
	*i = *i + 1;
	if (format[*i])
	{
		if (ft_cflag(format[*i]))
			ft_sflag(format, i, flags);
		if (ft_cwidth(format[*i]))
			ft_swidth(format, i, flags);
		if (ft_cprec(format[*i]))
			ft_sprec(format, i, flags);
		else
			flags->rprec = 1;
		if (ft_clen(format, *i))
			ft_slen(format, i, flags);
		if (ft_cspec(format[*i]))
			ft_sspec(format, i, flags);
	}
}

char	*ft_dispatcher(va_list *args, t_printf *flags, char *res)
{
	if (flags->spec == 'd' || flags->spec == 'i')
		res = di_spec(args, flags, res);
	else if (flags->spec == 'o' || flags->spec == 'O')
		res = o_spec(args, flags, res);
	else if (flags->spec == 'u' || flags->spec == 'U')
		res = u_spec(args, flags, res);
	else if (flags->spec == 'x')
		res = xx_spec(args, flags, res);
	else if (flags->spec == 'X')
		res = xx_spec(args, flags, res);
	else if (flags->spec == 'f')
		res = f_spec(args, flags, res);
	else if (flags->spec == 's')
		res = s_spec(args, flags, res);
	else if (flags->spec == 'c' || flags->spec == 'C')
		res = c_spec(args, flags, res);
	else if (flags->spec == 'p')
		res = p_spec(args, flags, res);
	else if (flags->spec == '%')
		res = pr_spec(flags, res);
	return (res);
}
