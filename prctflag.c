/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prctflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:36:58 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 10:18:22 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getprcta(const char *str)
{
	size_t	i;
	int		neg;
	int		ret;

	i = 0;
	ret = 0;
	neg = 1;
	while (str[i++])
	{
		while (str[i] && str[i] == '0')
			i++;
		if (str[i] == '-')
		{
			neg = -neg;
			i++;
		}
		if (str[i] && str[i] >= '0' && str[i] <= '9')
			ret = str[i++] - 48;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			ret = (ret * 10) + (str[i++] - 48);
	}
	return (ret * neg);
}

int		ft_prctwo(const char *str)
{
	return (ft_prctzero(str, 1));
}

int		ft_prctzero(const char *str, int two)
{
	int		a;
	int		i;

	i = 0;
	a = two == 0 ? ft_getprcta(str) : ft_geta(str);
	ft_freeargs((char *)str);
	if (a == 0)
		return (write(1, "%%", 1));
	if (a < 0)
	{
		write(1, "%%", 1);
		while (i-- > a + 1)
			write(1, " ", 1);
		return (-a);
	}
	if (a > 0)
	{
		while (i < a - 1)
			write(1, " ", i++ >= -90000 ? 1 : 1);
		write(1, "%%", 1);
		return (a);
	}
	return (0);
}
