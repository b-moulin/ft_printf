/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubledistrib.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 07:39:32 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/28 08:55:04 by bmoulin          ###   ########lyon.fr   */
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
		return (ft_substr(container[**i], 0, ft_geta(str)));
	return (0);
}

int		ft_putzerob(unsigned long nb)
{
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
	if (tmpa > b)
	{
		ft_putstr_len(container[**i], b);
		if (b < ft_strlen(container[**i]))
			ft_putspace(tmpa - b);
		else
			ft_putspace((tmpa - ft_strlen(container[(**i)++])));
		return (tmpa);
	}
	ft_putstr(container[**i]);
	ft_putspace(tmpa - ft_strlen(container[**i]));
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
		return (tmpa);
	}
	if (b > tmpa && tmpa <= ft_strlen(container[(**i)]))
	{
		ft_putstr(container[(**i)]);
		return (ft_strlen(container[(**i)++]));
	}
	ft_putspace(tmpa - ft_strlen(container[**i]));
	ft_putstr(container[**i]);
	return (ft_strlen(container[(**i)++]) + 1);
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
		return (ft_putspace(a));
	}
	if (a >= b)
		return (ft_dflag3(str, ft_b(str, container, &(*i)), &(*i)));
	return (0);
}
