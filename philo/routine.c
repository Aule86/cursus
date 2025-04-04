/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:53:54 by aszamora          #+#    #+#             */
/*   Updated: 2024/10/08 12:36:51 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	death_philo(t_list *d)
{
	int		c;
	long	time;

	c = -1;
	while (++c < d->num_philos)
	{
		time = calc_time() - d->s_time;
		if (time - d->philo[c].last_eat > d->time_die)
		{
			if (d->stat == 0)
			{
				d->stat = 1;
				printf("[%ld][%d]died\n", time, c + 1);
			}
			return (1);
		}
	}
	return (0);
}

int	routine(t_list *d)
{
	int	i;

	pthread_mutex_lock(&((t_list *)d)->mutex_i);
	i = d->id - 1;
	d->id++;
	pthread_mutex_unlock(&((t_list *)d)->mutex_i);
	if (i % 2 == 0)
		ft_usleep(d->time_eat / 2);
	while (d->stat == 0 || death_philo(d) == 0)
	{
		pthread_mutex_lock(&((t_list *)d)->mutex_fork);
		ft_take_fork((t_list *)d, i);
		pthread_mutex_unlock(&((t_list *)d)->mutex_fork);
		ft_eat((t_list *)d, i);
		ft_sleep((t_list *)d, i);
		if (d->num_philos % 2 != 0)
			ft_usleep(d->time_sleep / 3);
	}
	return (0);
}

void	*philo_routine(void *f)
{
	t_list	*d;

	d = (t_list *)f;
	while (d->init_philo == 0)
	{
		usleep(10);
	}
	if (routine(d) == -1)
		return (NULL);
	return (NULL);
}
