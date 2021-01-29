/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:48:03 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/28 09:13:15 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getafterp(const char *str)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i] != '.' && str[i] != '-' && str[i] != '+')
		i++;
	start = i + 1;
	while (str[++i] >= '0' && str[i] <= '9')
		j++;
	return (ft_atoi(ft_substr(str, start, j)));
}

int		ft_flagx(const char *str, char **container, size_t **i, int j)
{
	if (container[**i][0] == '-')
	{
		write(1, "-", 1);
		while (j++ < ft_getafterp(str) - ft_strlen(container[**i] + 1))
			write(1, "0", 1);
		ft_putstr(container[(**i)++] + 1);
		return (ft_getafterp(str) + 1);
	}
	while (j++ < ft_getafterp(str) - ft_strlen(container[**i]))
		write(1, "0", 1);
	ft_putstr(container[(**i)++]);
	return (ft_getafterp(str));
}

int		ft_flagxx(const char *str, char **container, size_t **i)
{
	if (is_in('d', (char *)str) || is_in('i', (char *)str)
		|| is_in('u', (char *)str) || is_in('x', (char *)str)
			|| is_in('X', (char *)str))
	{
		ft_putstr(container[**i]);
		return (ft_strlen(container[(**i)++]));
	}
	if (ft_getb(str) < 0)
	{
		ft_putstr(container[**i]);
		return (ft_strlen(container[(**i)++]));
	}
	ft_putstr_len(container[**i], ft_getafterp(str));
	(**i)++;
	return (ft_getafterp(str));
}

int		ft_flag3(const char *str, char **container, size_t **i)
{
	int		j;

	j = 0;
	if (ft_strlen(container[**i]) <= ft_getafterp(str))
	{
		if (is_in('d', (char *)str) || is_in('u', (char *)str)
			|| is_in('i', (char *)str) || is_in('x', (char *)str)
				|| is_in('X', (char *)str))
			return (ft_flagx(str, container, &(*i), j));
		ft_putstr(container[**i]);
		return (ft_strlen(container[(**i)++]));
	}
	else
		return (ft_flagxx(str, container, &(*i)));
	return (0);
}

int		ft_flag2(const char *str, char **container, size_t **i)
{
	if (str[1] == '.' && str[2] == 's')
	{
		(**i)++;
		return (0);
	}
	if (str[1] == '.' && str[2] == 'c')
	{
		write(1, &container[**i][0], 1);
		(**i)++;
		return (1);
	}
	else if (str[1] == '.' && is_in(str[2], "udixX"))
	{
		if (container[**i][0] == '0')
		{
			(**i)++;
			return (0);
		}
		ft_putstr(container[**i]);
		return (ft_strlen(container[(**i)++]));
	}
	return (0);
}
