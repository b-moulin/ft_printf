/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:13:29 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 10:27:44 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_freeargs(char *str)
{
	free((char *)str);
	str = 0;
	return (0);
}

int		ft_flag4neg(const char *str, char **container, size_t **i)
{
	int		j;

	j = ft_getaftert(str) * -1;
	if (container[**i][0] == 0)
	{
		if (ft_rettype(str) == 'c')
			write(1, "\0", 1);
		else
			write(1, " ", 1);
	}
	else
		ft_putstr(container[**i]);
	if (j > ft_strlen(container[**i]))
	{
		while (j-- > ft_strlen(container[**i])
			+ (container[**i][0] == 0 ? 1 : 0))
			write(1, " ", 1);
		(**i)++;
		j = ft_getaftert(str) * -1;
		free((char *)str);
		str = 0;
		return (j);
	}
	ft_freeargs((char *)str);
	return (ft_strlen(container[(**i)++]));
}

int		ft_flag4b3(const char *str, char **container, size_t **i, int j)
{
	int		ret;

	if (container[**i][0] == 0)
	{
		while (j < ft_getaftert(str) - 1)
			write(1, j++ ? " " : " ", 1);
		if (ft_rettype(str) == 'c')
			write(1, "\0", 1);
		else
			write(1, " ", 1);
		ret = ft_getaftert(str);
		free((char *)str);
		str = 0;
		return (ret);
	}
	while (j < ft_getaftert(str) - ft_strlen(container[**i]))
		write(1, j++ ? " " : " ", 1);
	ft_putstr(container[(**i)++]);
	ret = ft_getaftert(str);
	free((char *)str);
	str = 0;
	return (ret);
}

int		ft_flag4(const char *str, char **container, size_t **i, int j)
{
	int		ret;

	if (ft_getaftert(str) < 0)
		return (ft_flag4neg(str, container, &(*i)));
	if (ft_getaftert(str) <= ft_strlen(container[**i]))
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
	return (ft_flag4b3(str, container, &(*i), j));
}
