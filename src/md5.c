/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:51:03 by mstupnik          #+#    #+#             */
/*   Updated: 2020/01/28 14:51:57 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void    md5_pad1(t_ssl *md5, char *data)
{
    int     i;
    size_t  len;

    i = -1;
    len = ft_strlen(data);
    while (++i < (int)len)
    {
        md5->data[md5->len] = data[i];
        md5->len++;
        if (md5->len == 64)
        {
            md5_process(md5, md5->data);
            md5->blen += 64;
            md5->len = 0;
        }
    }
}

void    md5_pad2(t_ssl *md5, unsigned char h[])
{
    int i;

    i = md5->len;
    if (md5->len < 56)
    {
        md5->data[i++] = 0x80;
        while (i < 56)
            md5->data[i++] = 0x00;
    }
    else if (md5->len >= 56)
    {
        md5->data[i++] = 0x80;
        while (i < 64)
            md5->data[i++] = 0x00;
        md5_process(md5, md5->data);
        ft_memset(md5->data, 0, 56);
    }
    md5->blen += md5->len * 8;
    i = 55;
    while (++i < 64)
        md5->data[i] = md5->blen >> (i - 56) * 8;
    md5_process(md5, md5->data);
    endw2b(md5, h);
}

void    md5_init(t_ssl *md5)
{
    md5->len = 0;
    md5->blen = 0;
    md5->abcd[0] = 0x67452301;
    md5->abcd[1] = 0xefcdab89;
    md5->abcd[2] = 0x98badcfe;
    md5->abcd[3] = 0x10325476;
    md5->temp[0] = md5->abcd[0];
    md5->temp[1] = md5->abcd[1];
    md5->temp[2] = md5->abcd[2];
    md5->temp[3] = md5->abcd[3];
    md5->g_f = 0;
    md5->g_g = 0;
    md5->endn = endian_check();
}

void    ft_md5(char *msg, t_ssl *md5)
{
    int             i;
    unsigned char   h[16];

    i = -1;
    ft_memset(h, 0, 16);
    md5_init(md5);
    md5_pad1(md5, msg);
    md5_pad2(md5, h);
    while (++i < 16)
        ft_printf("%02x", h[i]);
}