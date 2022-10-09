/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:04:10 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/09 10:12:30 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_and_free_threads(t_info *data)
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

void	create_and_run_threads(t_info *data)
{
	int	i;

	i = 0;
	// pthread_mutex_init(&data->forks[2], NULL);
	while (i < data->num_of_philo)
	{
		data->philos[i].id = i;
		data->philos[i].global = data;
		pthread_create(&data->threads[i], NULL, routine, data->philos + i);
		i++;
	}
}

void	init_philos_threads_and_mutexes(t_info *data)
{
	gettimeofday(&data->created_at, NULL);
	data->philos = malloc(sizeof(t_info) * data->num_of_philo);
	data->threads = malloc(sizeof(pthread_t) * data->num_of_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	create_and_run_threads(data);
}