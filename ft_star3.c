/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:40:24 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 10:10:04 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_stopmalloc(const char *newstr, char **container)
{
	size_t	i;
	char	tab[ft_strlen((char *)newstr)];

	i = 0;
	while (newstr[i])
	{
		tab[i] = newstr[i];
		i++;
	}
	tab[i] = newstr[i];
	free((char *)newstr);
	newstr = 0;
	return (ft_flaglist(tab, container, 0));
}

char	*ft_removelastchar(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(sizeof(char) * ft_strlen(src))))
		return (NULL);
	while (src[i + 1])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	free(src);
	src = 0;
	return (dest);
}

int		ft_thereispoint(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		ft_nbargsttwo2(const char *str, char **container, size_t **i)
{
	long	b;

	b = ft_getb(str);
	if (container[**i][0] == '0' && b == 0 && is_in(ft_rettype(str), "dui"))
	{
		free((char *)str);
		str = 0;
		(**i)++;
		return (0);
	}
	if ((b >= ft_strlen(container[**i]) || b == 0)
		&& is_in(ft_rettype(str), "dui"))
	{
		ft_putstr(container[**i]);
		free((char *)str);
		str = 0;
		return (ft_strlen(container[(**i)++]));
	}
	ft_putstr_len(container[**i], b);
	free((char *)str);
	str = 0;
	(**i)++;
	return (b);
}
