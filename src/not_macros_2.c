/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_macros_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:59:03 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/02 10:20:27 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint32_t	ep0(uint32_t n)
{
	return (rightrotate(n, 2) ^ rightrotate(n, 13) ^ rightrotate(n, 22));
}

uint32_t	ep1(uint32_t n)
{
	return (rightrotate(n, 6) ^ rightrotate(n, 11) ^ rightrotate(n, 25));
}

uint32_t	sig0(uint32_t n)
{
	return (rightrotate(n, 7) ^ rightrotate(n, 18) ^ ((n) >> 3));
}

uint32_t	sig1(uint32_t n)
{
	return (rightrotate(n, 17) ^ rightrotate(n, 19) ^ ((n) >> 10));
}
