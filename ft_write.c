/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 07:54:44 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/29 15:54:49 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_star(const char *str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (!(str[i] != '%' || (str[i] == '%' && str[i + 1] == '%')))
			if (is_in('*', ft_returnflag(str + i)))
				ret++;
		i++;
	}
	return (ret);
}

char	*ft_returnflag(const char *str)
{
	size_t	i;

	i = 1;
	while (str[i])
	{
		if (is_in(str[i], "cspdiuxX%"))
			return (ft_substr(str, 0, i + 1));
		i++;
	}
	return (NULL);
}

int		ft_getnbargs(const char *str)
{
	size_t	i;

	i = 0;
	if (is_in('.', (char *)str) == 0)
		return (0);
	if (str[1] == '.')
		return (1);
	return (2);
}

int		ft_percflag(const char *str)
{
	if (str[2] == 0 || (str[2] == '%'
		&& str[1] == '.') || ft_getnbargs(str) == 1)
	{
		write(1, "%%", 1);
		free((char *)str);
		str = 0;
		return (1);
	}
	if (ft_getnbargs(str) == 0)
		return (ft_prctzero(str, 0));
	if (ft_getnbargs(str) == 2)
		return (ft_prctwo(str));
	free((char *)str);
	str = 0;
	return (0);
}

int		ft_ismalloc(void **str)
{
	// printf("\n\nstr : &s | %lld\n\n", str, (unsigned long long)str);
	// if ((unsigned long long)str > 140737488355328 - 8000000)
	// 	return (0);
	return (1);
	// char *addr;

	// if (!(addr = ft_nbrbase((unsigned long long)str, "0123456789abcdef")))
	// 	return (0);
	// // printf("addr : %s\n", addr);
	// // printf("str : %p\n", str);
	// if (ft_strlen(addr) <= 7)
	// {
	// 	free(addr);
	// 	addr = 0;
	// 	return (1);
	// }
	// free(addr);
	// addr = 0;
	// return (0);
}

int		ft_write(const char *str, char **container)
{
	size_t	i;
	size_t	nb_write;
	char	*malstr;

	i = 0;
	nb_write = 0;
	while (str[i])
	{
		malstr = ft_returnflag(str + i);
		if (str[i] != '%' || malstr[1] == 0)
		{
			if (str[i] == '%')
				write(1, &str[i++], 1);
			else
				write(1, &str[i], 1);
			nb_write++;
		}
		else
		{
			nb_write = nb_write +
				ft_flaglist(malstr, container, 0);
			i = i + ft_strlen(malstr) - 1;
		}
		if (ft_ismalloc((void **)malstr))
		{
			free(malstr);
			malstr = 0;
		}
		i++;
	}
	if (ft_ismalloc((void *)malstr))
	{
		free(malstr);
		malstr = 0;
	}
	return (nb_write);
}
