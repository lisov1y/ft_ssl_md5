/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:37:28 by mstupnik          #+#    #+#             */
/*   Updated: 2020/01/28 15:40:35 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

/*
** -p, echo STDIN to STDOUT and append the checksum to STDOUT
** -q, quiet mode
** -r, reverse the format of the output.
** -s, print the sum of the given string
*/

void    flag_check(t_ssl *md5, int ac, char **av)
{
    md5->p = 0;
    md5->q = 0;
    md5->r = 0;
    md5->s = 0;
    md5->i = 2;
    while (md5->i < ac)
    {
        if (ft_strcmp(av[md5->i], "-p") == 0)
            md5->p = 1;
        else if (ft_strcmp(av[md5->i], "-q") == 0)
            md5->q = 1;
        else if (ft_strcmp(av[md5->i], "-r") == 0)
            md5->r = 1;
        else if (ft_strcmp(av[md5->i], "-s") == 0)
        {
            md5->i++;
            md5->s++;
        }
        else
            break ;
        md5->i++;
    }
    md5->file = md5->i - ac;
}

void    check(t_ssl *md5, int ac, char **av)
{
    flag_check(md5, ac, av);
    if (md5->p || (!md5->file && !md5->s))
    {
            fgnl(&md5->input, 0);
            if (md5->p)
                ft_printf("%s", md5->input);
            if (ft_strcmp(av[1], "md5") == 0)
                ft_md5(md5->input, md5);
            else
                ft_sha256(md5->input, md5);
            ft_putchar('\n');
            free(md5->input);
    }
    md5->pars = 2;
    while (md5->pars < ac)
        if (print_s(md5, ac, av) == -1)
            break ;
    while (md5->pars < ac)
        frot(md5, av);
}

void    frot(t_ssl *md5, char **av)
{
    if (file_check(md5, av) == -1)
        exit(-1);
    fgnl(&md5->input, md5->fd);
    if (!md5->r)
        fnorot(md5, av);
    else
    {
        if (ft_strcmp(av[1], "sha256") == 0)
            ft_sha256(md5->input, md5);
        else
            ft_md5(md5->input, md5);
        if (!md5->q)
            ft_printf(" %s\n", av[md5->pars]);
        else
            ft_putchar('\n');
    }
    free(md5->input);
    close(md5->fd);
    md5->pars++;
}

void    fnorot(t_ssl *md5, char **av)
{
    if (!md5->q)
    {
        if (ft_strcmp(av[1], "sha256") == 0)
            ft_printf("SHA256 (");
        else
            ft_printf("MD5 (");
        ft_printf("%s) = ", av[md5->pars]);
    }
    if (ft_strcmp(av[1], "sha256") == 0)
        ft_sha256(md5->input, md5);
    else
        ft_md5(md5->input, md5);
    ft_putchar('\n');
}