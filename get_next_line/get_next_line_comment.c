/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:24:50 by aszamora          #+#    #+#             */
/*   Updated: 2023/11/09 15:49:16 by aszamora         ###   ########.fr       */
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

char	*ft_finish_line(char *static_buff, int i)
{
	char	*line;
	int		y;

	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	y = 0;
	/*bucle hasta que llegue al salto de linea y copiamos el contenido
	 de static_buff en la linea */
	{
		line[y] = static_buff[y];
		y++;
	}
	/*en la posicion y añadiremos el salto de linea y en la siguiente
	el \0, para despues retornar la linea*/
	line[y] = '\n';
	line [y + 1] = '\0';
	return (line);
}

char	*ft_line(char *static_buff)
{
	char	*line;
	int		i;

	if (ft_strlen(static_buff) <= 0)
		return (NULL);
	i = ft_find_nl(static_buff);
	/*con el i == -1 buscamos si hay un caracter de nueva linea, en ese caso se copiara
	el contenido de static_buff en linea con ft_strdup.
	con el i == ((int)ft_strlen(static_buff) - 1)) verificamos si el caracter de nueva linea
	es el ultimo, eso quiere decir que la linea actual esta en final del buffer y no hay mas datos
	despues y se copiara el static_buffer en line y se devolvera.
	*/
	if (i == -1 || i == ((int)ft_strlen(static_buff) - 1))
	{
		line = ft_strdup(static_buff);
		return (line);
	}
	line = ft_finish_line(static_buff, i);
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
	/*en caso que no se encuentre caracter de nueva linea o caracter de nueva linea
	es el ultimo caracter, se libera la memoria y retorna null*/
	if (i == -1 || ((len - i) == 1))
	{
		free(static_buff);
		return (NULL);
	}
	/*si no se cumple ninguno de los casos anteriores 
	(habra caracter de salto de linea en medio) se usara ft_substr
	para crear un nuevo buffer estatico con los datos restantes */
	static_buff = ft_substr(static_buff, (i + 1), (len - i - 1));
	return (static_buff);
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
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		static_buff = ft_strjoin(static_buff, buffer);
	}
	free(buffer);
	if (bytes == -1)
		return (NULL);
	line = ft_line(static_buff);
	static_buff = ft_static_buff(static_buff);
	return (line);
}
