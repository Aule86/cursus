
#include "philosophers.h"

int	create_mutex(t_list *d)
{
	int	i;

	i = -1;
	while (++i < d->num_philos)
	{
		if (pthread_mutex_init(&d->mutex[i], NULL) != 0)
			return (-1);
	}
	return (0);
}

int	create_thread(t_list *d)
{
	int	i;

	i = -1;
	while (++i < d->num_philos)
	{
		pthread_mutex_lock(&d->mutex_last_eat);
		d->philo[i].last_eat = 0;
		pthread_mutex_unlock(&d->mutex_last_eat);
		if (pthread_create(&d->thread[i], NULL, &philo_routine, (void *)d) != 0)
			return (-1);
	}
	return (0);
}
