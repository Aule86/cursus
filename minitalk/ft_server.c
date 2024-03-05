/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:46:37 by aszamora          #+#    #+#             */
/*   Updated: 2024/03/04 11:47:04 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binary_text(int signum)
{
	static int	byte;
	static int	i;

	if (signum == SIGUSR1)
		byte |= (0x01 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", byte);
		i = 0;
		byte = 0;
	}
}

void	get_pid(void)
{
	int	pid;

	pid = getpid();
	if (pid == 0)
		ft_printf("PID has not been generated\n");
	else
		ft_printf("PID is: %i\n", pid);
}

int	main(void)
{
	get_pid();
	ft_printf("Waiting...\n");
	while (1)
	{
		signal(SIGUSR1, binary_text);
		signal(SIGUSR2, binary_text);
		pause();
	}
	return (0);
}
