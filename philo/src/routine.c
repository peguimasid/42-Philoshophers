/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:07:02 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/09 11:18:27 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *argv)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = argv;
	if (philo->id % 2)
		usleep(philo->global->time_to_eat * 1000);
	left_fork = philo->id - 1;
	right_fork = philo->id % philo->global->num_of_philo;
	pthread_mutex_lock(&philo->global->forks[left_fork]);
	pthread_mutex_lock(&philo->global->forks[right_fork]);
	usleep(1000000);
	printf("philosopher = %d =>", philo->id);
	printf(" left fork = %d | right fork = %d\n", left_fork, right_fork);
	printf("run after %lums\n", current_time(philo));
	pthread_mutex_unlock(&philo->global->forks[left_fork]);
	pthread_mutex_unlock(&philo->global->forks[right_fork]);
	return (NULL);
}
