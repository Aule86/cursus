/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:47:04 by aszamora          #+#    #+#             */
/*   Updated: 2023/11/30 13:14:31 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_nl(char *static_buff)
{
	unsigned int	i;

	if (!static_buff)
		return (-1);
	i = 0;
	while (static_buff[i] != '\n' && static_buff[i] != '\0')
		i++;
	if (static_buff[i] == '\0')
		return (-1);
	return (i);
}

char	*ft_finish_line(char *static_buff, int len)
{
	char	*line;
	int		i;

	line = (char *)malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (static_buff[i] != '\n')
	{
		line[i] = static_buff[i];
		i++;
	}
	line[i] = '\n';
	line [i + 1] = '\0';
	return (line);
}

char	*ft_line(char *static_buff)
{
	char	*line;
	int		len;

	if (ft_strlen(static_buff) <= 0)
		return (NULL);
	len = ft_find_nl(static_buff);
	if (len == -1 || len == ((int)ft_strlen(static_buff) - 1))
	{
		line = ft_strdup(static_buff);
		return (line);
	}
	line = ft_finish_line(static_buff, len);
	return (line);
}

char	*ft_static_buff(char *static_buff)
{
	int				i;
	unsigned int	len;

	if (!static_buff)
		return (NULL);
	len = ft_strlen(static_buff);
	i = ft_find_nl(static_buff);
	if (i == -1 || ((len - i) == 1))
	{
		free(static_buff);
		return (NULL);
	}
	static_buff = ft_substr(static_buff, (i + 1), (len - i - 1));
	return (static_buff);
}

char	*get_next_line(int fd)
{
	static char	*static_buff[4096];
	char		*buffer;
	char		*line;
	int			bytes;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE +1);
	bytes = 1;
	while (ft_find_nl(static_buff[fd]) == -1 && buffer)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		read_error(&static_buff[fd], &buffer, bytes);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		static_buff[fd] = ft_strjoin(static_buff[fd], buffer);
	}
	free(buffer);
	if (bytes == -1 || !static_buff[fd])
		return (NULL);
	line = ft_line(static_buff[fd]);
	static_buff[fd] = ft_static_buff(static_buff[fd]);
	return (line);
}

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;
	int		i;

	if (argc < 3)
		return (1);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		return (1);
	fd2 = open(argv[2], O_RDONLY);
	if (fd2 == -1)
		return (close(fd1), 1);
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd1);
		if (line != NULL)
		{
			printf("Linea fichero 1 %d: %s", i, line);
			free(line);
		}
		line = get_next_line(fd2);
		if (line != NULL)
		{
			printf("Linea fichero 2 %d: %s", i, line);
			free(line);
		}
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}