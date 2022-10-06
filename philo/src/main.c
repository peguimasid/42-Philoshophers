/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:18:23 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/06 15:01:14 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	memset(&info, 0, sizeof(info));
	if (argc != 5 && argc != 6)
		return (print_usage());
	if (!parse(&info, argc, argv))
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
