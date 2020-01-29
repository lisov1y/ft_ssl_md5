/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:00:28 by mstupnik          #+#    #+#             */
/*   Updated: 2020/01/28 14:41:08 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	calculate_f(t_ssl *md5, int i)
{
	md5->g_f = DEF_F(md5->temp[1], md5->temp[2], md5->temp[3]);
	md5->g_g = i;
}

void	calculate_g(t_ssl *md5, int i)
{
	md5->g_f = DEF_G(md5->temp[1], md5->temp[2], md5->temp[3]);
	md5->g_g = (5 * i + 1) % 16;
}

void	calculate_h(t_ssl *md5, int i)
{
	md5->g_f = DEF_H(md5->temp[1], md5->temp[2], md5->temp[3]);
	md5->g_g = (3 * i + 5) % 16;
}

void	calculate_i(t_ssl *md5, int i)
{
	md5->g_f = DEF_I(md5->temp[1], md5->temp[2], md5->temp[3]);
	md5->g_g = (7 * i) % 16;
}