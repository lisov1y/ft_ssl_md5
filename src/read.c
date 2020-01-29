/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 12:30:54 by mstupnik          #+#    #+#             */
/*   Updated: 2020/01/28 15:40:59 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void    fgnl(char **p, int fd)
{
    char    c[2];
    int     v;
    char    *str;
    char    *tmp;

    c[1] = 0;
    v = 42;
    str = ft_strdup("");
    while (v > 0)
    {
        v = read(fd, c, 1);
        if (v == 0)
            break ;
        tmp = ft_strdup(str);
        str = ft_strjoin(str, c);
        free(tmp);
    }
    p[0] = ft_strdup(str);
}

int     print_s(t_ssl *md5, int ac, char **av)
{
        if (ft_strcmp(av[md5->pars], "-p") == 0)
            md5->p = 1;
        else if (ft_strcmp(av[md5->pars], "-q") == 0)
            md5->q = 1;
        else if (ft_strcmp(av[md5->pars], "-r") == 0)
            md5->r = 1;
        else if (ft_strcmp(av[md5->pars], "-s") == 0)
        {
            md5->pars++;
            if (md5->pars < ac)
            {
                if (!md5->r)
                    norot(md5, av);
                else
                    rots(md5, av);
            }
        }
        else
            return (-1);
        md5->pars++;
        return(0);
}

void    rots(t_ssl *md5, char **av)
{
    if (ft_strcmp(av[1], "sha256") == 0)
        ft_sha256(av[md5->pars], md5);
    else
    {
        ft_printf("MD5 (\"%s\") = ", av[md5->pars]);
        ft_md5(av[md5->pars], md5);
    }
    if (!md5->q)
        ft_printf(" \"%s\"\n", av[md5->pars]);
    else
        ft_printf("\n");
}

void    norot(t_ssl *md5, char **av)
{
    if (!md5->q)
    {
        if (ft_strcmp(av[1], "sha256") == 0)
            ft_printf("SHA256 (\"");
        else
            ft_printf("MD5 (\"");
		ft_putstr(av[md5->pars]);
		ft_printf("\") = ");
    }
    if (ft_strcmp(av[1], "sha256") == 0)
        ft_sha256(av[md5->pars], md5);
    else
        ft_md5(av[md5->pars], md5);
    ft_printf("\n");
}

int     file_check(t_ssl *md5, char **av)
{
    if ((md5->fd = open(av[md5->pars], O_RDWR)) < 0)
    {
        if (ft_strcmp(av[1], "sha256") == 0)
            ft_printf("ft_ssl: sha256: ");
        else
            ft_printf("ft_ssl: md5: ");
        ft_putstr(av[md5->pars]);
        ft_printf(": No such file or directory\n");
        md5->pars++;
        return (-1);
    }
    return (0);
}