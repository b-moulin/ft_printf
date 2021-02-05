/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flaglist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 08:52:59 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:32:42 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flaglist2(const char *str, char **container, size_t **i)
{
	if (ft_flagzero(str) == 1)
		return (ft_flag5(str, container, &(*i)));
	if (ft_strlen((char *)str) > 3 &&
		is_in(str[ft_strlen((char *)str) - 2], "0123456789.") &&
			is_in(str[1], "-+0123456789") && is_in('.', (char *)str))
		return (ft_flagdouble(str, container, &(*i)));
	if (ft_strlen((char *)str) == 3 && str[1] == '.')
		return (ft_flag2(str, container, &(*i)));
	if (ft_strlen((char *)str) > 3 && str[1] == '.')
		return (ft_flag3(str, container, &(*i)));
	if (ft_strlen((char *)str) >= 3 &&
		ft_strnstr((char *)str, ".", ft_strlen((char *)str)) == 0)
		return (ft_flag4(str, container, &(*i), 0));
	return (0);
}

int		ft_flaglist3(const char *str, char **container, size_t **i)
{
	if (container[**i][0] == 0 && ft_rettype(str) == 'c')
	{
		write(1, "\0", 1);
		(**i)++;
		free((char *)str);
		str = 0;
		return (1);
	}
	ft_putstr(container[**i]);
	free((char *)str);
	str = 0;
	return (ft_strlen(container[(**i)++]));
}

int		thereisnullb(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		if (is_in(str[i + 1], "cspdiuxX"))
			return (1);
	return (0);
}

int		ft_flaglist2b2(const char *str, char **container, size_t **i, char *m)
{
	if (ft_rettype(m) == '%')
	{
		free(m);
		m = 0;
		return (ft_percflag(str));
	}
	if (ft_rettype(m) == 'p')
	{
		free(m);
		m = 0;
		return (ft_address(str, ft_strdup(container[(**i)++])));
	}
	if (ft_strlen((char *)str) == 2)
	{
		free(m);
		m = 0;
		return (ft_flaglist3(str, container, &(*i)));
	}
	free(m);
	m = 0;
	return (ft_flaglist2(str, container, &(*i)));
}

int		ft_flaglist(const char *str, char **container, int reset)
{
	static	size_t	*i = 0;
	char			*malstr;

	if (reset == 1)
	{
		free(i);
		i = 0;
		return (0);
	}
	if (!i)
	{
		if (!(i = malloc(sizeof(size_t))))
			return (0);
		*i = 0;
	}
	malstr = ft_returnflag(str);
	if (ft_starin(str))
	{
		free(malstr);
		malstr = 0;
		return (ft_replacestar(str, container, &i));
	}
	return (ft_flaglist2b2(str, container, &i, malstr));
}
