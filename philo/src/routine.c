/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:07:02 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/09 14:50:28 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_msg(t_philo *philo, char *str)
{
	long long		ms;
	struct timeval	now;

	pthread_mutex_lock(&philo->global->finish_mutex);
	gettimeofday(&now, NULL);
	ms = time_to_ms(now) - time_to_ms(philo->global->created_at);
	if (!philo->global->finish)
		printf("%lldms\t%d\t %s\n", ms, philo->id, str);
	pthread_mutex_unlock(&philo->global->finish_mutex);
}

void	pickup_forks(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->global->num_of_philo;
	pthread_mutex_lock(&philo->global->forks[right_fork]);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(&philo->global->forks[left_fork]);
	print_msg(philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	long long	ms;
	int			left_fork;
	int			right_fork;

	left_fork = philo->id - 1;
	right_fork = philo->id % philo->global->num_of_philo;
	pthread_mutex_lock(&philo->check_mutex);
	gettimeofday(&philo->last_meal, NULL);
	ms = time_to_ms(philo->last_meal) - time_to_ms(philo->global->created_at);
	pthread_mutex_lock(&philo->global->finish_mutex);
	if (!philo->global->finish)
		printf("%lldms\t%d\t %s\n", ms, philo->id, "is eating");
	philo->ate_times++;
	if (philo->ate_times == philo->global->num_times_must_eat)
		philo->global->num_philo_finish_eat++;
	pthread_mutex_unlock(&philo->global->finish_mutex);
	usleep(philo->global->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->global->forks[right_fork]);
	pthread_mutex_unlock(&philo->global->forks[left_fork]);
	pthread_mutex_unlock(&philo->check_mutex);
}

void	sleeping(t_philo *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->global->time_to_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	print_msg(philo, "is thinking");
}

void	*routine(void *argv)
{
	t_philo	*philo;

	philo = argv;
	if (philo->id % 2)
		usleep(philo->global->time_to_eat * 1000);
	while (!philo->global->finish)
	{
		pickup_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
