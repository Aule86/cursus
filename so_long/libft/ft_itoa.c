/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:24:06 by aszamora          #+#    #+#             */
/*   Updated: 2023/10/06 18:46:23 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_digits(int n)
{
	int	r;

	r = 0;
	if (n < 0)
	{
		r++;
		n = n * -1;
	}
	else if (n == 0)
		return (1);
	while ((unsigned int)n > 0)
	{
		r++;
		n = (unsigned int)n / 10;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		digits;

	digits = ft_digits(n);
	r = malloc((digits + 1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	if (n == 0)
		r[0] = 48;
	if (n < 0)
	{
		r[0] = '-';
		n = n * -1;
	}
	r[digits] = '\0';
	while ((digits - 1) >= 0 && (unsigned int) n > 0)
	{
		r[digits - 1] = ((unsigned int)n % 10) + 48;
		n = (unsigned int)n / 10;
		digits--;
	}
	return (r);
}

/*int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
}
*/