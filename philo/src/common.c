/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:11 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/13 14:18:11 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_usage(void)
{
	return (throw_error("Usage: ./philo <num_of_philo> <time_to_die> <time_to_eat> \
<time_to_sleep> [num_times_philo_should_sleep]"));
}

int	throw_error(char *error)
{
	printf("\033[0;31m\n");
	printf("Error\n%s\n", error);
	printf("\033[0m");
	return (0);
}

void	print_msg(t_philo *philo, char *str)
{
	long long	ms;

	pthread_mutex_lock(&philo->global->finish_mutex);
	ms = time_now() - philo->global->created_at;
	if (!philo->global->finish)
		printf("%lldms\t%d\t %s\n", ms, philo->id, str);
	pthread_mutex_unlock(&philo->global->finish_mutex);
}
