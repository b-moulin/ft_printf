/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleflag2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:21:16 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/28 08:48:25 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_rettype(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (str[i - 1]);
}

int		ft_getb(const char *str)
{
	size_t	i;
	size_t	j;
	long	len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] && str[i] != '.')
		i++;
	i++;
	j = i;
	while (str[j] && str[j] == '0')
		j++;
	while (str[i++])
		len++;
	return (ft_atoi(ft_substr(str, j, len)));
}

int		ft_geta(const char *str)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 1;
	while (str[j] && str[j] == '0')
		j++;
	while (str[i] && str[i] != '.')
		i++;
	return (ft_atoi(ft_substr(str, j, i)));
}

int		ft_putspaced(const char *str, char **container, size_t **i)
{
	size_t	j;
	int		a;
	int		b;

	j = 0;
	a = ft_geta(str);
	b = ft_geta(str);
	while (j < a - ft_strlen(container[**i]))
	{
		j++;
		write(1, " ", 1);
	}
	ft_putstr(container[(**i)++]);
	return (a);
}

int		ft_putzero(const char *str, char **container, size_t **i)
{
	int		j;
	int		b;

	j = 0;
	b = ft_getb(str);
	if (container[**i][0] == '-')
		write(1, "-", 1);
	while (j < b - ft_strlen(container[**i]) +
		(container[**i][0] == '-' ? 1 : 0))
	{
		j++;
		write(1, "0", 1);
	}
	if (container[**i][0] == '-')
		ft_putstr(container[**i] + 1);
	else
		ft_putstr(container[**i]);
	if (container[(**i)++][0] == '-')
		return (b + 1);
	return (b);
}
