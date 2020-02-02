/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_macros_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:49:13 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/02 10:01:56 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint32_t	leftrotate(uint32_t n, int c)
{
	return (n << c | n >> (32 - c));
}

uint32_t	rightrotate(uint32_t n, int c)
{
	return (n >> c | n << (32 - c));
}

uint32_t	ch(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ (~(x) & (z)));
}

uint32_t	maj(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
}
