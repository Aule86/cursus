/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:18:39 by aule86            #+#    #+#             */
/*   Updated: 2024/07/10 13:26:09 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_command(t_shell *shell)
{
	int	len;

	printf("minishell> ");
	if (fgets(shell->buffer, BUFFER_SIZE, stdin) != NULL)
	{
		len = 0;
		while (shell->buffer[len] != '\0')
		{
			if (shell->buffer[len] == '\n')
			{
				shell->buffer[len] = '\0';
				break ;
			}
			len++;
		}
	}
}