/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:12:39 by mstupnik          #+#    #+#             */
/*   Updated: 2020/01/26 16:19:34 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		to_big(int bits32)
{
	unsigned char	bytes[4];
	int				ret;

	bytes[0] = (unsigned char)((bits32 >> 0) & 0xff);
	bytes[1] = (unsigned char)((bits32 >> 8) & 0xff);
	bytes[2] = (unsigned char)((bits32 >> 16) & 0xff);
	bytes[3] = (unsigned char)((bits32 >> 24) & 0xff);
	ret = ((int)bytes[0] << 24) |
		((int)bytes[1] << 16) |
		((int)bytes[2] << 8) |
		((int)bytes[3] << 0);
	return (ret);
}

int		to_little(int bits32)
{
	unsigned char	bytes[4];
	int				ret;

	bytes[0] = (unsigned char)((bits32 >> 0) & 0xff);
	bytes[1] = (unsigned char)((bits32 >> 8) & 0xff);
	bytes[2] = (unsigned char)((bits32 >> 16) & 0xff);
	bytes[3] = (unsigned char)((bits32 >> 24) & 0xff);
	ret = ((int)bytes[0] << 0) |
		((int)bytes[1] << 8) |
		((int)bytes[2] << 16) |
		((int)bytes[3] << 24);
	return (ret);
}

int     endian_check(void)
{
    int     temp;
    char    *c;

    temp = 0x01234567;
    c = (char *)&temp;
    if (c[0] == 0x67)
        return (1);
    return (0);
}