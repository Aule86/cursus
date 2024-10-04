/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aszamora <aszamora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:54:02 by aszamora          #+#    #+#             */
/*   Updated: 2024/10/04 10:54:03 by aszamora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
