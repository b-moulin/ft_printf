/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 09:17:49 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/07 14:18:38 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_ptf
{
	int				ret;
	char			**args;
	char			*first;
	char			*c;
	size_t			getflag;
	size_t			i;
}					t_ptf;

typedef	struct		s_nbr
{
	long long		lenbase;
	long long		result;
	char			*tab;
	char			c[2];
	size_t			i;
}					t_nbr;

typedef	struct		s_star
{
	size_t			j;
	char			*newstr;
}					t_star;

typedef	struct		s_wr
{
	size_t			i;
	size_t			nb_write;
	char			*malstr;
}					t_wr;

typedef	struct		s_at
{
	long long		i;
	short int		k;
	long long		value;
}					t_at;

int					ft_stopmalloc(const char *newstr, char **container);
char				*ft_removelastchar(char *src);
int					ft_thereispoint(const char *str);
char				*ft_joinptr(char *s1, char s2);
char				*ft_replacestar2(const char *str, char *newstr, size_t j);
char				*ft_replacestar3(const char *str,
						char *newstr, size_t **i);
char				*ft_replacestar4(const char *str,
						char *ctnr, size_t j, char *ns);
int					ft_starin(const char *str);
int					ft_star(const char *str);
int					ft_nbargsttwo3(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo4(const char *str,
						char **container, size_t **i);
int					ft_retzero2b2(const char *str,
						char **container, size_t **i);
int					ft_getafterp(const char *str);
int					ft_flagx(const char *str,
						char **container, size_t **i, int j);
int					ft_flagzero(const char *str);
int					ft_ptnotset2b(const char *str,
						char **container, size_t **i);
int					ft_flagdouble6(const char *str,
						char **container, size_t **i);
int					ft_printf(const char
						*str, ...) __attribute__((__format__(printf,1,2)));
int					ft_freeargs(char *str);
int					ft_sba2(const char *str,
						char **container, size_t **i);
int					ft_sba2b(const char *str,
						char **container, size_t **i);
int					ft_sba2b2(const char *str,
						char **container, size_t **i);
long long			ft_strlen(char *str);
char				*ft_strdup(char *s1);
char				*ft_strjoin_nos1(char *s1, char *s2);
char				*ft_nbrbase(unsigned long long dec, char *base);
int					is_in(char content, char *tofind);
int					ft_nbargs(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_itoa(long long n);
char				*ft_strjoin(char *s1, char *s2);
int					ft_write(const char *str, char **container);
void				ft_putstr(const char *str);
int					ft_flaglist(const char *str, char **container, int reset);
long long			ft_atoi(const char *str);
int					ft_getafterp(const char *str);
void				ft_putstr_len(const char *str, const size_t	len);
char				*ft_strnstr(const char *str, const char *find, size_t len);
int					ft_getaftert(const char *str);
int					ft_flag4(const char *str,
						char **container, size_t **i, int j);
int					ft_getafterp(const char *str);
int					ft_flag3(const char *str,
						char **container, size_t **i);
int					ft_flag2(const char *str,
						char **container, size_t **i);
int					ft_flagdouble(const char *str,
						char **container, size_t **i);
int					ft_geta(const char *str);
int					ft_getb(const char *str);
char				ft_rettype(const char *str);
int					ft_sab(const char *str,
						char **container, size_t **i);
int					ft_putspace(long long nb);
int					ft_sba(const char *str,
						char **container, size_t **i);
int					ft_flag5(const char *str, char **container, size_t **i);
char				*ft_returnflag(const char *str);
int					ft_replacestar(const char *str,
						char **container, size_t **i);
int					ft_percflag(const char *str);
int					ft_prctzero(const char *str, int two);
int					ft_prctwo(const char *str);
int					ft_address(const char *str, char *container);
int					ft_putzerob(long long nb);
int					ft_starin(const char *str);
int					ft_getprcta(const char *str);
char				*ft_retptr(const char c);
int					ft_resetstatic(size_t	*a, size_t	*b);
int					ft_valuept(const char *str, int tofree);
int					ft_valuept2(const char *str);
int					ft_dflag3r(const char *str, char *container, size_t **i);
int					ft_dflag3(const char *str, char *container, size_t **i);
char				*ft_b(const char *str, char **container, size_t **i);
int					ft_putspaced(const char *str, char **container, size_t **i);
int					ft_putzero(const char *str, char **container, size_t **i);
int					ft_ptnotset(const char *str, char **container, size_t **i);
int					ft_flagdouble2(const char *str,
						char **container, size_t **i);
void				ft_flagdouble3(const char *str,
						char **container, size_t **i);
int					ft_flagdouble4(const char *str,
						char **container, size_t **i);
int					ft_flagdouble5(const char *str,
						char **container, size_t **i);
int					ft_flagdouble6(const char *str,
						char **container, size_t **i);
int					ft_flagdouble7(const char *str,
						char **container, size_t **i);
int					ft_flagdouble8(const char *str,
						char **container, size_t **i);
int					ft_flagdouble(const char *str,
						char **container, size_t **i);
int					ft_retzero2(const char *str, char **container, size_t **i);
int					ft_retzero(const char *str, char **container, size_t **i);
int					ft_retun2(const char *str, char **container, size_t **i);
int					ft_retun3(const char *str, char **container, size_t **i);
int					ft_retun(const char *str, char **container, size_t **i);
int					ft_getaftert(const char *str);
int					ft_nbargsttwo2(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo3(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo4(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo5(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo6(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo7(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo8(const char *str,
						char **container, size_t **i);
void				ft_nbargsttwo9(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo10(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo11(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo12(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo13(const char *str,
						char **container, size_t **i);
int					ft_flag4neg(const char *str,
						char **container, size_t **i);
int					ft_flag4(const char *str,
						char **container, size_t **i, int j);
int					ft_ismalloc(void **str);
char				*ft_substr(char const *s,
						unsigned int start, size_t len, int tofree);
char				*ft_joinptr(char *s1, char s2);
int					ft_nomallocdflag3(const char *str,
						char *container, size_t **i);
char				*ft_strjoin_nos2(char *s1, char *s2);
int					thereisnullb(const char *str);
char				*ft_replacestarb2(const char *str,
						char **container, size_t **i, t_star *star);
char				*ft_replacestarb(const char *str,
						char **container, size_t **i, t_star *star);
void				ft_nbargsttwo14(const char *str,
						char **container, size_t **i);
int					ft_nbargsttwo2(const char *str,
						char **container, size_t **i);
int					ft_resetstatic(size_t *a, size_t *b);
int					ft_getflag2(const char c, const char before);
void				ft_putstr(const char *str);
void				ft_putstr_len(const char *str, const size_t len);
int					ft_nbtype(const char *str);
int					ft_address(const char *str, char *container);
int					ft_addressb(char *addr, const char *str);
int					ft_address2(char *addr, const char *str);
int					ft_address2b(char *addr, const char *str);
int					ft_getflag(const char *str, int restart);
int					ft_getflagb(const char *str, size_t i);
void				ft_ptf(t_ptf *ptf, va_list arg, const char *str);
void				ft_ptf2(t_ptf *ptf, va_list arg, const char *str);
int					ft_freeargs2(char *str, int ret);

#endif
