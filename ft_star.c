/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:25:55 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/28 15:25:09 by bmoulin          ###   ########lyon.fr   */
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

char	*ft_replacestar2(const char *str, char *newstr, size_t j)
{
	if (is_in(ft_rettype(str), "sc"))
	{
		if ((ft_retptr(str[j + 1])[0] != '0')
			&& ft_retptr(str[j + 1])[0] != '*')
			newstr = ft_strjoin(newstr, ft_retptr(str[j + 1]));
	}
	else
	{
		if (ft_retptr(str[j + 1])[0] != '*')
			newstr = ft_strjoin(newstr, ft_retptr(str[j + 1]));
	}
	return (newstr);
}

char	*ft_replacestar3(const char *str, char *newstr, size_t **i)
{
	newstr = ft_strjoin(newstr, ft_retptr(ft_rettype(str)));
	(**i)++;
	(**i)++;
	return (newstr);
}

char	*ft_replacestar4(const char *str, char *ctnr, size_t j, char *ns)
{
	char	*retptr;

	if (!ns)
		ns = ft_substr(str, 0, j);
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

int		ft_replacestar(const char *str, char **container, size_t **i)
{
	size_t	j;
	char	*newstr;

	j = 0;
	newstr = 0;
	while (str[j] && str[j] != '.')
		if (str[j++] == '*')
			newstr = ft_replacestar4(str, container[(**i)++], j - 1, newstr);
	while (str[j])
		if (str[j++] == '*')
		{
			if (is_in(ft_rettype(str), "sc") && (container[**i][0] == '0'))
				newstr = ft_replacestar3(str, newstr, &(*i));
			else
			{
				newstr = !newstr ? ft_substr(str, 0, j - 1) : newstr;
				newstr = ft_strjoin(newstr, container[(**i)++]);
				newstr = ft_strjoin(newstr, ft_retptr(str[j]));
			}
		}
		else
			newstr = ft_replacestar2(str, newstr, j - 1);
	if (!(is_in(newstr[ft_strlen(newstr) - 1], "cspdiuxX%")))
		newstr = ft_strjoin(newstr, ft_retptr(str[j - 1]));
	return (ft_flaglist(newstr, container, 0));
}
