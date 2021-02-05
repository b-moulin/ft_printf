/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:11:09 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 10:27:26 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	p;

	p = 0;
	i = 0;
	j = 0;
	if (ft_strlen((char *)find) > ft_strlen((char *)str) || !find[0] || !str)
		return (!find[0] || !str ? (char *)str : NULL);
	while (str[i] && i < len)
	{
		while (str[i] != find[j] && str[i] && i < len)
			i++;
		p = str[i] == find[j] ? i : p;
		while (str[i] == find[j]
			&& str[i] && find[j++] && i++ < len)
			if (find[j] == '\0')
				return ((char *)str + p);
		if (i >= len || !str[i])
			return (NULL);
		i = p;
		j = 0;
		i++;
	}
	return (NULL);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen((char *)src));
}

long long	ft_atoi(const char *str)
{
	t_at	at;

	at.value = 0;
	at.k = 1;
	at.i = 0;
	while (str[at.i] == ' ' || str[at.i] == '\t' || str[at.i] == '\n'
	|| str[at.i] == '\v' || str[at.i] == '\f' || str[at.i] == '\r')
		at.i++;
	if (str[at.i] == '-')
		at.k = -at.k;
	if (str[at.i] == '+' || str[at.i] == '-')
		at.i++;
	else if (!(str[at.i] >= '0' && str[at.i] <= '9'))
		return (ft_freeargs((char *)str));
	if (str[at.i] >= '0' && str[at.i] <= '9')
	{
		at.value = str[at.i] - 48;
		at.i++;
		while (str[at.i] >= '0' && str[at.i] <= '9')
			at.value = at.value * 10 + (str[at.i++] - 48);
	}
	ft_freeargs((char *)str);
	return (at.value * at.k);
}

char		*ft_retptr(const char c)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	ret[1] = 0;
	ret[0] = c;
	return (ret);
}

void		ft_nbargsttwo14(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (b == 0 && a >= ft_strlen(container[**i])
		&& is_in(ft_rettype(str), "sc"))
		ft_putspace(ft_strlen(container[**i]));
	else
		ft_putstr(container[**i]);
	free((char *)str);
	str = 0;
}
