/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 18:18:15 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/28 18:22:14 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_compute(char const *s, char **ret, char c, int *i, int *x);

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (s)
	{
		ret = ft_memalloc(ft_strlen(s) + 1);
		if (ret)
		{
			ret[0] = NULL;
			ret[ft_strlen(s) + 1] = NULL;
			ft_compute(s, ret, c, &i, &x);
			return (ret);
		}
	}
	return (NULL);
}

static void	ft_compute(char const *s, char **ret, char c, int *i, int *x)
{
	int		len;
	int		start;

	len = 0;
	start = 0;
	while (s[*i] != 0)
	{
		start = *i;
		len = 0;
		if (s[*i] == c)
		{
			(*i)++;
			start++;
		}
		else
		{
			while (s[*i] != c && s[*i] != 0)
			{
				len++;
				(*i)++;
			}
			ret[*x] = ft_strsub(s, start, len);
			(*x)++;
		}
	}
}
