/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubledistrib.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 07:39:32 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/04 16:39:36 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sba2(const char *str, char **container, size_t **i)
{
	int		b;
	int		a;
	int		tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a < 0 ? -a : a;
	if (b > 0 && a < 0 && tmpa <= b && is_in(ft_rettype(str), "sc"))
		return (ft_sba2b(str, container, &(*i)));
	if (tmpa > b)
	{
		ft_putstr_len(container[**i], b);
		if (b < ft_strlen(container[**i]))
			ft_putspace(tmpa - b);
		else
			ft_putspace((tmpa - ft_strlen(container[**i])));
		ft_freeargs((char *)str);
		(**i)++;
		return (tmpa);
	}
	ft_putstr(container[**i]);
	ft_putspace(tmpa - ft_strlen(container[**i]));
	free((char *)str);
	str = 0;
	return (ft_strlen(container[(**i)++]) + 1);
}

int		ft_sba2b2(const char *str, char **container, size_t **i)
{
	int		b;
	int		a;
	int		tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a < 0 ? -a : a;
	if (b == 0)
	{
		ft_putspace(tmpa);
		free((char *)str);
		str = 0;
		return (tmpa);
	}
	ft_putstr_len(container[**i], b);
	free((char *)str);
	str = 0;
	if (ft_strlen(container[(**i)]) < b)
		b = ft_strlen(container[(**i)]);
	(**i)++;
	return (b);
}

int		ft_sba(const char *str, char **container, size_t **i)
{
	int		b;
	int		a;
	int		tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a < 0 ? -a : a;
	if (b < 0)
		b = -b;
	if (tmpa >= b || a < 0)
		return (ft_sba2(str, container, &(*i)));
	if ((b == 0) || (b > tmpa && tmpa <= ft_strlen(container[(**i)])))
		return (ft_sba2b2(str, container, &(*i)));
	ft_putspace(tmpa - ft_strlen(container[**i]));
	ft_putstr(container[**i]);
	free((char *)str);
	str = 0;
	a = tmpa - ft_strlen(container[**i]) + ft_strlen(container[(**i)++]);
	return (a);
}

int		ft_nomallocdflag3(const char *str, char *container, size_t **i)
{
	char	dest[ft_strlen(container) + 1];
	int		j;

	j = 0;
	while (container[j])
	{
		dest[j] = container[j];
		j++;
	}
	dest[j] = container[j];
	free(container);
	container = 0;
	return (ft_dflag3(str, dest, &(*i)));
}

int		ft_sab(const char *str, char **container, size_t **i)
{
	int		a;
	int		b;

	a = ft_geta(str);
	b = ft_getb(str);
	if (b < 0 && is_in(ft_rettype(str), "sc"))
		b = -b;
	if (b == 0)
	{
		(**i)++;
		free((char *)str);
		str = 0;
		return (ft_putspace(a));
	}
	if (a >= b)
		if (ft_strlen(container[**i]) > ft_getb(str))
		{
			return (ft_nomallocdflag3(str, ft_substr(container[**i],
				0, ft_getb(str), 0), &(*i)));
		}
	if (a >= b)
		return (ft_dflag3(str, ft_b(str, container, &(*i)), &(*i)));
	free((char *)str);
	str = 0;
	return (0);
}
