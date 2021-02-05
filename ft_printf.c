/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 07:27:59 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:03:19 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptf3(t_ptf *ptf, va_list arg, const char *str)
{
	if (ptf->getflag == 66 || ptf->getflag == 67)
		ft_ptf2(ptf, arg, str);
	else if (ptf->getflag == 15)
	{
		str = ft_itoa(va_arg(arg, unsigned int));
		if (!str)
			str = ft_strdup("(null)");
		ptf->args[ptf->i] = ft_strdup((char *)str);
		ft_freeargs((char *)str);
	}
	else
	{
		str = ft_itoa(va_arg(arg, int));
		if (!str)
			str = ft_strdup("(null)");
		ptf->args[ptf->i] = ft_strdup((char *)str);
		ft_freeargs((char *)str);
	}
}

void	ft_ptf4(t_ptf *ptf, va_list arg, const char *str)
{
	if (ptf->getflag != 321)
	{
		if (ptf->i == 0)
			ft_freeargs(ptf->args[0]);
		if (ptf->getflag == 21)
		{
			str = va_arg(arg, void *);
			ptf->args[ptf->i] = ft_strdup("HELLO");
		}
		else if (ptf->getflag == 1 || ptf->getflag == 3)
			ft_ptf(ptf, arg, str);
		else if (ptf->getflag == 10)
		{
			str = ft_itoa((unsigned long long)va_arg(arg, void *));
			ptf->args[ptf->i] = ft_strjoin_nos1("", (char *)str);
		}
		else
			ft_ptf3(ptf, arg, str);
		ptf->i++;
	}
	ptf->getflag = ft_getflag(ptf->first, 0);
}

void	ft_ptf5(t_ptf *ptf, va_list arg, const char *str)
{
	ptf->i = 0;
	while (ptf->getflag != 0)
		ft_ptf4(ptf, arg, str);
	if (ptf->i == 0)
		free((char *)ptf->args[ptf->i]);
	ptf->args[ptf->i] = NULL;
	va_end(arg);
}

int		ft_printf(const char *str, ...)
{
	va_list		arg;
	t_ptf		ptf;

	va_start(arg, str);
	ptf.first = ft_strdup((char *)str);
	va_end(arg);
	if (!(ptf.c = malloc(sizeof(char) * 2)))
		return (0);
	if (!(ptf.args = malloc(sizeof(char *) * (ft_nbtype(str) + 1))))
		return (ft_freeargs(ptf.c));
	ptf.getflag = ft_getflag(ptf.first, 0);
	ptf.args[0] = ft_strdup((char *)str);
	va_start(arg, str);
	ft_ptf5(&ptf, arg, str);
	ptf.ret = ft_write(ptf.first, ptf.args);
	ft_getflag(ptf.first, 1);
	ft_flaglist(ptf.first, ptf.args, 1);
	ptf.i = 0;
	free(ptf.c);
	while (ptf.args[ptf.i])
		free(ptf.args[ptf.i++]);
	free(ptf.args);
	free(ptf.first);
	return (ptf.ret);
}
