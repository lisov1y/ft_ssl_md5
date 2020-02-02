/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:23:44 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/01 19:46:49 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "ft_ssl.h"

static const unsigned int g_sha256_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

typedef struct			s_sha256
{
	unsigned int		h[8];
	unsigned char		data[64];
	unsigned int		datalen;
	unsigned long long	blen;
}						t_sha256;

/*
** sha256.c
*/

void					ft_sha256(char *input_msg, size_t init_len);
t_sha256				*sha256_init(void);
void					msg_prepare(t_sha256 *dt, char *input_msg,
							size_t init_len);
void					modify_data(t_sha256 *dt);
void					sha256_manipulation(t_sha256 *dt, unsigned int *buf);

/*
** sha256_process.c
*/

void					get_hash(t_sha256 *dt, unsigned char *hash);
void					append_length_bits2padding(t_sha256 *dt);
void					reverse_bytes(t_sha256 *dt, unsigned char *hash);

/*
** not_macros_1.c
*/

uint32_t				rightrotate(uint32_t n, int c);
uint32_t				ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t				maj(uint32_t x, uint32_t y, uint32_t z);

/*
** not_macros_2.c
*/

uint32_t				ep0(uint32_t n);
uint32_t				ep1(uint32_t n);
uint32_t				sig0(uint32_t n);
uint32_t				sig1(uint32_t n);

#endif
