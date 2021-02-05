/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 07:54:44 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:23:19 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_returnflag(const char *str)
{
	size_t	i;

	i = 1;
	while (str[i])
	{
		if (is_in(str[i], "cspdiuxX%"))
			return (ft_substr(str, 0, i + 1, 0));
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
	if ((unsigned long long)str > 140737488355328 - 8000000)
		return (1);
	if ((unsigned long long)str == 0)
		return (1);
	return (0);
}

int		ft_write(const char *str, char **container)
{
	t_wr	wr;

	wr.i = 0;
	wr.nb_write = 0;
	while (str[wr.i])
	{
		wr.malstr = ft_returnflag(str + wr.i);
		if (str[wr.i] != '%' || wr.malstr[1] == 0)
		{
			if (str[wr.i] == '%')
				write(1, &str[wr.i++], 1);
			else
				write(1, &str[wr.i], 1);
			wr.nb_write++;
			ft_freeargs((char *)wr.malstr);
		}
		else
		{
			wr.i = wr.i + ft_strlen(wr.malstr) - 1;
			wr.nb_write = wr.nb_write +
				ft_flaglist(wr.malstr, container, 0);
		}
		wr.i++;
	}
	return (wr.nb_write);
}
