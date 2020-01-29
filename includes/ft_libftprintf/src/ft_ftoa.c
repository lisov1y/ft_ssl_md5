/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:06:10 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 13:15:47 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_roundup(double f, long fpart, char *s, int i)
{
	f = (f - fpart) * 10;
	if (f >= 5.0)
		s[i - 1] = (fpart + 1) % 10 + '0';
}

int		ft_flolen(double f)
{
	long int	ipart;
	int			len;

	ipart = (long)ABS(f);
	len = 0;
	if (f < 0)
		len++;
	if (ipart == 0)
		len++;
	while (ipart > 0)
	{
		ipart /= 10;
		len++;
	}
	return (len);
}

char	*ft_cdtoa(double f, int i, int prec)
{
	char	*s;
	long	absed;

	if (!(s = ft_strnew(i)))
		return (NULL);
	absed = (long)ABS(f);
	if (prec == 0 && (((int)(f * 10) % 10) >= 5))
		absed++;
	s[i] = '\0';
	while (--i >= 0)
	{
		s[i] = absed % 10 + '0';
		absed /= 10;
	}
	if (f < 0)
		s[++i] = '-';
	return (s);
}

char	*ft_cftoa(double f, int prec, int of)
{
	char	*s;
	int		i;
	long	fpart;

	if (!(s = ft_strnew(prec + 2)))
		return (NULL);
	f = ABS(f);
	i = 0;
	fpart = 0;
	s[i++] = '.';
	while (prec-- > 0)
	{
		f = (f - fpart) * 10;
		fpart = (long)(f);
		if (of > 19)
			s[i++] = '0';
		else
			s[i++] = fpart % 10 + '0';
		of++;
	}
	if (prec == -1)
		ft_roundup(f, fpart, s, i);
	s[i] = '\0';
	return (s);
}

char	*ft_ftoa(double f, int prec, int len, t_printf *flags)
{
	char	*ipts;
	char	*fpts;
	char	*s;
	double	fpart;

	len = ft_flolen(f);
	if (prec > 0)
	{
		if (!(ipts = ft_cdtoa(f, len, flags->prec)))
			return (NULL);
		fpart = f - (long)f;
		if (!(fpts = ft_cftoa(fpart, prec, 0)))
			return (NULL);
		s = ft_strjoin(ipts, fpts);
		free(ipts);
		free(fpts);
	}
	else
	{
		if (!(s = ft_cdtoa(f, len, flags->prec)))
			return (NULL);
	}
	if (flags->prec == 0 && flags->flag & HASH)
		s = ft_apptstr(s, 1, '.', 0);
	return (s);
}
