/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:51:03 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/02 10:21:05 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	print_md5(unsigned int h)
{
	int				i;
	unsigned char	*buf;

	buf = (unsigned char *)&h;
	i = -1;
	while (++i < 4)
		ft_printf("%2.2x", buf[i]);
}

void	md5_manip(t_md5 *md5, int i, unsigned int tmp1, unsigned int tmp2)
{
	unsigned int tmp;

	tmp = md5->d;
	md5->d = md5->c;
	md5->c = md5->b;
	md5->b = md5->b + leftrotate((md5->a + tmp1 + g_md5_k[i] + md5->tmp[tmp2]),
		g_md5_r[i]);
	md5->a = tmp;
}

void	md5_algo(t_md5 *md5, int i, unsigned int tmp1,
	unsigned int tmp2)
{
	while (++i < 64)
	{
		if (i < 16)
		{
			tmp1 = (md5->b & md5->c) | ((~md5->b) & md5->d);
			tmp2 = i;
		}
		else if (i < 32)
		{
			tmp1 = (md5->d & md5->b) | ((~md5->d) & md5->c);
			tmp2 = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			tmp1 = md5->b ^ md5->c ^ md5->d;
			tmp2 = (3 * i + 5) % 16;
		}
		else
		{
			tmp1 = md5->c ^ (md5->b | (~md5->d));
			tmp2 = (7 * i) % 16;
		}
		md5_manip(md5, i, tmp1, tmp2);
	}
}

t_md5	*md5_init(char *input_msg, size_t init_len)
{
	t_md5			*md5;
	unsigned int	bits_len;

	md5 = (t_md5 *)malloc(sizeof(t_md5));
	md5->h[0] = 0x67452301;
	md5->h[1] = 0xefcdab89;
	md5->h[2] = 0x98badcfe;
	md5->h[3] = 0x10325476;
	md5->offset = 0;
	md5->new_len = ((((init_len + 8) / 64) + 1) * 64) - 8;
	md5->msg = (unsigned char *)ft_strnew(md5->new_len + 64);
	ft_memcpy(md5->msg, input_msg, init_len);
	md5->msg[init_len] = 128;
	bits_len = init_len * 8;
	ft_memcpy(md5->msg + md5->new_len, &bits_len, 4);
	return (md5);
}

void	ft_md5(char *input_msg, size_t init_len)
{
	t_md5	*md5;
	int		i;

	md5 = md5_init(input_msg, init_len);
	while (md5->offset < md5->new_len)
	{
		md5->tmp = (unsigned int *)(md5->msg + md5->offset);
		md5->a = md5->h[0];
		md5->b = md5->h[1];
		md5->c = md5->h[2];
		md5->d = md5->h[3];
		md5_algo(md5, -1, 0, 0);
		md5->h[0] += md5->a;
		md5->h[1] += md5->b;
		md5->h[2] += md5->c;
		md5->h[3] += md5->d;
		md5->offset += (512 / 8);
	}
	free(md5->msg);
	i = -1;
	while (++i < 4)
		print_md5(md5->h[i]);
}
