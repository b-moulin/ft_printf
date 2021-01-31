/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flagzero3.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2021/01/28 08:57:27 by bmoulin      #+#   ##    ##    #+#       */
/*   Updated: 2021/01/31 19:33:12 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "ft_printf.h"

int		ft_nbargsttwo3(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (b == 0 && a == 0 && ft_rettype(str) == 's')
	{
		(**i)++;
		return (0);
	}
	if (a == 0 && ft_rettype(str) == 'c')
	{
		write(1, container[(**i)++], 1);
		return (1);
	}
	write(1, " ", 1);
	(**i)++;
	return (1);
}

int		ft_nbargsttwo4(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (container[**i][0] == '-')
	{
		write(1, "-", 1);
		ft_putzerob(b - ft_strlen(container[**i]) + 1);
		ft_putstr(container[(**i)++] + 1);
		return (b + 1);
	}
	else
	{
		ft_putzerob(b - ft_strlen(container[**i]));
		ft_putstr(container[(**i)++]);
	}
	return (b);
}

int		ft_nbargsttwo5(const char *str, char **container, size_t **i)
{
	long	tmpa;
	long	b;

	tmpa = ft_geta(str) > 0 ? ft_geta(str) : -ft_geta(str);
	b = ft_getb(str);
	if (b == 0 && is_in(ft_rettype(str), "sc"))
	{
		ft_putspace(tmpa);
		free((char *)str);
		str = 0;
		return (tmpa);
	}
	ft_putstr(container[**i]);
	ft_putspace(tmpa - ft_strlen(container[(**i)++]));
	free((char *)str);
	str = 0;
	return (tmpa);
}

int		ft_nbargsttwo6(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (container[**i][0] == '-' && tmpa > b
		&& tmpa > ft_strlen(container[**i]))
	{
		if (b > ft_strlen(container[**i]))
			ft_putspace(tmpa - b - 1);
		if (!(b > ft_strlen(container[**i]))
			&& b > ft_strlen(container[**i]) - 1)
			ft_putspace(tmpa - ft_strlen(container[**i])
				- (b - ft_strlen(container[**i]) + 1));
		else if (!((b > ft_strlen(container[**i]))))
			ft_putspace(tmpa - ft_strlen(container[**i]));
		write(1, "-", 1);
		return (1);
	}
	else
		ft_putspace(tmpa - (b > ft_strlen(container[**i])
			? b : ft_strlen(container[**i])));
	return (0);
}

int		ft_nbargsttwo7(const char *str, char **container, size_t **i)
{
	long	a;
	long	b;
	long	tmpa;

	a = ft_geta(str);
	b = ft_getb(str);
	tmpa = a > 0 ? a : -a;
	if (container[**i][0] == '-')
		write(1, "-", 1);
	if (b > tmpa - ft_strlen(container[**i]) + 1
		&& is_in(ft_rettype(str), "dui"))
		ft_putzerob((tmpa - (tmpa - b
			+ (container[**i][0] == '0' ? 1 : 0)))
			- ft_strlen(container[**i]) + 1);
	if (b > tmpa - ft_strlen(container[**i]) + 1
		&& !(is_in(ft_rettype(str), "dui")))
		ft_putzerob((tmpa - (tmpa - b + 1))
			- ft_strlen(container[**i]) + 1);
	if (container[**i][0] == '-')
		ft_putstr(container[**i] + 1);
	else
		ft_putstr(container[**i]);
	free((char *)str);
	str = 0;
	return (b + (container[(**i)++][0] == '-' ? 1 : 0));
}
