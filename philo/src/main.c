/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:18:23 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/08 18:01:56 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_things(t_info *data)
{
	printf(">> %d\n", data->num_of_philo);
	printf(">> %d\n", data->time_to_die);
	printf(">> %d\n", data->time_to_eat);
	printf(">> %d\n", data->time_to_sleep);
	printf(">> %d\n", data->num_times_must_eat);
}

int	main(int argc, char **argv)
{
	t_info	data;

	memset(&data, 0, sizeof(data));
	if (!is_valid_args(argc, argv))
		return (throw_error("You provide missing or invalid arguments"));
	init_data(&data, argc, argv);
	print_things(&data);
	// TODO: Join and free
}
