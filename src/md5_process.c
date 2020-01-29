/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:23:44 by mstupnik          #+#    #+#             */
/*   Updated: 2020/01/28 16:03:03 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int32_t	g_s[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

int32_t	g_k[64] = {0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};


void	endb2w(t_ssl *md5, unsigned char data[])
{
	int		i;

	i = -1;
	if (md5->endn== 1)
		while (++i < 16)
			md5->m[i] = (data[i * 4 + 0]) + (data[i * 4 + 1] << 8) +\
				(data[i * 4 + 2] << 16) + (data[i * 4 + 3] << 24);
	else
		while (++i < 16)
			md5->m[i] = (data[i * 4 + 0] << 24) + (data[i * 4 + 1] << 16) +\
				(data[i * 4 + 2] << 8) + (data[i * 4 + 3]);
}

void	endw2b(t_ssl *md5, unsigned char h[])
{
	int		i;

	i = -1;
	if (md5->endn == 1)
	{
		while (++i < 4)
		{
			h[i + 0] = (md5->abcd[0] >> (i * 8)) & 0x000000ff;
			h[i + 4] = (md5->abcd[1] >> (i * 8)) & 0x000000ff;
			h[i + 8] = (md5->abcd[2] >> (i * 8)) & 0x000000ff;
			h[i + 12] = (md5->abcd[3] >> (i * 8)) & 0x000000ff;
		}
	}
	else
	{
		while (++i < 4)
		{
			h[i + 0] = (md5->abcd[0] >> (24 - (i * 8))) & 0x000000ff;
			h[i + 4] = (md5->abcd[1] >> (24 - (i * 8))) & 0x000000ff;
			h[i + 8] = (md5->abcd[2] >> (24 - (i * 8))) & 0x000000ff;
			h[i + 12] = (md5->abcd[3] >> (24 - (i * 8))) & 0x000000ff;
		}
	}
}

void	md5_process(t_ssl *md5, unsigned char data[])
{
	int		i;

	endb2w(md5, data);
	i = -1;
	while (++i < 64)
	{
		if (i >= 0 && i <= 15)
			calculate_f(md5, i);
		else if (i >= 16 && i <= 31)
			calculate_g(md5, i);
		else if (i >= 32 && i <= 47)
			calculate_h(md5, i);
		else if (i >= 48 && i <= 63)
			calculate_i(md5, i);
		md5->g_f += md5->temp[0] + g_k[i] + md5->m[md5->g_g];
		md5->temp[0] = md5->temp[3];
		md5->temp[3] = md5->temp[2];
		md5->temp[2] = md5->temp[1];
		md5->temp[1] += ROT_LEFT(md5->g_f, g_s[i]);
	}
	md5->abcd[0] += md5->temp[0];
	md5->abcd[1] += md5->temp[1];
	md5->abcd[2] += md5->temp[2];
	md5->abcd[3] += md5->temp[3];
}
