/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubledistrib.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 07:39:32 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/02 15:17:55 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_a(const char *str, char **container, size_t **i)
{
	size_t	j;

	j = 0;
	if (ft_strlen(container[**i]) == 0 ||
		ft_strlen(container[**i]) <= ft_geta(str))
		return (container[**i]);
	else if (ft_strlen(container[**i]) > ft_geta(str))
		return (ft_substr(container[**i], 0, ft_geta(str), 0));
	return (0);
}

int		ft_putzerob(long long nb)
{
	if (nb < 0)
		return (0);
	while (nb-- > 0)
		write(1, "0", 1);
	return (nb);
}

int		ft_sba2(const char *str, char **container, size_t **i)
{
	int		b;
	int		a;
	int		tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a < 0 ? -a : a;
	if (b > 0 && a < 0 && tmpa < b && is_in(ft_rettype(str), "sc"))
	{
		ft_putstr_len(container[**i], b);
		if (b < ft_strlen(container[**i]))
			ft_putspace(tmpa - b);
		else
			ft_putspace((tmpa - ft_strlen(container[**i])));
		free((char *)str);
		str = 0;
		if (b > ft_strlen(container[**i]))
			b = tmpa;
		(**i)++;
		return (b);
	}
	if (tmpa > b)
	{
		ft_putstr_len(container[**i], b);
		if (b < ft_strlen(container[**i]))
			ft_putspace(tmpa - b);
		else
			ft_putspace((tmpa - ft_strlen(container[**i])));
		free((char *)str);
		str = 0;
		(**i)++;
		return (tmpa);
	}
	ft_putstr(container[**i]);
	ft_putspace(tmpa - ft_strlen(container[**i]));
	free((char *)str);
	str = 0;
	return (ft_strlen(container[(**i)++]) + 1);
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
	if (tmpa > b || a < 0)
		return (ft_sba2(str, container, &(*i)));
	if (b == 0)
	{
		ft_putspace(tmpa);
		free((char *)str);
		str = 0;
		return (tmpa);
	}
	if (b > tmpa && tmpa <= ft_strlen(container[(**i)]))
	{
		ft_putstr(container[(**i)]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	ft_putspace(tmpa - ft_strlen(container[**i]));
	ft_putstr(container[**i]);
	free((char *)str);
	str = 0;
	return (ft_strlen(container[(**i)++]) + 1);
}

int		ft_nomallocdflag3(const char *str, char *container, size_t **i)
{
	char	dest[ft_strlen(container)];
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
	char	*unmalloc;

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
	{
		if (ft_strlen(container[**i]) > ft_getb(str))
		{
			unmalloc = ft_substr(container[**i], 0, ft_getb(str), 0);
			return (ft_nomallocdflag3(str, unmalloc, &(*i)));
		}
		return (ft_dflag3(str, ft_b(str, container, &(*i)), &(*i)));
	}
	free((char *)str);
	str = 0;
	return (0);
}
