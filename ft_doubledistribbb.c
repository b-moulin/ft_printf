/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubledistribbb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:43:56 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/04 17:10:05 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptnotset2b(const char *str, char **container, size_t **i)
{
	long long	a;
	long long	tmpa;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	if (tmpa <= ft_strlen(container[**i]))
	{
		if (is_in(ft_rettype(str), "xX") && container[**i][0] == '0')
			write(1, " ", 1);
		else
			ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	ft_putstr(container[**i]);
	ft_putspace(tmpa - ft_strlen(container[(**i)++]));
	free((char *)str);
	str = 0;
	return (tmpa);
}

int		ft_cutflag(const char *str, char **container, size_t **i)
{
	write(1, "flaglist", 8);
	(**i)++;
	return (0);
}

int		ft_flagzero(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '0' && str[i - 1] &&
			(str[i - 1] == '%' || str[i - 1] == '.'))
			return (1);
		i++;
	}
	return (0);
}

int		ft_getafterp(const char *str)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	start = i + 1;
	while (str[++i] >= '0' && str[i] <= '9')
		j++;
	i = ft_atoi(ft_substr(str, start, j, 0));
	return (i);
}

int		ft_flagx(const char *str, char **container, size_t **i, int j)
{
	if (container[**i][0] == '-')
	{
		write(1, "-", 1);
		while (j++ < ft_getafterp(str) - ft_strlen(container[**i] + 1))
			write(1, "0", 1);
		ft_putstr(container[(**i)++] + 1);
		return (ft_getafterp(str) + 1);
	}
	while (j++ < ft_getafterp(str) - ft_strlen(container[**i]))
		write(1, "0", 1);
	ft_putstr(container[(**i)++]);
	return (ft_getafterp(str));
}
