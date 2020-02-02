/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:40:06 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/01 19:42:31 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "ft_libftprintf/includes/ft_printf.h"
# include "ft_libftprintf/includes/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "ft_sha256.h"
# include "ft_md5.h"

typedef struct		s_flag
{
	int				p;
	int				q;
	int				r;
	int				s;
	int				f;
}					t_flag;

typedef void	(*t_hash_func)(char *, size_t);

typedef struct		s_algo
{
	char			*name;
	t_hash_func		func;
}					t_algo;

typedef struct		s_ssl
{
	char			*input;
	size_t			len;
	char			*file_name;
	t_flag			flags;
	t_algo			algo[2];
	int				i;
}					t_ssl;

/*
** main.c
*/

t_ssl				*ssl_init(void);
void				flags_init(t_ssl *ssl, int ac, char **av);

/*
** process.c
*/

void				file_check(t_ssl *ssl, char *file_name);
void				stdin_check(t_ssl *ssl, int print_input);
void				process_string(t_ssl *ssl, char *str, int *i);

/*
** aux.c
*/

int					command_check(t_ssl *ssl, char *command_name);
int					print_error(char *str, t_ssl *ssl);
int					read_stdin(t_ssl *ssl);
int					fgnl(t_ssl *ssl, char *file_name);

#endif
