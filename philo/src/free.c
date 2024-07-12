/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:16:37 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/11 23:10:37 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		mutex_destroy(&data->forks[i]);
		mutex_destroy(&data->philos[i].status);
	}
	free(data->philos);
	free(data->forks);
}
