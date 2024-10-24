/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:54:36 by aszamora          #+#    #+#             */
/*   Updated: 2024/10/08 12:36:23 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	w_status(char *s, t_list *d, int i)
{
	long	time;

	pthread_mutex_lock(&d->mutex_msg);
	time = calc_time() - d->s_time;
	if (i <= d->num_philos && check_eats(d) == 0 && d->stat == 0)
	{
		printf("[%ld][%d]%s", time, i, s);
	}
	pthread_mutex_unlock(&d->mutex_msg);
}

void	ft_take_fork(t_list *d, int i)
{
	pthread_mutex_lock(&d->mutex[d->philo[i].fork_r]);
	w_status("has taken a fork\n", d, i + 1);
	if (d->num_philos == 1)
		ft_usleep(d->time_die + 1);
	pthread_mutex_lock(&d->mutex[d->philo[i].fork_l]);
	w_status("has taken a fork\n", d, i + 1);
}

void	ft_eat(t_list *d, int i)
{
	w_status("is eating\n", d, i + 1);
	d->philo[i].num_eats++;
	ft_usleep(d->time_eat);
	pthread_mutex_unlock(&d->mutex[d->philo[i].fork_l]);
	pthread_mutex_unlock(&d->mutex[d->philo[i].fork_r]);
	pthread_mutex_lock(&d->mutex_last_eat);
	d->philo[i].last_eat = calc_time() - d->s_time;
	pthread_mutex_unlock(&d->mutex_last_eat);
}

void	ft_sleep(t_list *d, int i)
{
	w_status("is sleeping\n", d, i + 1);
	ft_usleep(d->time_sleep);
	w_status("is thinking\n", d, i + 1);
}
