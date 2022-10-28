/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:43:04 by hasabir           #+#    #+#             */
/*   Updated: 2022/09/26 13:37:50 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# define L_MAX 9223372036854775807
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <time.h>
# include <string.h>
# include <unistd.h>

struct s_data
{
	int				number_of_philosophers;
	int				number_of_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	output;
};

typedef struct s_data	t_parameters;
struct s_philo
{
	int				id;
	long			time_of_meal;
	int				eat_log;
	t_parameters	*data;
	pthread_mutex_t	mutex;
} ;

typedef struct s_philo	t_philo;
int						ft_atoi(const char *str);
int						ft_error(void);
t_parameters			*set_default_thread(int ac, char **av);
void					creat_philosopher(t_parameters *data, t_philo **philo);
void					creat_thread(t_parameters *data,
							pthread_t *philosopher_id, t_philo **philo);
void					*set_philo(void *thread);
int						get_time(void);
void					think(t_philo *philo);
void					take_forks(t_philo *philo);
void					ft_sleep(t_philo *philo);
void					eat(t_philo *philo);
void					ft_usleep(int time, long current_time);
int						ft_kill(t_philo *philo, long current_time);
int						check_death(t_parameters *data, t_philo **philo);

#endif
