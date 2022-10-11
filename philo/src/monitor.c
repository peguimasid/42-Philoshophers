/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:00:13 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/11 19:49:10 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*must_eat_monitor(void *argv)
{
	t_info	*data;

	data = argv;
	while (!data->finish)
	{
		pthread_mutex_lock(&data->finish_mutex);
		if (data->num_philo_finish_eat == data->num_of_philo)
			data->finish = 1;
		pthread_mutex_unlock(&data->finish_mutex);
	}
	return (NULL);
}

void	*monitor(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		ms;
	unsigned long	dead_time;

	philo = argv;
	while (!philo->global->finish)
	{
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->global->finish_mutex);
		gettimeofday(&now, NULL);
		ms = time_to_ms(now) - time_to_ms(philo->last_meal);
		gettimeofday(&now, NULL);
		if (ms >= philo->global->time_to_die && philo->global->finish == 0)
		{
			dead_time = time_to_ms(now) - time_to_ms(philo->global->created_at);
			printf("%lums\t%d\t %s\n", dead_time, philo->id, "died");
			philo->global->finish = 1;
			exit(0);
		}
		pthread_mutex_unlock(&philo->global->finish_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
	}
	return (NULL);
}
