/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:59:12 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/19 13:22:19 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

# define LC_L 1
# define LC_H 2
# define LC_LL 4
# define LC_HH 8
# define UC_L 16

# define PLUS 1
# define MINUS 2
# define SPACE 4
# define ZERO 8
# define HASH 16

# define ABS(N) ((N < 0) ? (-N) : (N))

typedef struct		s_printf
{
	int				prec;
	int				rprec;
	int				width;
	unsigned int	len : 5;
	unsigned int	flag : 5;
	char			spec;
}					t_printf;

/*
** ft_printf.c
*/

int					ft_printf(char *format, ...);

/*
** ft_parser.c
*/

void				ft_parse(va_list *args, char *format, int *i, int *len);
void				ft_extract(char *format, int *i, t_printf *flags);
char				*ft_dispatcher(va_list *args, t_printf *flags, char *res);

/*
**ft_checker.c
*/

int					ft_cflag(char c);
int					ft_cwidth(char c);
int					ft_cprec(char c);
int					ft_clen(char *s, int i);
int					ft_cspec(char c);

/*
** ft_fwpl_set.c
*/

void				ft_sflag(char *format, int *i, t_printf *flags);
void				ft_swidth(char *format, int *i, t_printf *flags);
void				ft_sprec(char *format, int *i, t_printf *flags);
void				ft_slen(char *format, int *i, t_printf *flags);
void				ft_sspec(char *format, int *i, t_printf *flags);

/*
** dioux.c
*/

char				*di_spec(va_list *args, t_printf *flags, char *res);
char				*o_spec(va_list *args, t_printf *flags, char *res);
char				*u_spec(va_list *args, t_printf *flags, char *res);
char				*xx_spec(va_list *args, t_printf *flags, char *res);

/*
** fscpp.c
*/

char				*f_spec(va_list *args, t_printf *flags, char *res);
char				*s_spec(va_list *args, t_printf *flags, char *res);
char				*c_spec(va_list *args, t_printf *flags, char *res);
char				*p_spec(va_list *args, t_printf *flags, char *res);
char				*pr_spec(t_printf *flags, char *res);

/*
** ft_lenmodifs.c
*/

int64_t				ft_dilen(va_list *args, t_printf *flags);
uint64_t			ft_ouxxlen(va_list *args, t_printf *flags);
double				ft_flen(va_list *args, t_printf *flags);

/*
** ft_handler.c
*/

char				*ft_dihan(t_printf *flags, char *res, int64_t n);
char				*ft_ohan(t_printf *flags, char *res, uint64_t n);
char				*ft_xxhan(t_printf *flags, char *res, uint64_t n);
char				*ft_fhan(t_printf *flags, char *res, double n);
char				*ft_fixfloat(t_printf *flags, char *res, double n);

/*
** ft_fixflags.c
*/

char				*ft_fixwidth(t_printf *flags, char *res);
void				ft_fixwidthi(t_printf *flags, int i);
char				*ft_fixprec(int len, char *res);
char				*ft_fixps(t_printf *flags, char *res, int64_t n);
char				*ft_fixhash(t_printf *flags, char *res, uint64_t n);

/*
** ft_itoa_base.c
*/

int					ft_numlen_base(uintmax_t nb, int base);
int					ft_valcheck(uint64_t n, int uc);
char				*ft_itoa_base(uint64_t n, int base, int uc);

/*
** ft_init.c
*/

t_printf			*ft_init(void);

/*
** ft_ftoa.c
*/

void				ft_roundup(double f, long fpart, char *s, int i);
int					ft_flolen(double f);
char				*ft_cdtoa(double f, int i, int prec);
char				*ft_cftoa(double f, int prec, int of);
char				*ft_ftoa(double f, int prec, int len, t_printf *flags);

/*
** ft_utils.c
*/

char				*ft_apptstr(char *s, int len, char c, int part);
char				*ft_strndup(const char *s1, int len);
int					ft_strlen_int(char *s);
char				*ft_itoa_vl(int64_t n);

#endif
