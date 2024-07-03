/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:43:10 by aszamora          #+#    #+#             */
/*   Updated: 2023/10/06 10:10:18 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	const char		*str1;
	char			*str2;

	i = 0;
	str1 = (char *)src;
	str2 = dst;
	while (i < n && (src || dst))
	{
		str2[i] = str1[i];
		i++;
	}
	return (dst);
}
