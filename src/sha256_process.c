/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:12:39 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/01 18:53:46 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	reverse_bytes(t_sha256 *sha256, unsigned char *hash)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		hash[i] = (sha256->h[0] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4] = (sha256->h[1] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8] = (sha256->h[2] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (sha256->h[3] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (sha256->h[4] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (sha256->h[5] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (sha256->h[6] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (sha256->h[7] >> (24 - i * 8)) & 0x000000ff;
	}
}

void	append_length_bits2padding(t_sha256 *sha256)
{
	sha256->blen += sha256->datalen * 8;
	sha256->data[63] = sha256->blen;
	sha256->data[62] = sha256->blen >> 8;
	sha256->data[61] = sha256->blen >> 16;
	sha256->data[60] = sha256->blen >> 24;
	sha256->data[59] = sha256->blen >> 32;
	sha256->data[58] = sha256->blen >> 40;
	sha256->data[57] = sha256->blen >> 48;
	sha256->data[56] = sha256->blen >> 56;
	modify_data(sha256);
}

void	get_hash(t_sha256 *sha256, unsigned char *hash)
{
	unsigned int i;

	i = sha256->datalen;
	if (sha256->datalen < 56)
	{
		sha256->data[i++] = 0x80;
		while (i < 56)
			sha256->data[i++] = 0x00;
	}
	else
	{
		sha256->data[i++] = 0x80;
		while (i < 64)
			sha256->data[i++] = 0x00;
		modify_data(sha256);
		ft_memset(sha256->data, 0, 56);
	}
	append_length_bits2padding(sha256);
	reverse_bytes(sha256, hash);
}
