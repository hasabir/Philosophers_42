/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_states.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:38:00 by hasabir           #+#    #+#             */
/*   Updated: 2022/09/26 13:28:57 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->output);
	printf("%d philosopher %d has taken a fork\n",
		get_time(), philo->id);
	pthread_mutex_unlock(&philo->data->output);
	return ;
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	if (philo->data->times_must_eat != -2)
		philo->eat_log++;
	philo->time_of_meal = get_time();
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_lock(&philo->data->output);
	printf("%d philosopher %d is eating\n",
		get_time(), philo->id);
	pthread_mutex_unlock(&philo->data->output);
	ft_usleep(philo->data->time_to_eat, get_time());
	return ;
}

void	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->output);
	printf("%d philosopher %d is sleeping\n",
		get_time(), philo->id);
	pthread_mutex_unlock(&philo->data->output);
	ft_usleep(philo->data->time_to_sleep, get_time());
	return ;
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->output);
	printf("%d philosopher %d is thinking\n",
		get_time(), philo->id);
	pthread_mutex_unlock(&philo->data->output);
	return ;
}

int	check_death(t_parameters *data, t_philo **philo)
{
	int		i;
	int		current_time_of_meal;
	long	current_time;

	i = -1;
	while (1)
	{
		while (++i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&philo[i]->mutex);
			current_time = get_time();
			current_time_of_meal = current_time - philo[i]->time_of_meal;
			if (current_time_of_meal >= data->time_to_die)
				return (ft_kill(philo[i], current_time));
			else if (philo[i]->eat_log == data->times_must_eat)
				return (-1);
			pthread_mutex_unlock(&philo[i]->mutex);
		}
		usleep(150);
		i = -1;
	}
	return (0);
}
