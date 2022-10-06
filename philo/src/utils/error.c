/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:11 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/06 15:05:34 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	print_usage(void)
{
	throw_error("Usage: ./philo <num_of_philo> <time_to_die> <time_to_eat> \
<time_to_sleep> [num_times_philo_should_sleep]");
	return (1);
}

int	throw_error(char *error)
{
	printf("\033[0;31m\n");
	printf("Error\n%s\n", error);
	printf("\033[0m");
	return (0);
}
