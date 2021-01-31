/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_star.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2021/01/11 08:25:55 by bmoulin      #+#   ##    ##    #+#       */
/*   Updated: 2021/01/31 18:18:43 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
	newstr = newstr = ft_joinptr(newstr, ft_rettype(str));
	(**i)++;
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

// char	*ft_nomallocstr(const char *str)
// {
// 	size_t	i;
// 	char	tab[ft_strlen((char *)str)];

// 	i = 0;
// 	while (str[i])
// 	{
// 		tab[i] = str[i];
// 		i++;
// 	}
// 	tab[i] = str[i];
// 	free ((char *)str);
// 	str = 0;
// 	printf("tab : |%s|\n\n", tab);
// 	return (tab);
// }

int		ft_stopmalloc(const char *newstr, char **container)
{
	size_t	i;
	char	tab[ft_strlen((char *)newstr)];

	i = 0;
	while (newstr[i])
	{
		tab[i] = newstr[i];
		i++;
	}
	tab[i] = newstr[i];
	free ((char *)newstr);
	newstr = 0;
	return (ft_flaglist(tab, container, 0));
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
				newstr = !newstr ? ft_substr(str, 0, j - 1, 0) : newstr;
				newstr = ft_strjoin(newstr, container[(**i)++]);
				newstr = ft_joinptr(newstr, str[j]);
			}
		}
		else
			newstr = ft_replacestar2(str, newstr, j - 1);
	if (!(is_in(newstr[ft_strlen(newstr) - 1], "cspdiuxX%")))
		newstr = ft_strjoin(newstr, ft_retptr(str[j - 1]));
	// printf("ft_nomallocstr : |%s|\n\n\n", ft_nomallocstr(newstr));
	// return (0);
	//return (ft_stopmalloc(newstr, container));
	free((char *)str);
	str = 0;
	return (ft_flaglist(newstr, container, 0));
}
