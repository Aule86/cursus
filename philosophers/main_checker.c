/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:54:19 by aszamora          #+#    #+#             */
/*   Updated: 2024/10/04 10:54:20 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"

int	check_eats(t_list *d)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (!d->philo_eats)
		return (0);
	while (++i < d->num_philos)
	{
		if (d->philo[i].num_eats >= d->philo_eats)
			j++;
		else
			break ;
	}
	if (j >= d->num_philos)
	{
		d->stat = 2;
		return (1);
	}
	return (0);
}

static void	ft_print_die(long t, int c)
{
	printf("[%ld][%d]died\n", t, c);
}

void	ft_free(t_list *d)
{
	int	i;

	i = 0;
	while (++i <= d->num_philos)
		pthread_mutex_destroy(&d->mutex[i]);
	i = 0;
	if (d->num_philos == 1)
		pthread_detach(d->thread[i]);
	else
	{
		while (++i <= d->num_philos)
			pthread_detach(d->thread[i]);
	}
}

void	main_checker(t_list *d)
{
	int		c;
	long	t;

	c = -1;
	while (d->stat == 0)
	{
		while (++c < d->num_philos)
		{
			t = calc_time() - d->s_time;
			if (t - d->philo[c].last_eat > d->time_die || check_eats(d) == 1)
			{
				if (d->stat == 2)
				{
					break ;
				}
				d->stat = 1;
				ft_print_die(t, c + 1);
				break ;
			}
		}
		c = -1;
	}
	ft_free(d);
}
