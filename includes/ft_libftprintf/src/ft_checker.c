/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:39:40 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 12:04:59 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_cflag(char c)
{
	if (c == '-' || c == '+' || c == ' '
			|| c == '#' || c == '0')
		return (1);
	return (0);
}

int		ft_cwidth(char c)
{
	if (c > '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_cprec(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int		ft_clen(char *s, int i)
{
	if ((s[i] == 'l' && s[i + 1] != 'l') ||
			(s[i] == 'h' && s[i + 1] != 'h') ||
			(s[i] == 'l' && s[i + 1] == 'l') ||
			(s[i] == 'h' && s[i + 1] == 'h') ||
			(s[i] == 'L'))
		return (1);
	return (0);
}

int		ft_cspec(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'O' || c == 'u' ||
			c == 'x' || c == 'X' || c == 'f' || c == 'c' || c == 'U'
			|| c == 'C' || c == 's' || c == 'p' || c == '%')
		return (1);
	return (0);
}
