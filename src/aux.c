/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:30:54 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/01 19:42:10 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		command_check(t_ssl *ssl, char *undef_com)
{
	int i;

	i = -1;
	while (++i < 2)
		if (ft_strcmp(undef_com, ssl->algo[i].name) == 0)
			ssl->i = i;
	if (ssl->i == -1)
		return (print_error(undef_com, ssl));
	return (1);
}

int		print_error(char *str, t_ssl *ssl)
{
	int i;

	if (str == NULL)
		ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", str);
		ft_putstr("\nStandard commands:\n");
		ft_putstr("\nMessage Digest commands:\n");
		i = -1;
		while (++i < 2)
			ft_printf("%s\t", ssl->algo[i].name);
		ft_putstr("\n\nCipher commands:\n");
	}
	return (0);
}

int		read_stdin(t_ssl *ssl)
{
	char	buf[2];
	char	*tmp;
	int		fd;

	fd = 0;
	ssl->len = 0;
	ft_memset(buf, 0, 2);
	ssl->input = ft_strdup("");
	while (read(fd, buf, 1) > 0)
	{
		tmp = ssl->input;
		ssl->input = ft_strjoin(ssl->input, buf);
		free(tmp);
	}
	ssl->len = ft_strlen(ssl->input);
	return (1);
}

int		fgnl(t_ssl *ssl, char *file_name)
{
	int		ret;
	int		fd;
	char	c;

	ssl->len = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_printf("ft_ssl: %s: %s: No such file or directory\n",
			ssl->algo[ssl->i].name, file_name);
		return (0);
	}
	while ((ret = read(fd, &c, 1)) > 0)
		ssl->len++;
	if (ret < 0)
	{
		ft_printf("%s: %s: Is a directory\n",
			ssl->algo[ssl->i].name, file_name);
		return (0);
	}
	ssl->input = (char*)malloc(sizeof(char) * (ssl->len));
	close(fd);
	fd = open(file_name, O_RDONLY);
	read(fd, ssl->input, ssl->len);
	close(fd);
	return (1);
}
