/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 07:25:54 by bmoulin           #+#    #+#             */
/*   Updated: 2021/02/05 14:51:52 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strjoin_nos2(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (i <= (size_t)(ft_strlen(s1)) && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (j <= (size_t)(ft_strlen(s2)) && s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free(s2);
	free(s1);
	return (dest);
}

static char		*ft_nbrbase2(unsigned long long dec, char *base, t_nbr *nbr)
{
	nbr->result = dec / nbr->lenbase;
	nbr->i = dec - (nbr->lenbase * nbr->result) == 0 ? nbr->i - 1 : nbr->i;
	if (dec - (nbr->lenbase * nbr->result) != 0)
	{
		nbr->c[0] = base[dec - (nbr->lenbase * nbr->result)];
		nbr->tab = ft_strjoin_nos1(&nbr->c[0], nbr->tab);
	}
	nbr->tab[nbr->i] = 0;
	return (nbr->tab);
}

char			*ft_nbrbase(unsigned long long dec, char *base)
{
	t_nbr		nbr;

	if ((long)dec == -9223372036854775807)
		return (ft_strdup("8000000000000000"));
	nbr.lenbase = ft_strlen(base);
	nbr.result = nbr.lenbase;
	nbr.i = 1;
	nbr.c[1] = '\0';
	if (!(nbr.tab = malloc(sizeof(char))))
		return (NULL);
	nbr.tab[0] = 0;
	while (nbr.result >= nbr.lenbase)
	{
		nbr.result = dec / nbr.lenbase;
		nbr.c[0] = base[dec - (nbr.lenbase * nbr.result)];
		nbr.tab = ft_strjoin_nos1(&nbr.c[0], nbr.tab);
		dec = nbr.result;
		nbr.i++;
	}
	return (ft_nbrbase2(dec, base, &nbr));
}

int				is_in(char content, char *tofind)
{
	size_t	i;

	i = 0;
	if (!tofind)
		return (0);
	while (tofind[i])
	{
		if (tofind[i] == content)
			return (1);
		i++;
	}
	return (0);
}

int				ft_nbargs(const char *str)
{
	size_t	i;
	size_t	nbargs;

	i = 0;
	nbargs = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			while (str[i] && (str[i] == '-'
				|| str[i] == '0' || str[i] == '.' || str[i] == '*'))
				i++;
			if (str[i] && is_in(str[i], "cspdiuxX%") == 1)
				nbargs++;
		}
		i++;
	}
	return (nbargs);
}
