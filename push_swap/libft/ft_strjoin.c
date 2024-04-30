/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:43:55 by aszamora          #+#    #+#             */
/*   Updated: 2023/09/22 14:19:42 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_join(char const *s1, char const *s2, char *r)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		r[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		r[j] = s2[i];
		i++;
		j++;
	}
	r[j] = '\0';
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	r = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (r == NULL)
		return (NULL);
	r = ft_join(s1, s2, r);
	return (r);
}

/*int	main(void)
{
	char const	s1[] = "hola";
	char const	s2[] = "que tal";

	printf("%s", ft_strjoin(s1, s2));
}
*/