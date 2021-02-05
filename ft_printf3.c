/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:05:20 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:52:40 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_address2b(char *addr, const char *str)
{
	long long	tmpa;
	long long	a;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	if (tmpa <= 2)
	{
		write(1, "0x", 2);
		ft_freeargs(addr);
		ft_freeargs((char *)str);
		return (2);
	}
	if (a > 0)
	{
		ft_putspace(a - 2);
		write(1, "0x", 2);
		ft_freeargs(addr);
		ft_freeargs((char *)str);
		return (a);
	}
	write(1, "0x", 2);
	ft_putspace(tmpa - 2);
	ft_freeargs(addr);
	ft_freeargs((char *)str);
	return (tmpa);
}

int		ft_address2(char *addr, const char *str)
{
	long long	a;

	if (is_in('.', (char *)str) && addr[0] == '0')
		return (ft_address2b(addr, str));
	write(1, "0x", 2);
	ft_putstr(addr);
	a = ft_strlen(addr) + 2;
	ft_freeargs(addr);
	ft_freeargs((char *)str);
	return (a);
}

int		ft_addressb(char *addr, const char *str)
{
	long long	tmpa;
	long long	a;

	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	if (tmpa <= ft_strlen(addr) + 2)
	{
		write(1, "0x", 2);
		a = ft_strlen(addr) + 2;
		ft_putstr(addr);
		free(addr);
		addr = 0;
		free((char *)str);
		str = 0;
		return (a);
	}
	ft_putspace(a - ft_strlen(addr) - 2);
	write(1, "0x", 2);
	ft_putstr(addr);
	free(addr);
	addr = 0;
	free((char *)str);
	str = 0;
	return (a);
}

int		ft_address(const char *str, char *container)
{
	char		*addr;
	long long	a;
	long long	tmpa;

	addr = ft_nbrbase(ft_atoi(container), "0123456789abcdef");
	a = 0;
	if ((is_in('.', (char *)str) && addr[0] == '0')
		|| (ft_strlen((char *)str) == 2))
		return (ft_address2(addr, str));
	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	if (a > 0 || tmpa <= ft_strlen(addr) + 2)
		return (ft_addressb(addr, str));
	free((char *)str);
	str = 0;
	write(1, "0x", 2);
	ft_putstr(addr);
	ft_putspace(tmpa - ft_strlen(addr) - 2);
	free(addr);
	addr = 0;
	free((char *)str);
	str = 0;
	return (tmpa);
}

int		ft_nbtype(const char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' || str[i] == '*')
			len++;
		i++;
	}
	return (len);
}
