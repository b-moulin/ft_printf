/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagzero2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:34:13 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/28 14:23:00 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_retzero2(const char *str, char **container, size_t **i)
{
	int		a;
	int		tmpa;

	a = ft_getprcta(str);
	tmpa = a > 0 ? a : -a;
	if (container[**i][0] == '-')
		ft_putstr(container[**i] + 1);
	else if (a > 0)
		ft_putstr(container[(**i)]);
	(**i)++;
	free((char *)str);
	str = 0;
	return (tmpa);
}

int		ft_retzero(const char *str, char **container, size_t **i)
{
	int		a;
	int		tmpa;
	size_t	j;

	a = ft_getprcta(str);
	tmpa = a > 0 ? a : -a;
	j = 0;
	if (ft_strlen(container[**i]) >= tmpa)
	{
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	if (container[**i][0] == '-')
		write(1, "-", 1);
	if (a < 0)
		ft_putstr(container[(**i)]);
	while (j < (tmpa - ft_strlen(container[(**i)])))
	{
		if (a < 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		j++;
	}
	return (ft_retzero2(str, container, &(*i)));
}

int		ft_retun2(const char *str, char **container, size_t **i)
{
	int		b;

	b = ft_getb(str);
	if (b == 0 && is_in(ft_rettype(str), "sc"))
	{
		(**i)++;
		return (0);
	}
	ft_putstr(container[**i]);
	return (ft_strlen(container[(**i)++]));
}

int		ft_retun3(const char *str, char **container, size_t **i)
{
	if (container[**i][0] == '-')
		ft_putstr(container[(**i)++] + 1);
	else
		ft_putstr(container[(**i)++]);
	return (ft_getb(str));
}

int		ft_retun(const char *str, char **container, size_t **i)
{
	int		b;
	size_t	j;
	int		size;

	j = 0;
	size = ft_strlen(container[**i]);
	b = ft_getb(str);
	if (container[**i][0] == '-')
		size--;
	if (b == 0 && container[**i][0] == '0')
		return (0);
	if (size >= b)
		return (ft_retun2(str, container, &(*i)));
	if (container[**i][0] == '-')
	{
		b++;
		write(1, "-", 1);
	}
	while (j < b - ft_strlen(container[**i]))
	{
		write(1, "0", 1);
		j++;
	}
	return (ft_retun3(str, container, &(*i)));
}
