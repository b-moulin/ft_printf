/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:42:43 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/04 16:42:55 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flagdouble8(const char *str, char **container, size_t **i)
{
	long long			tmpa;
	long long			calc;

	tmpa = ft_geta(str) < 0 ? -ft_geta(str) : ft_geta(str);
	if (ft_geta(str) < 0)
		return (ft_flagdouble6(str, container, &(*i)));
	ft_putspace(tmpa - ft_strlen(container[**i]) - 1);
	write(1, "-", 1);
	ft_putzerob(ft_getb(str) - ft_strlen(container[**i]) + 1);
	ft_putstr(container[(**i)++] + 1);
	free((char *)str);
	str = 0;
	return (tmpa);
}

int		ft_flagdouble7b(const char *str, char **container, size_t **i)
{
	long long int		tmpa;

	tmpa = ft_geta(str) < 0 ? -ft_geta(str) : ft_geta(str);
	if (!(tmpa > ft_strlen(container[**i])))
	{
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	ft_putspace(tmpa - ft_strlen(container[**i]));
	ft_putstr(container[(**i)++]);
	free((char *)str);
	str = 0;
	return (tmpa);
}

int		ft_flagdouble7(const char *str, char **container, size_t **i)
{
	long long int		tmpa;

	tmpa = ft_geta(str) < 0 ? -ft_geta(str) : ft_geta(str);
	if (ft_strlen(container[**i]) < ft_getb(str))
	{
		if (ft_geta(str) < 0)
		{
			ft_flagdouble3(str, container, &(*i));
			(**i)++;
			free((char *)str);
			str = 0;
			return (tmpa);
		}
		return (ft_flagdouble4(str, container, &(*i)));
	}
	if ((ft_geta(str) < 0) || (container[**i][0] == '-'
		&& ft_getb(str) > ft_strlen(container[**i]) - 1))
		return (ft_flagdouble8(str, container, &(*i)));
	return (ft_flagdouble7b(str, container, &(*i)));
}

int		ft_flagdouble2b2(const char *str, char **container, size_t **i)
{
	long long int		a;
	long long int		b;
	long long int		tmpa;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	b = ft_getb(str);
	if (((a <= 0 && b <= 0) || ft_strlen(container[(**i)]) > b))
	{
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	if (b >= a)
		return (ft_putzero(str, container, &(*i)));
	return (0);
}

int		ft_flagdouble(const char *str, char **container, size_t **i)
{
	long long int		a;
	long long int		b;
	long long int		tmpa;
	char				type;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	b = ft_getb(str);
	if (is_in(ft_rettype(str), "dui") && b == 0 && container[**i][0] == '0')
	{
		free((char *)str);
		str = 0;
		(**i)++;
		return (ft_putspace(tmpa));
	}
	if (ft_rettype(str) == 'c' || ft_rettype(str) == 's')
		if (a == 0 || a >= (b > 0 ? b : -b) || (b > 0 ? b : -b) > a)
			return (ft_flagdouble2(str, container, &(*i)));
	if (str[ft_strlen((char *)str) - 2] == '.')
		return (ft_ptnotset(str, container, &(*i)));
	if (tmpa > b && b > 0)
		return (ft_flagdouble7(str, container, &(*i)));
	return (ft_flagdouble2b2(str, container, &(*i)));
}
