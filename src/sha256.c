/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:15:39 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/02 12:06:47 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void		sha256_manipulation(t_sha256 *sha256, unsigned int *buf)
{
	int				i;
	unsigned int	tmp1;
	unsigned int	tmp2;
	unsigned int	x[8];

	i = -1;
	while (++i < 8)
		x[i] = sha256->h[i];
	i = -1;
	while (++i < 64)
	{
		tmp1 = x[7] + ep1(x[4]) + ch(x[4], x[5], x[6]) + g_sha256_k[i] + buf[i];
		tmp2 = ep0(x[0]) + maj(x[0], x[1], x[2]);
		x[7] = x[6];
		x[6] = x[5];
		x[5] = x[4];
		x[4] = x[3] + tmp1;
		x[3] = x[2];
		x[2] = x[1];
		x[1] = x[0];
		x[0] = tmp1 + tmp2;
	}
	i = -1;
	while (++i < 8)
		sha256->h[i] += x[i];
}

void		modify_data(t_sha256 *sha256)
{
	int				i;
	int				j;
	unsigned int	buf[64];

	i = -1;
	j = 0;
	while (++i < 16)
	{
		buf[i] = (sha256->data[j] << 24) | (sha256->data[j + 1] << 16) |
		(sha256->data[j + 2] << 8) | (sha256->data[j + 3]);
		j += 4;
	}
	i -= 1;
	while (++i < 64)
		buf[i] = sig1(buf[i - 2]) + buf[i - 7] +
			sig0(buf[i - 15]) + buf[i - 16];
	sha256_manipulation(sha256, buf);
}

void		msg_prepare(t_sha256 *sha256, char *input, size_t init_len)
{
	size_t	i;

	i = 0;
	while (i < init_len)
	{
		sha256->data[sha256->datalen] = input[i];
		sha256->datalen++;
		if (sha256->datalen == 64)
		{
			modify_data(sha256);
			sha256->blen += 512;
			sha256->datalen = 0;
		}
		i++;
	}
}

t_sha256	*sha256_init(void)
{
	t_sha256		*sha256;

	sha256 = (t_sha256 *)malloc(sizeof(t_sha256));
	sha256->h[0] = 0x6a09e667;
	sha256->h[1] = 0xbb67ae85;
	sha256->h[2] = 0x3c6ef372;
	sha256->h[3] = 0xa54ff53a;
	sha256->h[4] = 0x510e527f;
	sha256->h[5] = 0x9b05688c;
	sha256->h[6] = 0x1f83d9ab;
	sha256->h[7] = 0x5be0cd19;
	sha256->datalen = 0;
	sha256->blen = 0;
	return (sha256);
}

void		ft_sha256(char *input, size_t init_len)
{
	t_sha256		*sha256;
	unsigned char	hash[32];
	int				i;

	sha256 = sha256_init();
	msg_prepare(sha256, input, init_len);
	get_hash(sha256, hash);
	i = -1;
	while (++i < 32)
		ft_printf("%2.2x", hash[i]);
}
