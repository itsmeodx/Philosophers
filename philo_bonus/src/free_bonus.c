/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:16:37 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/12 21:54:44 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
		sem_destroy(&data->philos[i].status);
	free(data->philos);
	free(data->pids);
	sem_destroy(&data->forks);
	sem_destroy(&data->someone_died);
	sem_destroy(&data->print);
}
