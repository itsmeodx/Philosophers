/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:16:37 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/29 13:39:44 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	if (data->philos)
		while (++i < data->philo_count)
		{
			sem_unlink(data->philos[i].name);
			sem_close(data->philos[i].status);
			free(data->philos[i].name);
		}
	free(data->philos);
	free(data->pids);
	sem_unlink("forks");
	sem_close(data->forks);
	sem_unlink("print");
	sem_close(data->print);
	sem_unlink("killall");
	sem_close(data->killall);
	sem_unlink("exitted");
	sem_close(data->exitted);
	sem_unlink("starting");
	sem_close(data->starting);
	free(data);
}
