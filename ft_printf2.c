/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:01:35 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 12:49:42 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_len(const char *str, const size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] && i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_getflag2(const char c, const char before)
{
	if (is_in(c, "cs") == 1)
	{
		if (before == '.')
			return (21);
		return (is_in(c, "s") == 1 ? 1 : 3);
	}
	if (is_in(c, "dixX") == 1)
	{
		if (is_in(c, "di") == 1)
			return (2);
		return (c == 'x' ? 66 : 67);
	}
	if (c == 'p')
		return (10);
	if (c == 'u')
		return (15);
	return (0);
}

int		ft_resetstatic(size_t *a, size_t *b)
{
	if (*a)
		*a = 0;
	if (*b)
		*b = 0;
	return (0);
}
