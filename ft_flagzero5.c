/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagzero5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:02:03 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/28 09:02:15 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbargsttwo12(const char *str, char **container, size_t **i)
{
	long	b;
	long	tmpa;
	long	negret;

	b = ft_getb(str);
	tmpa = ft_geta(str) > 0 ? ft_geta(str) : -ft_geta(str);
	if (b == 0 && container[**i][0] == '0')
	{
		ft_putspace(tmpa);
		(**i)++;
		return (tmpa);
	}
	if (ft_geta(str) < 0)
		return (ft_nbargsttwo5(str, container, &(*i)));
	if (ft_geta(str) > b)
		if (b != 0)
			negret = ft_nbargsttwo6(str, container, &(*i));
	if (ft_geta(str) > ft_strlen(container[**i]))
		return (ft_nbargsttwo11(str, container, &(*i)));
	if (container[**i][0] == '-')
		ft_putstr(container[**i] + 1);
	else
		ft_putstr(container[**i]);
	return (tmpa);
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
		return (b + 1);
	}
	if (b > ft_strlen(container[**i]))
	{
		ft_putzerob(b - ft_strlen(container[**i]));
		ft_putstr(container[(**i)++]);
		return (b);
	}
	ft_putstr(container[**i]);
	return (ft_strlen(container[(**i)++]));
}
