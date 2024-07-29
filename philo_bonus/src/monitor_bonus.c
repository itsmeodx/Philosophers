/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:11:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/27 12:03:33 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor(void *arg)
{
	t_philo	*philo;
	long	elapsed_time;

	philo = (t_philo *)arg;
	while (!philo->died && !philo->eaten)
	{
		sem_wait(philo->status);
		elapsed_time = get_time(philo->data->start) - philo->last_meal;
		if (elapsed_time > philo->data->time_to_die && !philo->eaten
			&& !philo->died)
		{
			philo->died = true;
			sem_wait(philo->data->print);
			printf(DIED, get_time(philo->data->start), philo->id);
			sem_post(philo->data->killall);
			sem_post(philo->status);
			return (false);
		}
		sem_post(philo->status);
		usleep(9 * MS);
	}
	return (NULL);
}
