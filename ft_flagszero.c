/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagszero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:25:46 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:49:35 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbargsttwo15(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (a == 0 && b < 0 && !(is_in(ft_rettype(str), "sc")))
	{
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	return (ft_nbargsttwo2(str, container, &(*i)));
}

int		ft_nbargsttwob2b(const char *str, char **container, size_t **i)
{
	long	a;
	long	tmpa;

	a = ft_geta(str);
	tmpa = a > 0 ? a : -a;
	if (a == 0 && ft_getb(str) > ft_strlen(container[**i])
		- (container[**i][0] == '-' ? 1 : 0))
		return (ft_nbargsttwo4(str, container, &(*i)));
	if ((ft_getb(str) == 0 && container[**i][0] == '0')
		|| (ft_strlen(container[**i]) < tmpa))
		return (ft_nbargsttwo12(str, container, &(*i)));
	if (ft_getb(str) >= ft_strlen(container[**i][0] == '-'
		? container[**i] : container[**i] + 1))
		return (ft_nbargsttwo13(str, container, &(*i)));
	ft_nbargsttwo14(str, container, &(*i));
	return (ft_strlen(container[(**i)++]));
}

int		ft_nbargsttwo(const char *str, char **container, size_t **i)
{
	long	a;
	long	tmpa;

	a = ft_geta(str);
	tmpa = a > 0 ? a : -a;
	if (is_in(ft_rettype(str), "sc") && thereisnullb(str))
	{
		ft_freeargs((char *)str);
		(**i)++;
		return (0);
	}
	if ((a == 0 && ft_getb(str) < 0
		&& !(is_in(ft_rettype(str), "sc")))
		|| (a == 0 && (ft_getb(str) < ft_strlen(container[**i]))
			&& is_in(ft_rettype(str), "sc")))
		return (ft_nbargsttwo15(str, container, &(*i)));
	if ((ft_getb(str) == 0 && a == 0 && ft_rettype(str) == 's')
		|| (a == 0 && ft_rettype(str) == 'c')
			|| (ft_rettype(str) == 's' && !container[**i][0] && !ft_getb(str)))
		return (ft_nbargsttwo3(str, container, &(*i)));
	return (ft_nbargsttwob2b(str, container, &(*i)));
}

int		ft_nbargst(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i - 1] == '%')
				return (1);
			return (2);
		}
		i++;
	}
	return (0);
}

int		ft_flag5(const char *str, char **container, size_t **i)
{
	if (ft_nbargst(str) == 0)
		return (ft_retzero(str, container, &(*i)));
	if (ft_nbargst(str) == 1)
		return (ft_retun(str, container, &(*i)));
	if (ft_nbargst(str) == 2)
		return (ft_nbargsttwo(str, container, &(*i)));
	return (0);
}
