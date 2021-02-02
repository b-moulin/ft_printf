/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 07:27:59 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/02 15:48:50 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_len(const char *str, const size_t	len)
{
	size_t	i;

	i = 0;
	while (str[i] && i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_getflag2(const char c, const char before)
{
	if (is_in(c, "cs") == 1)
	{
		if (before == '.')
			return (21);
		return (is_in(c, "s") == 1 ? 1 : 3);
	}
	if (is_in(c, "dixX") == 1)
	{
		if (is_in(c, "di") == 1)
			return (2);
		return(c == 'x' ? 66 : 67);
	}
	if (c == 'p')
		return (10);
	if (c == 'u')
		return (15);
	return (0);
}

int		ft_resetstatic(size_t	*a, size_t	*b)
{
	if (*a)
		*a = 0;
	if (*b)
		*b = 0;
	return (0);
}

int		ft_getflag(const char *str, int restart)
{
	static size_t	i = 0;
	static size_t	percenton = 0;

	if (restart == 1)
		return (ft_resetstatic(&i, &percenton));
//	printf("str[i] : |%s|\n\n", str + i);
	while (str[i])
	{
		if ((str[i] == '%' && str[i + 1] != '%') || percenton == 1)
		{
			percenton = 1;
			i++;
			while (str[i] && is_in(str[i], "cspdiuxX*%") != 1)
				i++;
			// printf("str[i] : |%c|\n\n", str[i]);
			if (str[i] == '*')
				return (i < 9999 ? 2 : 2);
			percenton = 0;
			if (str[i] == '%')
				return (321);
			if (ft_getflag2(str[i], str[i - 1]) != 0)
				return (ft_getflag2(str[i], str[i - 1]));
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			i++;
		if (!str[i++])
			return (0);
	}
	return (0);
}

int		ft_address2(char *addr, const char *str)
{
	long long	tmpa;
	long long	a;

	if (is_in('.', (char *)str) && addr[0] == '0')
	{
		a = ft_geta(str);
		tmpa = a < 0 ? -a : a;
		if (tmpa <= 2)
		{
			write(1, "0x", 2);
			free(addr);
			addr = 0;
			free((char *)str);
			str = 0;
			return (2);
		}
		if (a > 0)
		{
			ft_putspace(a - 2);
			write(1, "0x", 2);
			free(addr);
			addr = 0;
			free((char *)str);
			str = 0;
			return (a);
		}
		write(1, "0x", 2);
		ft_putspace(tmpa - 2);
		free(addr);
		addr = 0;
		free((char *)str);
		str = 0;
		return (tmpa);
	}
	write(1, "0x", 2);
	ft_putstr(addr);
	a = ft_strlen(addr) + 2;
	free(addr);
	addr = 0;
	free((char *)str);
	str = 0;
	return (a);
}

int		ft_address(const char *str, char *container)
{
	char 		*addr;
	long long	a;
	long long	tmpa;
	addr = ft_nbrbase(ft_atoi(container), "0123456789abcdef");
	a = 0;
	if ((is_in('.', (char *)str) && addr[0] == '0') || (ft_strlen((char *)str) == 2))
		return (ft_address2(addr, str));
	a = ft_geta(str);
	tmpa = a < 0 ? -a : a;
	free ((char *)str);
	str = 0;
	if (tmpa <= ft_strlen(addr) + 2)
	{
		write(1, "0x", 2);
		a = ft_strlen(addr) + 2;
		ft_putstr(addr);
		free (addr);
		addr = 0;
		free((char *)str);
		str = 0;
		return (a);
	}
	if (a > 0)
	{
		ft_putspace(a - ft_strlen(addr) - 2);
		write(1, "0x", 2);
		ft_putstr(addr);
		free (addr);
		addr = 0;
		free((char *)str);
		str = 0;
		return (a);
	}
	write(1, "0x", 2);
	ft_putstr(addr);
	ft_putspace(tmpa - ft_strlen(addr) - 2);
	free (addr);
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

__attribute__ ((__format__(printf,1,2)))
int		ft_printf(const char *str, ...)
{
	va_list		arg;
	int			ret;
	char		**args;
	char		*first;
	char		*c;
	size_t		getflag;
	size_t		i;

	va_start(arg, str);
	first = ft_strdup((char *)str);
	va_end(arg);
	if (!(c = malloc(sizeof(char) * 2)))
		return (0);
	if (!(args = malloc(sizeof(char *) * (ft_nbtype(str) + 1))))
	{
		free (c);
		c = 0;
		return (0);
	}
	getflag = ft_getflag(first, 0);
	args[0] = ft_strdup((char *)str);
	va_start(arg, str);
	i = 0;
	while (getflag != 0)
	{
		//printf("ICI|%d|\n", getflag);
		if (getflag != 321)
		{
			if (i == 0)
			{
				free (args[0]);
				args[0] = 0;
			}
			if (getflag == 21)
			{
				str = va_arg(arg, void *);
				args[i] = ft_strdup("HELLO");
			}
			else if (getflag == 1 || getflag == 3)
			{
				if (getflag == 1)
				{
					str = va_arg(arg, const char *);
					if (!str)
						args[i] = ft_strdup("(null)");
					else
						args[i] = ft_strdup((char *)str);
				}
				else
				{
					c[1] = 0;
					c[0] = va_arg(arg, const int);
					str = (char *)c;
					if (c[0] == 0)
						args[i] = ft_strdup("");
					else
						args[i] = ft_strdup((char *)str);
				}
			}
			else if (getflag == 10)
			{
				str = ft_itoa((unsigned long long)va_arg(arg, void *));
				args[i] = ft_strjoin_nos1("", (char *)str);
			}
			else if (getflag == 66 || getflag == 67)
			{
				str = ft_itoa((unsigned int)va_arg(arg, unsigned int));
				if (!str)
					str = ft_strdup("(null)");
				if (getflag == 66)
				{
					str = ft_nbrbase(ft_atoi(str), "0123456789abcdef");
					args[i] = ft_strdup((char *)str);
					free((char *)str);
					str = 0;
				}
				else
				{
					str = ft_nbrbase(ft_atoi(str), "0123456789ABCDEF");
					args[i] = ft_strdup((char *)str);
					free((char *)str);
					str = 0;
				}
			}
			else if (getflag == 15)
			{
				str = ft_itoa(va_arg(arg, unsigned int));
				if (!str)
					str = ft_strdup("(null)");
				args[i] = ft_strdup((char *)str);
				free ((char *)str);
				str = 0;
			}
			else
			{
				str = ft_itoa(va_arg(arg, int));
				if (!str)
					str = ft_strdup("(null)");
				args[i] = ft_strdup((char *)str);
				free ((char *)str);
				str = 0;
			}
			i++;
		}
		getflag = ft_getflag(first, 0);
	}
	if (i == 0)
		free((char *)args[i]);
	args[i] = NULL;
	va_end(arg);
	ret = ft_write(first, args);
	ft_getflag(first, 1);
	ft_flaglist(first, args, 1);
	//---------------FREE---------------------
	i = 0;
	free (c);
	while (args[i])
		free(args[i++]);
	free(args);
	free (first);
	//---------------FREE---------------------
	return (ret);
}

// int main ()
// {
// 	setbuf(stdout, NULL);

// 	int		a = -4;
// 	int		b = 0;
// 	char	c = 'a';
// 	int		d = 2147483647;
// 	int		e = -2147483648;
// 	int		f = 42;
// 	int		g = 25;
// 	int		h = 4200;
// 	int		i = 8;
// 	int		j = -12;
// 	int		k = 123456789;
// 	int		l = 0;
// 	int		m = -12345678;
// 	char	*n = "abcdefghijklmnop";
// 	char	*o = "-a";
// 	char	*p = "-12";
// 	char	*q = "0";
// 	char	*r = "%%";
// 	char	*s = "-2147483648";
// 	char	*t = "0x12345678";
// 	char	*u = "-0";

// 	int		ret;
// 	int 	ret2;
// 	a = 1;

// 	b = -1;
// 	// ft_printf("%*.*X, %*.*u, %*.*x", a, b, l, a, b, m, a, b, m);

// 	//Test 1
// 	//ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
// 	//Test 2
// 	//printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
// 	//Test 3
// 	//printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);

// 	a = 0;
// 	b = -1;

// 	ret2 = printf("V %*.*X\n", a, b, l);
// 	ret = ft_printf("F %*.*X\n", a, b, l);
// 	printf("V : %d|F : %d\n", ret2, ret);
// }
