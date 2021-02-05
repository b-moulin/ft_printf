/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagzero5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:02:03 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:55:52 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbargsttwo12b2(const char *str, size_t **i)
{
	long	tmpa;

	tmpa = ft_geta(str) > 0 ? ft_geta(str) : -ft_geta(str);
	if (is_in(ft_rettype(str), "xX") && tmpa >= 1 && ft_geta(str) < 0)
	{
		if (ft_geta(str) > 0)
			write(1, "0", 1);
		if (tmpa > 1 || ft_geta(str) < 0)
			ft_putspace(tmpa - 1 + (ft_geta(str) < 0 ? 1 : 0));
		(**i)++;
		ft_freeargs((char *)str);
		return (tmpa);
	}
	if (ft_geta(str) >= 0)
	{
		ft_putspace(tmpa);
		(**i)++;
		ft_freeargs((char *)str);
		return (tmpa);
	}
	ft_putspace(tmpa);
	(**i)++;
	ft_freeargs((char *)str);
	return (tmpa);
}

int		ft_nbargsttwo12b2b(const char *str, char **container, size_t **i)
{
	long	b;
	long	tmpa;
	long	negret;

	b = ft_getb(str);
	tmpa = ft_geta(str) > 0 ? ft_geta(str) : -ft_geta(str);
	if (ft_geta(str) > b)
		if (b != 0)
			negret = ft_nbargsttwo6(str, container, &(*i));
	if (ft_geta(str) > ft_strlen(container[**i]))
		return (ft_nbargsttwo11(str, container, &(*i)));
	if (container[**i][0] == '-')
		ft_putstr(container[**i] + 1);
	else
		ft_putstr(container[**i]);
	if (tmpa == 0 && is_in(ft_rettype(str), "uidxX"))
		tmpa = 1;
	free((char *)str);
	str = 0;
	(**i)++;
	return (tmpa);
}

int		ft_nbargsttwo12(const char *str, char **container, size_t **i)
{
	long	b;
	long	tmpa;

	b = ft_getb(str);
	tmpa = ft_geta(str) > 0 ? ft_geta(str) : -ft_geta(str);
	if (b == 0 && container[**i][0] == '0' && !is_in(ft_rettype(str), "scp"))
		return (ft_nbargsttwo12b2(str, &(*i)));
	if (ft_geta(str) < 0)
		return (ft_nbargsttwo5(str, container, &(*i)));
	if (ft_geta(str) > 0 && b < 0
		&& is_in(ft_rettype(str), "uid") && -b > ft_strlen(container[**i]))
	{
		ft_putstr(container[**i]);
		ft_putspace(-b - ft_strlen(container[(**i)++]));
		return (-b);
	}
	return (ft_nbargsttwo12b2b(str, container, &(*i)));
}

int		ft_nbargsttwo13(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (container[**i][0] == '-')
	{
		write(1, "-", 1);
		ft_putzerob(b - ft_strlen(container[**i] + 1));
		ft_putstr(container[(**i)++] + 1);
		ft_freeargs((char *)str);
		return (b + 1);
	}
	if (b > ft_strlen(container[**i]))
	{
		ft_putzerob(b - ft_strlen(container[**i]));
		ft_putstr(container[(**i)++]);
		ft_freeargs((char *)str);
		return (b);
	}
	ft_putstr(container[**i]);
	ft_freeargs((char *)str);
	return (ft_strlen(container[(**i)++]));
}
