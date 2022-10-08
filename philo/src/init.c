/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:00:47 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/08 19:17:17 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	parse_args(t_info *data, int argc, char **argv)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_times_must_eat = ft_atoi(argv[5]);
}

void	*routine(t_philo *philo)
{
	printf("thread num = %d\n", philo->id);
	return (NULL);
}

void	create_and_run_threads(t_info *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		data->philos[i].id = i;
		pthread_create(&data->threads[i], NULL, (void *)routine, data->philos
				+ i);
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

void	init_data(t_info *data, int argc, char **argv)
{
	parse_args(data, argc, argv);
	init_philos_threads_and_mutexes(data);
}
