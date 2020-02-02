/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fixflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:34:00 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 12:13:41 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_fixwidth(t_printf *flags, char *res)
{
	int ext;

	ext = (int)flags->width - ft_strlen(res);
	if (flags->flag & MINUS)
		res = ft_apptstr(res, ext, ' ', 0);
	else if ((flags->flag & ZERO) && flags->prec == 0)
		res = ft_apptstr(res, ext, '0', 1);
	else
		res = ft_apptstr(res, ext, ' ', 1);
	return (res);
}

void	ft_fixwidthi(t_printf *flags, int i)
{
	int ext;

	ext = (int)flags->width - 1;
	if (flags->flag & MINUS)
	{
		ft_putchar((char)i);
		while (ext--)
			ft_putchar(' ');
	}
	else if (flags->width > 0)
	{
		while (ext--)
			ft_putchar(' ');
		ft_putchar((char)i);
	}
	else
		ft_putchar((char)i);
	return ;
}

char	*ft_fixprec(int len, char *res)
{
	res = ft_apptstr(res, len, '0', 1);
	return (res);
}

char	*ft_fixps(t_printf *flags, char *res, int64_t n)
{
	if (flags->flag & PLUS && n >= 0)
		res = ft_apptstr(res, 1, '+', 1);
	else if ((flags->flag & PLUS) && n < 0)
		res = ft_apptstr(res, 1, '-', 1);
	else if ((flags->spec == 'd' || flags->spec == 'i') && n < 0)
		res = ft_apptstr(res, 1, '-', 1);
	else if (flags->flag & SPACE)
		res = ft_apptstr(res, 1, ' ', 1);
	return (res);
}

char	*ft_fixhash(t_printf *flags, char *res, uint64_t n)
{
	char *temp;

	if ((flags->flag & HASH) && (flags->spec == 'o')
			&& (!(n == 0 && flags->rprec == 1)))
	{
		temp = ft_strjoin("0", res);
		free(res);
		res = temp;
	}
	else if ((flags->flag & HASH) && flags->spec == 'x' && n > 0)
	{
		temp = ft_strjoin("0x", res);
		free(res);
		res = temp;
	}
	else if ((flags->flag & HASH) && flags->spec == 'X' && n > 0)
	{
		temp = ft_strjoin("0X", res);
		free(res);
		res = temp;
	}
	return (res);
}
