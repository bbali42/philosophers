/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:56:46 by bbali             #+#    #+#             */
/*   Updated: 2022/08/09 05:47:30 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	digit_len(char *str, int offset)
{
	int		i;

	i = 0;
	while (str[offset + i])
		i++;
	return (i);
}

static int	ft_strdigit_cmp(char *str, int offset, char *str_nb)
{
	if (digit_len(str, offset) > INT_MAX_LEN)
		return (1);
	else if (digit_len(str, offset) == INT_MAX_LEN)
	{
		while (offset)
		{
			str++;
			offset--;
		}
		while (*str && *str_nb && (*str == *str_nb))
		{
			str++;
			str_nb++;
		}
		return (*(unsigned char *)str - *(unsigned char *)str_nb);
	}
	return (0);
}

static int	int_overflow(char **av)
{
	char	sign;
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = 0;
		sign = '+';
		if (av[i][j] == '-' || av[i][j] == '+')
		{
			if (av[i][j] == '-')
				sign = '-';
			j++;
		}
		while (av[i][j] == '0')
				j++;
		if (sign == '+' && ft_strdigit_cmp(av[i], j, INT_MAX) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int		i;

	if (ac != 5 && ac != 6)
		return (0);
	if (int_overflow(av))
		return (0);
	return (1);
}
