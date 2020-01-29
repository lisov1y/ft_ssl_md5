/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:39:15 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/18 10:14:17 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf	*ft_init(void)
{
	t_printf *flags;

	if (!(flags = malloc(sizeof(flags))))
		return (NULL);
	flags->spec = '\0';
	flags->flag = 0;
	flags->len = 0;
	flags->prec = 0;
	flags->rprec = 0;
	flags->width = 0;
	return (flags);
}
