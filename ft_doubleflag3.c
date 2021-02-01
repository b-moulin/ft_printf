/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleflag3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:24:05 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/01 15:26:11 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptnotset(const char *str, char **container, size_t **i)
{
	long long	a;
	long long	tmpa;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	if (tmpa <= ft_strlen(container[**i]))
	{
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	if (a < 0)
	{
		ft_putstr(container[**i]);
		ft_putspace(tmpa - ft_strlen(container[(**i)++]));
		free((char *)str);
		str = 0;
		return (tmpa);
	}
	ft_putspace(tmpa - ft_strlen(container[**i]));
	ft_putstr(container[(**i)++]);
	free((char *)str);
	str = 0;
	return (tmpa);
}

int		ft_flagdouble2(const char *str, char **container, size_t **i)
{
	long long int		a;
	long long int		b;

	a = ft_geta(str);
	b = ft_getb(str);
	if (a < 0 && b < 0 && is_in(ft_rettype(str), "sc")
		&& -b <= ft_strlen(container[**i]))
	{
		ft_putstr(container[**i]);
		return (ft_strlen(container[(**i)++]));
	}
	if (b < 0)
		b = -b;
	if (a == 0)
		return (ft_flag3(str, container, &(*i)));
	if (a >= b)
		return (ft_sab(str, container, &(*i)));
	if (b > a)
		return (ft_sba(str, container, &(*i)));
	return (0);
}

void	ft_flagdouble3(const char *str, char **container, size_t **i)
{
	long long int		a;
	long long int		b;
	long long int		tmpa;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	b = ft_getb(str);
	if (container[**i][0] == '-')
	{
		write(1, "-", 1);
		ft_putzerob(1 + b - ft_strlen(container[**i]));
		ft_putstr(container[**i] + 1);
		ft_putspace(tmpa - b - 1);
	}
	else
	{
		ft_putzerob(b - ft_strlen(container[**i]));
		ft_putstr(container[**i]);
		ft_putspace(tmpa - b);
	}
}

int		ft_flagdouble4(const char *str, char **container, size_t **i)
{
	long long int		a;
	long long int		b;
	long long int		tmpa;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	b = ft_getb(str);
	if (container[**i][0] == '-')
	{
		write(1, "-", 1);
		ft_putzerob(b - ft_strlen(container[**i]) + 1);
		ft_putstr(container[(**i)++] + 1);
		free((char *)str);
		str = 0;
		return (a);
	}
	ft_putspace(a - b);
	ft_putzerob(b - ft_strlen(container[**i]));
	ft_putstr(container[(**i)++]);
	free((char *)str);
	str = 0;
	return (a);
}

int		ft_flagdouble5(const char *str, char **container, size_t **i)
{
	long long int		a;
	long long int		b;
	long long int		tmpa;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	b = ft_getb(str);
	write(1, "-", 1);
	ft_putzerob(b - ft_strlen(container[**i]) + 1);
	ft_putstr(container[**i] + 1);
	if ((tmpa - ft_strlen(container[**i]) - 1) > 0)
	{
		ft_putspace(tmpa - ft_strlen(container[(**i)++]) - 1);
		free((char *)str);
		str = 0;
		return (tmpa);
	}
	free((char *)str);
	str = 0;
	return (tmpa + 1 - (b - ft_strlen(container[(**i)++]) + 1));
}
