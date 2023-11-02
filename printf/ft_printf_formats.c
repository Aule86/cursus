/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:21:26 by aszamora          #+#    #+#             */
/*   Updated: 2023/10/18 11:28:14 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_onlychar(int c, int *r)
{
	if (*r == -1)
		return ;
	if (write (1, &c, 1) == -1)
	{
		*r = -1;
		return ;
	}
	*r += 1;
	return ;
}

void	ft_putstr(char *s, int *r)
{
	int	i;
	int	result;

	if (!s)
	{
		ft_putstr("(null)", r);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
		i++;
	result = write(1, s, i);
	if (result == -1)
		*r = -1;
	else
		*r += result;
}

void	ft_putnbr(int n, int *r)
{
	if (n == -2147483648)
	{
		ft_onlychar('-', r);
		ft_onlychar('2', r);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		ft_onlychar('-', r);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, r);
		ft_putnbr(n % 10, r);
	}
	else
	{
		ft_onlychar(n + 48, r);
	}
}

void	ft_putunbr(unsigned int n, int *r)
{
	char	result;

	if (n > 9)
		ft_putunbr(n / 10, r);
	result = (n % 10) + 48;
	ft_onlychar(result, r);
}
