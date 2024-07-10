/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:30:05 by aule86            #+#    #+#             */
/*   Updated: 2024/07/08 13:14:01 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parse_command(char *buffer)
{
	char	**argv;
	int		i;

	argv = ft_split(buffer, ' ');
	if (argv == NULL)
	{
		perror("split");
		exit(1);
	}
	i = 0;
	while (argv[i] != NULL)
	{
		argv[i] = ft_strtrim(argv[i], " ");
		i++;
	}
	return (argv);
}
