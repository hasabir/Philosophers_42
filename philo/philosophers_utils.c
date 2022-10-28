/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:38:47 by hasabir           #+#    #+#             */
/*   Updated: 2022/09/17 16:57:23 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_time(void)
{
	struct timeval	current_time;
	static long		old_time;
	long			time;

	gettimeofday(&current_time, NULL);
	if (!old_time)
		old_time = current_time.tv_usec / 1000 + current_time.tv_sec * 1000;
	time = (current_time.tv_usec / 1000 + current_time.tv_sec * 1000)
		- old_time;
	if (time < 0)
		time *= -1;
	return (time);
}

void	ft_usleep(int time, long data_time)
{
	int	current_time;

	data_time = get_time();
	time = data_time + time;
	current_time = 0;
	while (current_time < time)
	{
		usleep(100);
		current_time = get_time();
	}
	return ;
}

int	ft_kill(t_philo *philo, long current_time)
{
	pthread_mutex_lock(&philo->data->output);
	printf("%lu philosopher %d is dead\n",
		current_time, philo->id);
	return (-1);
}
