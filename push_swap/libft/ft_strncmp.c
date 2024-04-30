/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:27:36 by aszamora          #+#    #+#             */
/*   Updated: 2023/09/26 13:25:42 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((*(s1 + i) == *(s2 + i)))
	{
		if (i == (n - 1) || *(s1 + i) == '\0' || *(s2 + 1) == '\0')
			break ;
		i++;
	}
	return ((unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}

/*int	main(void)
{
	char s1[] = "cola!";
	char s2[] = "cdios";

	printf("%d", ft_strncmp(s1, s2, 5));
}
*/