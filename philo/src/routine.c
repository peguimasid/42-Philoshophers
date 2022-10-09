/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:07:02 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/09 10:12:15 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *argv)
{
	t_philo			*philo;
	struct timeval	now;
	long long		calc;

	philo = argv;
	pthread_mutex_lock(&philo->global->forks[2]);
	usleep(1000000);
	gettimeofday(&now, NULL);
	calc = time_to_ms(now) - time_to_ms(philo->global->created_at);
	printf("thread num = %d\n", philo->id);
	printf("run after %lldms\n", calc);
	pthread_mutex_unlock(&philo->global->forks[2]);
	return (NULL);
}