/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:17:57 by aszamora          #+#    #+#             */
/*   Updated: 2023/11/07 14:25:49 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_nl(char *static_buff)
{
	unsigned int	i;

	if (!static_buff)
		return (-1);
	i = 0;
	while (static_buff[i] != '\0' && static_buff[i] != '\n')
		i++;
	if (static_buff[i] == '\0')
		return (-1);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*static_buff;
	char		*buffer;
	char		*line;
	int			bytes;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE +1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (ft_find_nl(static_buff) == -1)
	{
		bytes = read (fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		static_buff = ft_strjoin(static_buff, buffer);
	}
	free(buffer);
	if (bytes == -1)
		return (NULL);
}
