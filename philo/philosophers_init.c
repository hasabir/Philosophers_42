/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:17:10 by hasabir           #+#    #+#             */
/*   Updated: 2022/09/26 13:22:43 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	creat_philosopher(t_parameters *data, t_philo **philo)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (!philo[i])
			return ;
		philo[i]->data = data;
		philo[i]->id = i + 1;
		philo[i]->time_of_meal = 0;
		philo[i]->eat_log = -1;
		pthread_mutex_init(&philo[i]->mutex, NULL);
		pthread_mutex_init(&philo[i]->data->forks[i], NULL);
		i++;
	}
	return ;
}

void	creat_thread(t_parameters *data, pthread_t *id, t_philo **philo)
{
	int	i;

	pthread_mutex_init(&data->output, NULL);
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		if (pthread_create(&id[i], NULL, &set_philo,
				(void *)philo[i]) != 0)
			return ;
		usleep(100);
	}
	return ;
}

t_parameters	*set_default_thread(int ac, char **av)
{
	t_parameters	*thread;

	thread = (t_parameters *)malloc(sizeof(t_parameters));
	if (!thread)
		return (NULL);
	thread->number_of_philosophers = ft_atoi(av[1]);
	thread->time_to_die = ft_atoi(av[2]);
	thread->time_to_eat = ft_atoi(av[3]);
	thread->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		thread->times_must_eat = ft_atoi(av[5]);
	else
		thread->times_must_eat = -2;
	thread->number_of_forks = thread->number_of_philosophers;
	thread->forks = malloc(sizeof(pthread_mutex_t) * thread->number_of_forks);
	if (!thread->forks)
		return (NULL);
	return (thread);
}
