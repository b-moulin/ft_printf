/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagzero2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:34:13 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:49:59 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (ft_rettype(str) == 'c' && container[**i][0] == 0)
		{
			write(1, "\0", 1);
			free((char *)str);
			str = 0;
			(**i)++;
			return (1);
		}
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	if (container[**i][0] == '-')
		write(1, "-", 1);
	return (ft_retzero2b2(str, container, &(*i)));
}

int		ft_retun2(const char *str, char **container, size_t **i)
{
	int		b;

	b = ft_getb(str);
	if (b == 0 && is_in(ft_rettype(str), "sc"))
	{
		(**i)++;
		free((char *)str);
		str = 0;
		return (0);
	}
	ft_putstr(container[**i]);
	free((char *)str);
	str = 0;
	return (ft_strlen(container[(**i)++]));
}

int		ft_retun3(const char *str, char **container, size_t **i)
{
	if (container[**i][0] == '-')
		ft_putstr(container[(**i)++] + 1);
	else
		ft_putstr(container[(**i)++]);
	free((char *)str);
	str = 0;
	return (ft_getb(str));
}

int		ft_retunb2(const char *str, char **container, size_t **i)
{
	int		b;
	size_t	j;
	int		size;

	j = 0;
	size = ft_strlen(container[**i]);
	b = ft_getb(str);
	if (size >= b)
		return (ft_retun2(str, container, &(*i)));
	if (container[**i][0] == '-')
	{
		b++;
		write(1, "-", 1);
	}
	while (j < (size_t)(b - ft_strlen(container[**i])))
	{
		write(1, "0", 1);
		j++;
	}
	return (ft_retun3(str, container, &(*i)));
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
	{
		free((char *)str);
		str = 0;
		(**i)++;
		return (0);
	}
	return (ft_retunb2(str, container, &(*i)));
}
