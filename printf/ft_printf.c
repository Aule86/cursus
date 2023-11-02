/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:00:01 by aszamora          #+#    #+#             */
/*   Updated: 2023/10/18 11:29:13 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_formats(va_list args, const char str, int *r)
{
	if (*r == -1)
		return ;
	if (str == 'c')
		ft_onlychar(va_arg(args, int), r);
	else if (str == 'u')
		ft_putunbr(va_arg(args, unsigned int), r);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(args, unsigned int), r);
	else if (str == 's')
		ft_putstr(va_arg(args, char *), r);
	else if (str == 'p')
		ft_adress(va_arg(args, unsigned long int), r);
	else if (str == 'x' || str == 'X')
		ft_puthexa(va_arg(args, unsigned long int), str, r);
	else if (str == '%')
		ft_onlychar('%', r);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	int				r;

	i = 0;
	r = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			ft_formats(args, str[i + 1], &r);
			i++;
		}
		else
			ft_onlychar(str[i], &r);
		i++;
	}
	va_end(args);
	return (r);
}

/*int	main(void)
{
	printf("%")

}
*/