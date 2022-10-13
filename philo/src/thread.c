/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:04:10 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/13 13:36:07 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_threads_and_free_data(t_info *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(data->threads[i], NULL);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->threads);
	free(data->philos);
	free(data->forks);
}

void	initialize_mutexes(t_info *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->finish_mutex, NULL);
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philos[i].check_mutex, NULL);
		i++;
	}
}

void	create_and_run_threads(t_info *data)
{
	int			i;
	pthread_t	thread;

	i = 0;
	data->created_at = time_now();
	while (i < data->num_of_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].global = data;
		pthread_create(&data->threads[i], NULL, routine, data->philos + i);
		data->philos[i].last_meal = time_now();
		pthread_create(&thread, NULL, monitor, data->philos + i);
		pthread_detach(thread);
		i++;
	}
	if (data->num_times_must_eat != 0)
		must_eat_monitor(data);
}

void	init_philos_threads_and_mutexes(t_info *data)
{
	data->philos = malloc(sizeof(t_info) * data->num_of_philo);
	data->threads = malloc(sizeof(pthread_t) * data->num_of_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	initialize_mutexes(data);
	create_and_run_threads(data);
}
