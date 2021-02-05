/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:37:48 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:30:13 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_starin(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_joinptr(char *s1, char s2)
{
	char news2[2];

	news2[0] = s2;
	news2[1] = 0;
	return (ft_strjoin(s1, news2));
}

char	*ft_replacestar2(const char *str, char *newstr, size_t j)
{
	if (is_in(ft_rettype(str), "sc"))
	{
		if ((str[j + 1] != '0')
			&& str[j + 1] != '*')
			newstr = ft_joinptr(newstr, str[j + 1]);
	}
	else
	{
		if (str[j + 1] != '*')
			newstr = ft_joinptr(newstr, str[j + 1]);
	}
	return (newstr);
}

char	*ft_replacestar3(const char *str, char *newstr, size_t **i)
{
	newstr = ft_joinptr(newstr, ft_rettype(str));
	(**i)++;
	return (newstr);
}

char	*ft_replacestar4(const char *str, char *ctnr, size_t j, char *ns)
{
	char	*retptr;

	if (!ns)
		ns = ft_substr(str, 0, j, 0);
	if (ctnr[0] == '-' && (str[1] == '-'))
		ns = ft_strjoin(ns, ctnr + 1);
	else
		ns = ft_strjoin(ns, ctnr);
	retptr = ft_retptr(str[j + 1]);
	ns = ft_strjoin(ns, retptr);
	free(retptr);
	retptr = 0;
	return (ns);
}
