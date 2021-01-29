/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:17:49 by bmoulin           #+#    #+#             */
/*   Updated: 2021/01/29 09:40:53 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_nbr
{
	long long		lenbase;
	long long		result;
	char			*tab;
	char			c[2];
	size_t			i;
}					t_nbr;

int					ft_printf(const char *str, ...);
size_t				ft_strlen(char *str);
char				*ft_strdup(char *s1);
char				*ft_strjoin_nos1(char *s1, char *s2);
char				*ft_nbrbase(unsigned long long dec, char *base);
int					is_in(char content, char *tofind);
int					ft_nbargs(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_itoa(long long n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
int					ft_write(const char *str, char **container);
void				ft_putstr(const char *str);
int					ft_flaglist(const char *str, char **container, int reset);
long long			ft_atoi(const char *str);
int					ft_getafterp(const char *str);
void				ft_putstr_len(const char *str, const size_t	len);
char				*ft_strnstr(const char *str, const char *find, size_t len);
int					ft_getaftert(const char *str);
int					ft_flag4(const char *str, char **container, size_t **i, int j);
int					ft_getafterp(const char *str);
int					ft_flag3(const char *str, char **container, size_t **i);
int					ft_flag2(const char *str, char **container, size_t **i);
int					ft_flagdouble(const char *str, char **container, size_t **i);
int					ft_geta(const char *str);
int					ft_getb(const char *str);
char				ft_rettype(const char *str);
int					ft_sab(const char *str, char **container, size_t **i);
int					ft_putspace(unsigned long nb);
int					ft_sba(const char *str, char **container, size_t **i);
int					ft_flag5(const char *str, char **container, size_t **i);
char				*ft_returnflag(const char *str);
int					ft_replacestar(const char *str, char **container, size_t **i);
int					ft_percflag(const char *str);
int					ft_prctzero(const char *str, int two);
int					ft_prctwo(const char *str);
int					ft_address(const char *str, char *container);
int					ft_putzerob(unsigned long nb);
int					ft_starin(const char *str);
int					ft_getprcta(const char *str);
char				*ft_retptr(const char c);
int					ft_resetstatic(size_t	*a, size_t	*b);
int					ft_valuept(const char *str);
int					ft_valuept2(const char *str);
int					ft_dflag3r(const char *str, char *container, size_t **i);
int					ft_dflag3(const char *str, char *container, size_t **i);
char				*ft_b(const char *str, char **container, size_t **i);
int					ft_putspaced(const char *str, char **container, size_t **i);
int					ft_putzero(const char *str, char **container, size_t **i);
int					ft_ptnotset(const char *str, char **container, size_t **i);
int					ft_flagdouble2(const char *str, char **container, size_t **i);
void				ft_flagdouble3(const char *str, char **container, size_t **i);
int					ft_flagdouble4(const char *str, char **container, size_t **i);
int					ft_flagdouble5(const char *str, char **container, size_t **i);
int					ft_flagdouble6(const char *str, char **container, size_t **i);
int					ft_flagdouble7(const char *str, char **container, size_t **i);
int					ft_flagdouble8(const char *str, char **container, size_t **i);
int					ft_flagdouble(const char *str, char **container, size_t **i);
int					ft_retzero2(const char *str, char **container, size_t **i);
int					ft_retzero(const char *str, char **container, size_t **i);
int					ft_retun2(const char *str, char **container, size_t **i);
int					ft_retun3(const char *str, char **container, size_t **i);
int					ft_retun(const char *str, char **container, size_t **i);
int					ft_getaftert(const char *str);
int					ft_nbargsttwo2(const char *str, char **container, size_t **i);
int					ft_nbargsttwo3(const char *str, char **container, size_t **i);
int					ft_nbargsttwo4(const char *str, char **container, size_t **i);
int					ft_nbargsttwo5(const char *str, char **container, size_t **i);
int					ft_nbargsttwo6(const char *str, char **container, size_t **i);
int					ft_nbargsttwo7(const char *str, char **container, size_t **i);
int					ft_nbargsttwo8(const char *str, char **container, size_t **i);
void				ft_nbargsttwo9(const char *str, char **container, size_t **i);
int					ft_nbargsttwo10(const char *str, char **container, size_t **i);
int					ft_nbargsttwo11(const char *str, char **container, size_t **i);
int					ft_nbargsttwo12(const char *str, char **container, size_t **i);
int					ft_nbargsttwo13(const char *str, char **container, size_t **i);
int					ft_flag4neg(const char *str, char **container, size_t **i);
int					ft_flag4(const char *str, char **container, size_t **i, int j);
int					ft_ismalloc(void **str);

#endif

// static char		*ft_nbrbase2(unsigned long long dec, char *base, t_nbr *nbr)
// {
// 	nbr->result = dec / nbr->lenbase;
// 	nbr->i = dec - (nbr->lenbase * nbr->result) == 0 ? nbr->i - 1 : nbr->i;
// 	if (dec - (nbr->lenbase * nbr->result) != 0)
// 	{
// 		nbr->c[0] = base[dec - (nbr->lenbase * nbr->result)];
// 		nbr->tab = ft_strjoin_nos1(&nbr->c[0], nbr->tab);
// 	}
// 	nbr->tab[nbr->i] = 0;
// 	return (nbr->tab);
// }

// char		*ft_nbrbase(unsigned long long dec, char *base)
// {
// 	t_nbr		nbr;

// 	if (dec == -9223372036854775807)
// 		return (ft_strdup("8000000000000000"));
// 	nbr.lenbase = ft_strlen(base);
// 	nbr.result = nbr.lenbase;
// 	nbr.i = 1;
// 	nbr.c[1] = '\0';
// 	if (!(nbr.tab = malloc(sizeof(char))))
// 		return (NULL);
// 	nbr.tab[0] = 0;
// 	while (nbr.result >= nbr.lenbase)
// 	{
// 		nbr.result = dec / nbr.lenbase;
// 		nbr.c[0] = base[dec - (nbr.lenbase * nbr.result)];
// 		nbr.tab = ft_strjoin_nos1(&nbr.c[0], nbr.tab);
// 		dec = nbr.result;
// 		nbr.i++;
// 	}
// 	return (ft_nbrbase2(dec, base, &nbr));
// }