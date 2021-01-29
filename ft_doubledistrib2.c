/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubledistrib2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:08:06 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/28 08:55:17 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_valuept(const char *str)
{
	size_t	i;

	i = 1;
	while (str[i] && str[i] != '.')
		i++;
	return (ft_atoi(ft_substr(str, 1, i - 1)));
}

int		ft_valuept2(const char *str)
{
	size_t	i;

	i = 1;
	while (str[i] && str[i] != '.')
		i++;
	return (ft_atoi(ft_substr(str, i + 1, ft_strlen((char *)str) - 1)));
}

int		ft_dflag3r(const char *str, char *container, size_t **i)
{
	size_t	j;

	j = 0;
	if (ft_strlen(container) >= ft_valuept2(str))
	{
		ft_putstr(container);
		return (ft_strlen(container));
	}
	else
	{
		ft_putstr_len(container, ft_valuept2(str));
		return (ft_valuept2(str));
	}
}

int		ft_dflag3(const char *str, char *container, size_t **i)
{
	size_t	j;

	j = 0;
	if (ft_strlen(container) < ft_valuept(str))
	{
		while (j < ft_valuept(str) - ft_strlen(container))
		{
			write(1, " ", 1);
			j++;
		}
		ft_putstr(container);
		(**i)++;
		return (ft_valuept(str));
	}
	else
	{
		ft_putstr(container);
		(**i)++;
		return (ft_valuept(str));
	}
}

char	*ft_b(const char *str, char **container, size_t **i)
{
	size_t	j;

	j = 0;
	if (ft_strlen(container[**i]) == 0 ||
		ft_strlen(container[**i]) <= ft_getb(str))
		return (container[**i]);
	else if (ft_strlen(container[**i]) > ft_getb(str))
		return (ft_substr(container[**i], 0, ft_getb(str)));
	return (0);
}
