/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:57:34 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/13 14:19:24 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + time.tv_usec / 1000);
}

unsigned long	time_diff(unsigned long past, unsigned long pres)
{
	return (pres - past);
}

void	smart_sleep(unsigned long time, t_philo *philo)
{
	unsigned long	start;

	start = time_now();
	while (!(philo->global->finish))
	{
		if (time_diff(start, time_now()) >= time)
			break ;
		usleep(50);
	}
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
