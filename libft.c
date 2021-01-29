/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:11:09 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/28 14:00:30 by bmoulin          ###   ########lyon.fr   */
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
	long long		i;
	short int		k;
	long long		value;

	value = 0;
	k = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		k = -k;
	if (str[i] == '+' || str[i] == '-')
		i++;
	else if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	if (str[i] >= '0' && str[i] <= '9')
	{
		value = str[i] - 48;
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			value = value * 10 + (str[i++] - 48);
	}
	free ((char *)str);
	str = 0;
	return (value * k);
}

char		*ft_retptr(const char c)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	ret[1] = 0;
	ret[0] = c;
	return (ret);
}
