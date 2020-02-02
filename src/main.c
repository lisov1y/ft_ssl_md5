/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:50:37 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/01 19:40:15 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	flags_init(t_ssl *ssl, int ac, char **av)
{
	int i;

	i = 1;
	while (++i < ac)
	{
		if (ssl->flags.f)
			file_check(ssl, av[i]);
		else if (!ft_strcmp(av[i], "-p"))
			stdin_check(ssl, 1);
		else if (!ft_strcmp(av[i], "-q"))
			ssl->flags.q = 1;
		else if (!ft_strcmp(av[i], "-r"))
			ssl->flags.r = 1;
		else if (!ft_strcmp(av[i], "-s"))
		{
			if (av[i + 1])
				process_string(ssl, av[i + 1], &i);
			else
				print_error(NULL, ssl);
		}
		else
			file_check(ssl, av[i]);
	}
	if (!ssl->flags.f && !ssl->flags.s && !ssl->flags.p)
		stdin_check(ssl, 0);
}

t_ssl	*ssl_init(void)
{
	t_ssl	*ssl;

	ssl = (t_ssl *)malloc(sizeof(t_ssl));
	ssl->algo[0].name = "md5";
	ssl->algo[0].func = &ft_md5;
	ssl->algo[1].name = "sha256";
	ssl->algo[1].func = &ft_sha256;
	ssl->i = -1;
	ssl->flags.p = 0;
	ssl->flags.q = 0;
	ssl->flags.r = 0;
	ssl->flags.s = 0;
	ssl->flags.f = 0;
	ssl->len = 0;
	return (ssl);
}

int		main(int argc, char **argv)
{
	t_ssl	*ssl;

	ssl = ssl_init();
	if (argc < 2)
		return (print_error(NULL, ssl));
	if (command_check(ssl, argv[1]))
	{
		if (argc > 2)
			flags_init(ssl, argc, argv);
		else
			stdin_check(ssl, 0);
	}
	return (0);
}
