/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:51:47 by aszamora          #+#    #+#             */
/*   Updated: 2023/10/18 11:32:02 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	len_adress(unsigned long int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
}

void	ft_put_adress(unsigned long int n, int *r)
{
	if (n >= 16)
	{
		ft_put_adress(n / 16, r);
		ft_put_adress(n % 16, r);
	}
	else
	{
		if (n <= 9)
			ft_onlychar(n + 48, r);
		else
			ft_onlychar(n - 10 + 'a', r);
	}
}

void	ft_adress(unsigned long int n, int *r)
{
	int	result;

	result = 0;
	ft_onlychar('0', r);
	ft_onlychar('x', r);
	if (n == 0)
		ft_onlychar('0', r);
	else
	{
		ft_put_adress(n, r);
		len_adress(n);
	}
}
