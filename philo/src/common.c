/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:11 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/05 17:43:34 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_usage(void)
{
	return (throw_error("Usage: ./philo <num_of_philo> <time_to_die> <time_to_eat> \
<time_to_sleep> [num_times_philo_should_sleep]"));
}

int	throw_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		i++;
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, i);
	write(STDERR_FILENO, "\n", 1);
	return (1);
}
