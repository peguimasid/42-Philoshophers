/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:18:23 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/06 14:36:39 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		result *= 10;
		result += *nptr++ - '0';
	}
	return (result * sign);
}

int	is_valid_info(t_info *info, int argc)
{
	if (argc == 6 && info->num_times_must_eat <= 0)
		return (throw_error("Wrong num of must eat"));
	if (info->num_of_philo < 0)
		return (throw_error("Wrong num of philo"));
	if (info->time_to_die < 0)
		return (throw_error("Wrong time to die"));
	if (info->time_to_eat < 0)
		return (throw_error("Wrong time to eat"));
	if (info->time_to_sleep < 0)
		return (throw_error("Wrong time to sleep"));
	return (1);
}

int	parse_info(t_info *info, int argc, char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_times_must_eat = ft_atoi(argv[5]);
	return (1);
}

int	init(t_info *info, int argc, char **argv)
{
	parse_info(info, argc, argv);
	if (!is_valid_info(info, argc))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	memset(&info, 0, sizeof(info));
	if (argc != 5 && argc != 6)
		return (print_usage());
	if (!init(&info, argc, argv))
	{
		throw_error("You must send valid values");
		return (1);
	}
	// --------------
	printf("%d", info.num_of_philo);
	printf("%d", info.time_to_die);
	printf("%d", info.time_to_eat);
	printf("%d", info.time_to_sleep);
	printf("%d", info.num_times_must_eat);
}
