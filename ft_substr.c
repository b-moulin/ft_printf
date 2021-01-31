/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2021/01/06 15:35:50 by bmoulin      #+#   ##    ##    #+#       */
/*   Updated: 2021/01/31 11:28:28 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_lignes(const char *s, char *dest, size_t i, size_t start)
{
	if (start >= ft_strlen((char *)s))
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

	if (!s)
		return (NULL);
	if (start > ft_strlen((char *)s))
	{
		if (!(dest = malloc(sizeof(char))))
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	len = len > ft_strlen((char *)s) ? ft_strlen((char *)s) + start : len;
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
	{
		free((char *)s);
		s = 0;
	}
	return (dest);
}
