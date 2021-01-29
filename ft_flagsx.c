/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:13:29 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/29 13:42:05 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (ft_ismalloc((void **)str))
		{
			free((char *)str);
			str = 0;
		}
		return (j);
	}
	if (ft_ismalloc((void **)str))
	{
		free((char *)str);
		str = 0;
	}
	return (ft_strlen(container[(**i)++]));
}

int		ft_flag4(const char *str, char **container, size_t **i, int j)
{
	int		ret;

	if (ft_getaftert(str) < 0)
		return (ft_flag4neg(str, container, &(*i)));
	if (ft_getaftert(str) <= ft_strlen(container[**i]))
	{
		if (ft_ismalloc((void **)str))
		{
			free((char *)str);
			str = 0;
		}
		ft_putstr(container[**i]);
		return (ft_strlen(container[(**i)++]));
	}
	else
	{
		if (container[**i][0] == 0)
		{
			while (j < ft_getaftert(str) - 1)
				write(1, j++ ? " " : " ", 1);
			if (ft_rettype(str) == 'c')
				write(1, "\0", 1);
			else
				write(1, " ", 1);
			ret = ft_getaftert(str);
			if (ft_ismalloc((void **)str))
			{
				free((char *)str);
				str = 0;
			}
			return (ret);
		}
		while (j < ft_getaftert(str) - ft_strlen(container[**i]))
			write(1, j++ ? " " : " ", 1);
		ft_putstr(container[(**i)++]);
		ret = ft_getaftert(str);
		if (ft_ismalloc((void **)str))
		{
			//printf("here\n\n");
			free((char *)str);
			str = 0;
		}
		return (ret);
	}
}
