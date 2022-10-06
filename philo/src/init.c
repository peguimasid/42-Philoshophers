/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:00:47 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/06 15:40:09 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_valid_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (print_usage());
	i = 1;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]) || (!ft_atoi(argv[i])))
			return (0);
		i++;
	}
	return (1);
}

void	init_args(t_info *info, int argc, char **argv)
{
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_times_must_eat = ft_atoi(argv[5]);
}
