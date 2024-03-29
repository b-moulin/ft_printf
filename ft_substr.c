/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:35:50 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/07 14:18:26 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_lignes(const char *s, char *dest, size_t i, size_t start)
{
	if (start >= (size_t)(ft_strlen((char *)s)))
	{
		dest[i] = '\0';
		return (0);
	}
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len, int tofree)
{
	size_t	i;
	size_t	maxlen;
	char	*dest;

	if (!s || start > (size_t)(ft_strlen((char *)s)))
	{
		if (!s || !(dest = malloc(sizeof(char))))
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	len = len > (size_t)(ft_strlen((char *)s))
		? ft_strlen((char *)s) + start : len;
	maxlen = start + len;
	i = 0;
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (ft_lignes(s, dest, i, start) == 0)
		return (dest);
	while (start < maxlen)
		dest[i++] = s[start++];
	dest[i] = '\0';
	if (tofree)
		ft_freeargs((char *)s);
	return (dest);
}

int		ft_freeargs2(char *str, int ret)
{
	free((char *)str);
	str = 0;
	return (ret);
}
