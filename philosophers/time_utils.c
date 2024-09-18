
#include "philosophers.h"

long	calc_time(void)
{
	struct timeval	time;
	long			actual_time;

	gettimeofday(&time, NULL);
	actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (actual_time);
}

void	ft_usleep(int condition)
{
	long	start;

	start = calc_time();
	while (calc_time() - start < condition)
	{
		usleep(condition / 2);
	}
}
