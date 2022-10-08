/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:00:47 by gmasid            #+#    #+#             */
/*   Updated: 2022/10/08 18:07:39 by gmasid           ###   ########.fr       */
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
