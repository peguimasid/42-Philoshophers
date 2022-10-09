/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:18:23 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/09 10:20:04 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	data;

	memset(&data, 0, sizeof(data));
	if (!is_valid_args(argc, argv))
		return (throw_error("You provide missing or invalid arguments"));
	parse_args(&data, argc, argv);
	init_philos_threads_and_mutexes(&data);
	join_threads_and_free_data(&data);
}
