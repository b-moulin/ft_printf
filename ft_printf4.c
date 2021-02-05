/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:10:51 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:03:25 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_getflagb(const char *str, size_t i)
{
	if (str[i] == '%')
		return (321);
	return (ft_getflag2(str[i], str[i - 1]));
}

int		ft_getflag(const char *str, int restart)
{
	static size_t	i = 0;
	static size_t	percenton = 0;

	if (restart == 1)
		return (ft_resetstatic(&i, &percenton));
	while (str[i])
	{
		if ((str[i] == '%' && str[i + 1] != '%') || percenton == 1)
		{
			percenton = 1;
			i++;
			while (str[i] && is_in(str[i], "cspdiuxX*%") != 1)
				i++;
			if (str[i] == '*')
				return (i < 9999 ? 2 : 2);
			percenton = 0;
			if (str[i] == '%' || ft_getflag2(str[i], str[i - 1]) != 0)
				return (ft_getflagb(str, i));
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			i++;
		if (!str[i++])
			return (0);
	}
	return (0);
}

void	ft_ptf(t_ptf *ptf, va_list arg, const char *str)
{
	if (ptf->getflag == 1)
	{
		str = va_arg(arg, const char *);
		if (!str)
			ptf->args[ptf->i] = ft_strdup("(null)");
		else
			ptf->args[ptf->i] = ft_strdup((char *)str);
	}
	else
	{
		ptf->c[1] = 0;
		ptf->c[0] = va_arg(arg, const int);
		str = (char *)ptf->c;
		if (ptf->c[0] == 0)
			ptf->args[ptf->i] = ft_strdup("");
		else
			ptf->args[ptf->i] = ft_strdup((char *)str);
	}
}

void	ft_ptf2(t_ptf *ptf, va_list arg, const char *str)
{
	str = ft_itoa((unsigned int)va_arg(arg, unsigned int));
	if (!str)
		str = ft_strdup("(null)");
	if (ptf->getflag == 66)
	{
		str = ft_nbrbase(ft_atoi(str), "0123456789abcdef");
		ptf->args[ptf->i] = ft_strdup((char *)str);
		ft_freeargs((char *)str);
	}
	else
	{
		str = ft_nbrbase(ft_atoi(str), "0123456789ABCDEF");
		ptf->args[ptf->i] = ft_strdup((char *)str);
		ft_freeargs((char *)str);
	}
}
