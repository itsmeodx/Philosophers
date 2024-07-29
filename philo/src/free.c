/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:16:37 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/29 13:38:20 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		if (data->forks)
			mutex_destroy(&data->forks[i]);
		if (data->philos)
			mutex_destroy(&data->philos[i].status);
	}
	mutex_destroy(&data->print);
	free(data->philos);
	free(data->forks);
	free(data);
}
