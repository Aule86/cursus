/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:24:27 by aule86            #+#    #+#             */
/*   Updated: 2024/07/03 13:32:19 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
			perror("execvp");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
	}
	else
	{
		perror("fork");
	}
}

char	**parse_command(char *buffer)
{
	int		argc;
	char	**argv;
	char	*token;

	argc = 0;
	argv = (char **)malloc(BUFFER_SIZE * sizeof(char *));
	if (!argv)
		return (NULL);
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;
	return (argv);
}

void	read_command(char *buffer)
{
	printf("minishell>");
	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		buffer[strcspn(buffer, "\n")] = '\0';
}

int	main(int ac, char **av, char **env)
{
	char	buffer[BUFFER_SIZE];
	char	**argv;

	(void)ac;
	(void)av;
	while (1)
	{
		read_command(buffer);
		if (strcmp(buffer, "exit") == 0)
			break ;
		argv = parse_command(buffer);
		if (argv[0] != NULL)
			execute_command(argv, env);
		free(argv);
	}
	return (0);
}
