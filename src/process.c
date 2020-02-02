/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:37:28 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/02 10:25:26 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	file_check(t_ssl *ssl, char *file_name)
{
	if (fgnl(ssl, file_name))
	{
		if (!ssl->flags.r && !ssl->flags.q)
			ft_printf("%s (%s) = ",
				ft_strtoupper(ssl->algo[ssl->i].name), file_name);
		ssl->algo[ssl->i].func(ssl->input, ssl->len);
		if (ssl->flags.r && !ssl->flags.q)
			ft_printf(" %s", file_name);
		ft_printf("\n");
		free(ssl->input);
	}
	ssl->flags.f = 1;
}

void	stdin_check(t_ssl *ssl, int print_input)
{
	if (read_stdin(ssl))
	{
		if (print_input)
		{
			ft_printf("%s", ssl->input);
			ssl->flags.p = 1;
		}
		ssl->algo[ssl->i].func(ssl->input, ssl->len);
		ft_printf("\n");
		free(ssl->input);
	}
}

void	process_string(t_ssl *ssl, char *str, int *i)
{
	if (!ssl->flags.r && !ssl->flags.q)
		ft_printf("%s (\"%s\") = ",
			ft_strtoupper(ssl->algo[ssl->i].name), str);
	ssl->algo[ssl->i].func(str, ft_strlen(str));
	if (ssl->flags.r && !ssl->flags.q)
		ft_printf(" \"%s\"", str);
	ft_printf("\n");
	ssl->flags.s = 1;
	(*i)++;
}
