/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:00:13 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/10 15:04:33 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		ms;

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
			printf("%lu\t%d\t %s\n",
					time_to_ms(now) - time_to_ms(philo->global->created_at),
					philo->id,
					"died");
			philo->global->finish = 1;
		}
		pthread_mutex_unlock(&philo->global->finish_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
	}
	return (NULL);
}
