/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:48:03 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/07 14:00:45 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flagxx2b2(const char *str, char **container, size_t **i)
{
	int		ret;

	if (ft_getb(str) < 0)
	{
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	ft_putstr_len(container[**i], ft_getafterp(str));
	(**i)++;
	ret = ft_getafterp(str);
	free((char *)str);
	str = 0;
	return (ret);
}

int		ft_flagxx(const char *str, char **container, size_t **i)
{
	int		ret;

	if (is_in('d', (char *)str) || is_in('i', (char *)str)
		|| is_in('u', (char *)str) || is_in('x', (char *)str)
			|| is_in('X', (char *)str))
	{
		if (is_in('d', (char *)str)
			&& container[**i][0] == '0' && ft_getb(str) < 0)
		{
			ret = -ft_getb(str);
			ft_putspace(ret);
			free((char *)str);
			str = 0;
			(**i)++;
			return (ret);
		}
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	return (ft_flagxx2b2(str, container, &(*i)));
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
		{
			return (ft_flagx(str, container, &(*i), j));
		}
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	else
		return (ft_flagxx(str, container, &(*i)));
	return (0);
}

int		ft_flag2b3(const char *str, char **container, size_t **i)
{
	if (str[1] == '.' && is_in(str[2], "udixX"))
	{
		if (container[**i][0] == '0')
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
	free((char *)str);
	str = 0;
	return (0);
}

int		ft_flag2(const char *str, char **container, size_t **i)
{
	if (str[1] == '.' && str[2] == 's')
	{
		(**i)++;
		free((char *)str);
		str = 0;
		return (0);
	}
	if (str[1] == '.' && str[2] == 'c')
	{
		write(1, &container[**i][0], 1);
		(**i)++;
		free((char *)str);
		str = 0;
		return (1);
	}
	return (ft_flag2b3(str, container, &(*i)));
}
