/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aule86 <aule86@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:32:40 by aule86            #+#    #+#             */
/*   Updated: 2024/07/10 13:37:23 by aule86           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

static void	copy_env(char **env_copy, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		env_copy[i] = ft_strdup(envp[i]);
		if (env_copy[i] == NULL)
		{
			perror("strdup");
			exit(1);
		}
		i++;
	}
	env_copy[i] = NULL;
}

void	init_shell(t_shell *shell, char **envp)
{
	int	env_count;

	env_count = count_env(envp);
	shell->env_copy = malloc(sizeof(char *) * (env_count + 1));
	if (!shell->env_copy)
	{
		perror("malloc");
		exit(1);
	}
	copy_env(shell->env_copy, envp);
}