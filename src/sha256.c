/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:15:39 by mstupnik          #+#    #+#             */
/*   Updated: 2020/01/28 16:09:21 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void    ft_sha256(char *str, t_ssl *md5)
{
	int	            i;
	unsigned char   h[16];

	i = -1;
	ft_memset(h, 0, 16);
	ft_memset(str, 0, 16);
	while (++i < 4)
		ft_printf("%x\n", md5->abcd[i]);
	i = -1;
	while (++i < 16)
		ft_printf("%02x", h[i]);
}