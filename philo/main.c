/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:22:34 by hasabir           #+#    #+#             */
/*   Updated: 2022/09/26 13:25:02 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*set_philo(void *thread)
{
	t_philo	*philo;

	philo = (t_philo *)thread;
	while (1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		take_forks(philo);
		pthread_mutex_lock(&philo->data->forks[philo->id
			% philo->data->number_of_forks]);
		take_forks(philo);
		eat(philo);
		pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->id
			% philo->data->number_of_forks]);
		ft_sleep(philo);
		think(philo);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_parameters	*data;
	pthread_t		*philosopher_id;
	void			**philo;

	if (ac != 5 && ac != 6)
		return (ft_error());
	data = set_default_thread(ac, av);
	if (!data)
		return (1);
	philosopher_id = (pthread_t *)malloc(data->number_of_philosophers
			* sizeof(pthread_t));
	if (!philosopher_id)
		return (1);
	philo = malloc(sizeof(t_philo) * data->number_of_philosophers);
	if (!philo)
		return (1);
	creat_philosopher(data, (t_philo **)philo);
	creat_thread(data, philosopher_id, (t_philo **)philo);
	if (check_death(data, (t_philo **)philo) == -1)
		return (0);
	return (0);
}
