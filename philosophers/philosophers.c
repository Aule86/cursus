/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:54:15 by aszamora          #+#    #+#             */
/*   Updated: 2024/10/14 12:10:02 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	cleanup_values(t_list *d)
{
	int	i;

	pthread_mutex_destroy(&d->mutex_i);
	pthread_mutex_destroy(&d->mutex_msg);
	pthread_mutex_destroy(&d->mutex_fork);
	if (d->mutex)
	{
		i = 0;
		while (i < d->num_philos)
		{
			pthread_mutex_destroy(&d->mutex[i]);
			i++;
		}
		free(d->mutex);
	}
	if (d->philo)
		free(d->philo);
	if (d->thread)
		free(d->thread);
}

static int	check_num_arg(char *num_arg, int i, t_list *d)
{
	int	n;

	n = ft_atoi(num_arg);
	if (!n || n < 0 || (i == 1 && n > 200) || (i == 2 && n < 60)
		|| (i == 3 && n < 60) || (i == 4 && n < 60))
	{
		free(d);
		write(1, "Incorrect number.\n", 19);
		return (-1);
	}
	else
	{
		if (i == 1)
			d->num_philos = n;
		if (i == 2)
			d->time_die = n;
		if (i == 3)
			d->time_eat = n;
		if (i == 4)
			d->time_sleep = n;
		if (i == 5)
			d->philo_eats = n;
		return (n);
	}
}

static	int	start_simulation(t_list *d)
{
	pthread_mutex_init(&d->mutex_last_eat, NULL);
	pthread_mutex_init(&d->mutex_stat, NULL);
	d->stat = 0;
	d->id = 1;
	if (init_values(d) == -1)
		return (-1);
	if (create_mutex(d) == -1)
		return (-1);
	d->s_time = calc_time();
	if (create_thread(d) == -1)
		return (-1);
	d->init_philo = 1;
	main_checker(d);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*d;

	if (argc != 5 && argc != 6)
	{
		write(1, "Invalid arg num.\n", 18);
		return (0);
	}
	i = 1;
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	while (i != argc)
	{
		if (check_num_arg(argv[i], i, d) < 0)
			return (0);
		i++;
	}
	if (start_simulation(d) != 0)
		return (-1);
	cleanup_values(d);
	free(d);
	return (0);
}
