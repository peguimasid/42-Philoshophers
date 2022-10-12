/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:57:34 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/12 12:11:55 by gmasid           ###   ########.fr       */
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

unsigned long	time_now(void)
{
	struct timeval	time;
	unsigned long	l;
	unsigned long	s;
	unsigned long	u;

	gettimeofday(&time, NULL);
	s = time.tv_sec * 1000;
	u = time.tv_usec / 1000;
	l = s + u;
	return (l);
}

unsigned long	time_to_ms(struct timeval now)
{
	unsigned long	ms;

	ms = now.tv_sec * 1000;
	ms += now.tv_usec / 1000;
	return (ms);
}
