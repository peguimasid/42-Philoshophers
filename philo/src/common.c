/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:32:11 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/12 12:11:51 by gmasid           ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += *str++ - '0';
	}
	return (result * sign);
}

int	ft_isnum(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
