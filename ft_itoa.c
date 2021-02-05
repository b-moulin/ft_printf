/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:19:11 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/04 16:04:07 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_lendest(long long n)
{
	long long	size;
	long long	count;

	size = 0;
	if (n == LONG_MIN)
		return (20);
	if (n < 0)
	{
		count = -n;
		size++;
	}
	else
		count = n;
	while (count >= 10)
	{
		size++;
		count = count / 10;
	}
	size++;
	return (size);
}

static char			*ft_filldest(long long n, long long len, char *dest)
{
	dest[len] = '\0';
	len--;
	if (n < 0)
	{
		dest[0] = '-';
		if (n == LONG_MIN)
			n = n - 1;
		else
			n = -n;
	}
	while (n >= 10)
	{
		dest[len] = (n % 10) + 48;
		len--;
		n = n / 10;
	}
	dest[len] = n + 48;
	return (dest);
}

char				*ft_itoa(long long n)
{
	char		*dest;
	long long	lln;

	if (!n || n == 0)
	{
		if (!(dest = malloc(sizeof(char) * 2)))
			return (NULL);
		dest[1] = 0;
		dest[0] = '0';
		return (dest);
	}
	lln = n;
	if (!lln)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_lendest(lln) + 1));
	if (!dest)
		return (NULL);
	return (ft_filldest(lln, ft_lendest(lln), dest));
}

int					ft_putspace(long long nb)
{
	unsigned long ret;

	ret = nb;
	if (nb < 0)
		return (0);
	while (nb-- > 0)
		write(1, " ", 1);
	return (ret);
}

int					ft_getaftert(const char *str)
{
	size_t	i;
	size_t	j;
	size_t	start;
	int		ret;

	i = 1;
	j = 0;
	start = 1;
	while (str[i] && (str[i] == '-' || str[i] == '0'))
	{
		i++;
		start++;
	}
	if (start > 1)
		start--;
	if (str[i] && str[i] == '0')
		return (0);
	i--;
	while ((str[++i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+')
		j++;
	ret = ft_atoi(ft_substr(str, start, j + 1, 0));
	return (ret);
}
