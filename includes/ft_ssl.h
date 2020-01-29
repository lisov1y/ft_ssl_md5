/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:40:06 by mstupnik          #+#    #+#             */
/*   Updated: 2020/01/28 16:02:42 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "ft_libftprintf/includes/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>

# define ROT_LEFT(x,y) ((x << y) | (x >> (32 - y)))

# define DEF_F(x, y, z) ((x & y) | (~x & z))
# define DEF_G(x, y, z) ((x & z) | (y & ~z))
# define DEF_H(x, y, z) (x ^ y ^ z)
# define DEF_I(x, y, z) (y ^ (x | ~z))

typedef struct                  s_ssl
{
    int                         p;
    int                         q;
    int                         r;
    int                         s;
    int                         i;
    int                         endn;
    int                         pars;
    char                        *input;
    int                         fd;
    int                         file;
	unsigned int				m[16];
    unsigned int                len;
    unsigned long long int      blen;
    unsigned int                abcd[4];
    unsigned int                temp[4];
    unsigned int                g_f;
    unsigned int                g_g;
    unsigned char               data[64];
}                               t_ssl;


/*
** main.c
*/

int     main(int ac, char **av);

/*
** prep.c
*/

void    flag_check(t_ssl *md5, int ac, char **av);
void    check(t_ssl *md5, int ac, char **av);
void    frot(t_ssl *md5, char **av);
void    fnorot(t_ssl *md5, char **av);

/*
** read.c
*/

void    fgnl(char **p, int fd);
int     print_s(t_ssl *md5, int ac, char **av);
void    rots(t_ssl *md5, char **av);
void    norot(t_ssl *md5, char **av);
int     file_check(t_ssl *md5, char **av);

/*
** dispatcher.c
*/

void	calculate_f(t_ssl *md5, int i);
void	calculate_g(t_ssl *md5, int i);
void	calculate_h(t_ssl *md5, int i);
void	calculate_i(t_ssl *md5, int i);

/*
** end.c
*/

int		to_big(int bits32);
int		to_little(int bits32);
int     endian_check(void);

/*
** md5.c
*/

void    md5_pad1(t_ssl *md5, char *data);
void    md5_pad2(t_ssl *md5, unsigned char h[]);
void    md5_init(t_ssl *md5);
void    ft_md5(char *msg, t_ssl *md5);

/*
** md5_process.c
*/

void	endb2w(t_ssl *md5, unsigned char data[]);
void	endw2b(t_ssl *md5, unsigned char hash[]);
void	md5_process(t_ssl *md5, unsigned char data[]);

/*
** sha256.c
*/

void    ft_sha256(char *str, t_ssl *md5);

#endif