/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:00:47 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/09 15:56:53 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_positive(char *num)
{
	if (ft_atoi(num) > 0)
		return (1);
	return (0);
}

int	is_valid_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (print_usage());
	i = 1;
	while (argv[i])
	{
		if (!ft_isnum(argv[i]) || !is_positive(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parse_args(t_info *data, int argc, char **argv)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_times_must_eat = ft_atoi(argv[5]);
}
