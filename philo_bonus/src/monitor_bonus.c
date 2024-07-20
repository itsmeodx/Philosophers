/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:11:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/18 20:42:34 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	run_monitor(t_philo *philo)
{
	if (pthread_create(&philo->monitor, NULL, &monitor, philo) != 0)
		return (printf("Error: pthread_create\n"), false);
	return (true);
}

void	check_philo(t_philo *philo)
{
	long	elapsed_time;

	if (philo->died || philo->eaten)
		return ;
	ft_mssleep(1);
	elapsed_time = get_time(philo->data->start) - philo->last_meal;
	if (elapsed_time > philo->data->time_to_die && !philo->eaten)
	{
		philo->died = true;
		sem_wait(philo->data->print);
		philo->data->printing = printf("%ld %d died\n",
				get_time(philo->data->start), philo->id);
	}
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->died && !philo->eaten)
	{
		check_philo(philo);
		if (philo->died || philo->eaten)
			break ;
		ft_mssleep(100);
	}
	return (NULL);
}
