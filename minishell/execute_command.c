/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:25:53 by aule86            #+#    #+#             */
/*   Updated: 2024/07/10 13:31:56 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_shell *shell)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(shell->argv[0], shell->argv, shell->envp) == -1)
			perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		waitpid(pid, NULL, 0);
	else
		perror("fork");
}
