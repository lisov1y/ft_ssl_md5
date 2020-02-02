/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:18:51 by mstupnik          #+#    #+#             */
/*   Updated: 2019/11/18 16:20:35 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_apptstr(char *s, int len, char c, int part)
{
	char	*str;
	char	*res;

	if (!s || !len)
		return (s);
	if (!(str = ft_strnew(len)))
		return (s);
	while (len)
		str[--len] = c;
	if (part)
		res = ft_strjoin(str, s);
	else
		res = ft_strjoin(s, str);
	free(s);
	free(str);
	return (res);
}

char	*ft_strndup(const char *s1, int len)
{
	char	*s2;
	size_t	i;

	if (!(s2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && len--)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int		ft_strlen_int(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_numcount_vl(int64_t n)
{
	int count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_vl(int64_t n)
{
	char	*str;
	int		a;
	int		nums;
	int		i;

	a = 0;
	if (n < 0)
		a = 1;
	nums = ft_numcount_vl(n);
	str = ft_strnew(nums + a);
	if (str == NULL)
		return (NULL);
	if (a)
		str[0] = '-';
	i = nums + a - 1;
	while (i >= a)
	{
		if (a)
			str[i--] = (n % 10 * -1) + '0';
		else
			str[i--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
