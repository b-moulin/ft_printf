/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubledistribb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:36:35 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/04 16:42:58 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_freearg(char *str)
{
	free(str);
	str = 0;
}

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

int		ft_sba2b(const char *str, char **container, size_t **i)
{
	int		b;
	int		a;
	int		tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a < 0 ? -a : a;
	ft_putstr_len(container[**i], b);
	if (b < ft_strlen(container[**i]))
		ft_putspace(tmpa - b);
	else
		ft_putspace((tmpa - ft_strlen(container[**i])));
	free((char *)str);
	str = 0;
	if (b > ft_strlen(container[**i]))
		b = ft_strlen(container[**i]);
	if (tmpa > b)
		b = b + (tmpa - b);
	(**i)++;
	return (b);
}

int		ft_flagdouble6(const char *str, char **container, size_t **i)
{
	long long int		a;
	long long int		b;
	long long int		tmpa;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	b = ft_getb(str);
	if (container[**i][0] == '-' && b > ft_strlen(container[**i]) - 1)
		return (ft_flagdouble5(str, container, &(*i)));
	ft_putstr(container[**i]);
	free((char *)str);
	str = 0;
	if (!(tmpa > ft_strlen(container[**i])))
		return (ft_strlen(container[(**i)++]));
	if (a < 0)
		ft_putspace(tmpa - ft_strlen(container[(**i)++]));
	return (tmpa);
}
