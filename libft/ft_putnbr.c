/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguirrie <sguirrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:43:24 by sguirrie          #+#    #+#             */
/*   Updated: 2013/11/27 20:18:18 by sguirrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0 && n > -2147483648)
	{
		ft_putchar(45);
		n = n * -1;
		ft_putnbr(n);
	}
	if (n == -2147483648)
	{
		ft_putchar(45);
		ft_putnbr(214748364);
		ft_putchar('8');
	}
	else
	{
		if (n > 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
			ft_putchar(n + 48);
	}
}
