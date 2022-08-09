/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:50:12 by bbali             #+#    #+#             */
/*   Updated: 2022/08/09 05:48:40 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void static	init_args(t_params *params, int ac, char **av)
{
	params->nb_of_philos = ft_atoi(av[1]);
	params->time_to_die = ft_atoi(av[2]);
	params->time_to_eat = ft_atoi(av[3]);
	params->time_to_sleep = ft_atoi(av[4]);
}

int	main(int ac, char **av)
{
	t_params	params;
	// TODO check negative number
	if (!check_args(ac, av))
	{
		write(STDERR_FILENO, "nb of philo | time to die | time to eat | time to sleep | \
[optional: number of times each philosopher must eat]\n", 112);
		return (0);
	}
	init_args(&params, ac, av);
	return (0);
}
