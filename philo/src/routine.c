/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:07:02 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/09 10:57:11 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *argv)
{
	t_philo		*philo;
	long long	calc;
	int			left_fork;
	int			right_fork;

	philo = argv;
	pthread_mutex_lock(&philo->global->forks[0]);
	usleep(1000000);
	calc = time_now() - time_to_ms(philo->global->created_at);
	printf("philosopher = %d =>", philo->id);
	left_fork = philo->id - 1;
	right_fork = philo->id % philo->global->num_of_philo;
	printf(" left fork = %d | right fork = %d\n", left_fork, right_fork);
	printf("run after %lldms\n", calc);
	pthread_mutex_unlock(&philo->global->forks[0]);
	return (NULL);
}
