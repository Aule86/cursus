/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:47:26 by aszamora          #+#    #+#             */
/*   Updated: 2023/11/28 11:12:21 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s )
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*r;
	int		len;
	int		i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	r = (char *) malloc((len + 1) * sizeof(char));
	if (!r)
	{
		free(r);
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*r;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
	{
		free(r);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		r[i] = s[start];
		start++;
		i++;
	}
	r[i] = '\0';
	free((char *)s);
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	len1;
	unsigned int	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	while (i++ < len1)
		res[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < len2)
		res[i - 1 + len1] = s2[i - 1];
	res[i - 1 + len1] = '\0';
	free((char *)s1);
	return (res);
}

void	read_error(char **static_buff, char **buffer, int bytes)
{
	if (bytes == -1)
	{
		free(*static_buff);
		free(*buffer);
		*static_buff = NULL;
		*buffer = NULL;
	}
}
