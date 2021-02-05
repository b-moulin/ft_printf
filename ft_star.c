/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:25:55 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 10:07:49 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_replacestarb2(const char *str, char **ctn, size_t **i, t_star *star)
{
	if (ctn[**i] && ctn[**i + 1]
		&& ctn[**i + 1][0] == '0'
		&& is_in(ft_rettype(str), "duixX")
			&& ctn[**i][0] == '-')
	{
		star->newstr = !star->newstr
			? ft_substr(str, 0, star->j - 1, 0) : star->newstr;
		star->newstr = ft_joinptr(star->newstr, '1');
		(**i)++;
	}
	else
	{
		if (ft_geta(str) != 0 && ctn[**i][0] == '-'
			&& is_in(ft_rettype(str), "dui"))
		{
			star->newstr = !star->newstr
				? ft_substr(str, 0, star->j - 1, 0) : star->newstr;
			star->newstr = ft_strjoin_nos2(star->newstr,
				ft_itoa(ft_strlen(ctn[**i + 1])));
			(**i)++;
		}
		else
			star->newstr = ft_replacestarb(str, ctn, &(*i), star);
	}
	return (star->newstr);
}

char	*ft_replacestarb(const char *str, char **ctn, size_t **i, t_star *star)
{
	if (ctn[**i] && ctn[**i][0] == '-'
		&& !is_in(ft_rettype(str), "sc"))
	{
		star->newstr = !star->newstr
			? ft_substr(str, 0, star->j - 1, 0) : star->newstr;
		(**i)++;
		if (star->newstr[ft_strlen(star->newstr) - 1] == '.')
			star->newstr = ft_removelastchar(star->newstr);
	}
	else
	{
		if (!star->newstr)
			star->newstr = ft_substr(str, 0, star->j - 1, 0);
		star->newstr = ft_strjoin(star->newstr, ctn[(**i)++]);
		star->newstr = ft_joinptr(star->newstr, str[star->j]);
	}
	return (star->newstr);
}

char	*ft_replacestar2b(const char *str, char **ctn, size_t **i, t_star *star)
{
	if (is_in(ft_rettype(str), "duixXsc")
		&& ctn[**i][0] == '-' && ft_thereispoint(star->newstr))
	{
		star->newstr = ft_removelastchar(star->newstr);
		(**i)++;
	}
	else
	{
		if (ctn[**i] && is_in(ft_rettype(str), "sc")
			&& (ctn[**i][0] == '0'))
			star->newstr = ft_replacestar3(str, star->newstr, &(*i));
		else
			star->newstr = ft_replacestarb2(str, ctn, &(*i), star);
	}
	return (star->newstr);
}

int		ft_replacestar(const char *str, char **container, size_t **i)
{
	t_star	star;

	star.j = 0;
	star.newstr = 0;
	while (str[star.j] && str[star.j] != '.')
		if (str[star.j++] == '*')
			star.newstr = ft_replacestar4(str,
				container[(**i)++], star.j - 1, star.newstr);
	if (!star.newstr && !is_in(ft_rettype(str), "dui"))
		star.newstr = ft_substr(str, 0, star.j + 1, 0);
	while (str[star.j])
	{
		if (str[star.j++] == '*')
			star.newstr = ft_replacestar2b(str, container, &(*i), &star);
		else
			star.newstr = ft_replacestar2(str, star.newstr, star.j - 1);
	}
	if (!(is_in(star.newstr[ft_strlen(star.newstr) - 1], "cspdiuxX%"))
		|| ft_strlen(star.newstr) < 2)
		star.newstr = ft_joinptr(star.newstr, str[star.j - 1]);
	free((char *)str);
	str = 0;
	return (ft_flaglist(star.newstr, container, 0));
}
