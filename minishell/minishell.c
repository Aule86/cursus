/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:24:27 by aule86            #+#    #+#             */
/*   Updated: 2024/07/10 13:43:02 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\nminishell> ", 12);
}

void	setup_shell(t_shell *shell, char **envp)
{
	shell->envp = envp;
	init_shell(shell, envp);
	signal(SIGINT, handle_signal);
}

void	cleanup_shell(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env_copy[i] != NULL)
	{
		free(shell->env_copy[i]);
		i++;
	}
	free(shell->env_copy);
}

void	process_command(t_shell *shell)
{
	if (ft_strncmp(shell->buffer, "exit", 4) == 0
		&& shell->buffer[4] == '\0')
		exit(0);
	shell->argv = parse_command(shell->buffer);
	if (shell->argv[0] != NULL)
	{
		if (ft_strncmp(shell->argv[0], "env", 3) == 0
			&& shell->argv[0][3] == '\0')
			env_command(shell);
		else
			execute_command(shell);
	}
	free(shell->argv);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	setup_shell(&shell, envp);
	while (1)
	{
		read_command(&shell);
		process_command(&shell);
	}
	cleanup_shell(&shell);
	return (0);
}
