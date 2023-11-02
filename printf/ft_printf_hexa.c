/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:49:08 by aszamora          #+#    #+#             */
/*   Updated: 2023/10/17 16:31:37 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
}

void	ft_puthex(unsigned int n, const char str, int *r)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, str, r);
		ft_puthex(n % 16, str, r);
	}
	else
	{
		if (n <= 9)
			ft_onlychar(n + 48, r);
		else
		{
			if (str == 'x')
				ft_onlychar(n - 10 + 'a', r);
			if (str == 'X')
				ft_onlychar(n - 10 + 'A', r);
		}
	}
}

void	ft_puthexa(unsigned int n, const char str, int *r)
{
	if (n == 0)
		ft_onlychar('0', r);
	else
		ft_puthex(n, str, r);
	hex_len(n);
}
