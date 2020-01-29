/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:50:37 by mstupnik          #+#    #+#             */
/*   Updated: 2020/01/22 12:48:49 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int     main(int ac, char **av)
{
    t_ssl   md5;

    if (ac == 1)
    {
        ft_printf("usage: ft_ssl command [command opts] [command args]\n");
        exit(-1);
    }
    if (ft_strcmp(av[1], "md5") == 0)
        check(&md5, ac, av);
    else if (ft_strcmp(av[1], "sha256") == 0)
        check(&md5, ac, av);
    else
        ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\nStandard \
        commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher \
        commands:\n", av[1]);
    return (0);
}