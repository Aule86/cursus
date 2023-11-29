/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:10:54 by aszamora          #+#    #+#             */
/*   Updated: 2023/10/06 10:41:56 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;
	int		len;
	int		i;

	len = ft_strlen(s1);
	r = (char *) malloc((len + 1) * sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

/*int	main(void)
{
	char s1[] = "hola que tal";

	printf("%s\n", s1);
}
*/