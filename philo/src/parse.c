/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:50:36 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/11 17:59:32 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	parse_args(t_data *data, int ac, char *av[])
{
	data->philo_count = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals = ft_atoi(av[5]);
	else
		data->meals = -1;
	if (data->philo_count < 1 || data->philo_count > 200
		|| data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60 || (ac == 6 && data->meals < 1))
		return (printf("Error: invalid numbers\n"), false);
	if (!data_init(data))
		return (false);
	if (!philo_init(data))
		return (false);
	return (true);
}
