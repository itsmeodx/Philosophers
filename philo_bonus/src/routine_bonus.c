/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:56:24 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/26 20:23:55 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->died && !philo->eaten)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	sem_post(philo->data->exitted);
	return (NULL);
}

bool	philo_eat(t_philo *philo)
{
	sem_wait(philo->right_fork);
	sem_wait(philo->data->print);
	printf(TAKE, get_time(philo->data->start), philo->id);
	sem_post(philo->data->print);
	sem_wait(philo->left_fork);
	sem_wait(philo->data->print);
	printf(TAKE, get_time(philo->data->start), philo->id);
	printf(EAT, get_time(philo->data->start), philo->id);
	sem_post(philo->data->print);
	sem_wait(philo->status);
	philo->last_meal = get_time(philo->data->start);
	usleep(philo->data->time_to_eat * 1000);
	philo->meal_counter++;
	if (philo->meal_counter == philo->data->meals)
		philo->eaten = true;
	sem_post(philo->status);
	sem_post(philo->right_fork);
	sem_post(philo->left_fork);
	return (true);
}

bool	philo_sleep(t_philo *philo)
{
	if (philo->eaten)
		return (true);
	sem_wait(philo->data->print);
	printf(SLEEP, get_time(philo->data->start), philo->id);
	sem_post(philo->data->print);
	usleep(philo->data->time_to_sleep * 1000);
	return (true);
}

bool	philo_think(t_philo *philo)
{
	if (philo->eaten)
		return (true);
	sem_wait(philo->data->print);
	printf(THINK, get_time(philo->data->start), philo->id);
	sem_post(philo->data->print);
	usleep(1 * 1000);
	return (true);
}
