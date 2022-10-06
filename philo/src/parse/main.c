/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:00:47 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/06 15:00:50 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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

int	parse(t_info *info, int argc, char **argv)
{
	parse_info(info, argc, argv);
	if (!is_valid_info(info, argc))
		return (0);
	return (1);
}
