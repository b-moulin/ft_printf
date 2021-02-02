/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagzero4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 08:59:58 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/02 10:32:37 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbargsttwo2(const char *str, char **container, size_t **i)
{
	long	b;

	b = ft_getb(str);
	if (container[**i][0] == '0' && b == 0 && is_in(ft_rettype(str), "dui"))
	{
		free ((char *)str);
		str = 0;
		(**i)++;
		return (0);
	}
	if ((b >= ft_strlen(container[**i]) || b == 0)
		&& is_in(ft_rettype(str), "dui"))
	{
		ft_putstr(container[**i]);
		free ((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	ft_putstr_len(container[**i], b);
	free ((char *)str);
	str = 0;
	(**i)++;
	return (b);
}

int		ft_nbargsttwo8(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (b == 0 && a > 0)
		ft_putspace(tmpa - ft_strlen(container[**i]));
	if (a > ft_strlen(container[**i] + 1) && b == 0)
		ft_putstr(container[**i]);
	else
		ft_putstr(container[**i] + 1);
	if (b == 0 && a < 0)
		ft_putspace(tmpa - ft_strlen(container[**i]));
	(**i)++;
	free((char *)str);
	str = 0;
	return (tmpa + (b >= a ? 1 : 0));
}

void	ft_nbargsttwo9(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (container[**i][0] == '-')
	{
		if (b >= a)
			write(1, "-", 1);
		ft_putzerob((tmpa - (tmpa - b))
			- ft_strlen(container[**i]) + 1);
	}
	else
	{
		tmpa = (tmpa - (tmpa - b)) - ft_strlen(container[**i]);
		if (tmpa < 0)
			return ;
		ft_putzerob(tmpa);
	}
}

int		ft_nbargsttwo10(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (is_in(ft_rettype(str), "sc"))
	{
		ft_putspace(tmpa);
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

int		ft_nbargsttwo11(const char *str, char **container, size_t **i)
{
	long	b;
	long	tmpa;

	b = ft_getb(str);
	tmpa = ft_geta(str) > 0 ? ft_geta(str) : -ft_geta(str);
	if (b >= tmpa)
		return (ft_nbargsttwo7(str, container, &(*i)));
	if (is_in(ft_rettype(str), "uid") && b == 0
		&& ft_geta(str) > ft_strlen(container[**i]))
	{
		ft_putspace(ft_geta(str) - ft_strlen(container[**i]));
		ft_putstr(container[(**i)++]);
		b = ft_geta(str);
		free((char *)str);
		str = 0;
		return (b);
	}
	if (tmpa > b - ft_strlen(container[**i]) + 1)
		ft_nbargsttwo9(str, container, &(*i));
	if (container[**i][0] == '-')
		return (ft_nbargsttwo8(str, container, &(*i)));
	else
	{
		if (b >= ft_geta(str) && b > ft_strlen(container[**i])
			&& container[**i][0] == '0')
			ft_putzerob(b - 1);
		if (b == 0 && tmpa > ft_strlen(container[**i]))
			return (ft_nbargsttwo10(str, container, &(*i)));
		ft_putstr(container[**i]);
	}
	if (b == 0)
		ft_putspace(tmpa - ft_strlen(container[**i]));
	(**i)++;
	free((char *)str);
	str = 0;
	return (tmpa);
}
