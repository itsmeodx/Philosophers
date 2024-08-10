/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:56:24 by oouaadic          #+#    #+#             */
/*   Updated: 2024/08/10 13:32:49 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_mssleep(50);
	while (!philo->data->someone_died && !philo->eaten)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	if (philo->r_locked)
		mutex_unlock(philo->right_fork);
	if (philo->l_locked)
		mutex_unlock(philo->left_fork);
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	if (!take_forks(philo))
		return ;
	if (philo->data->someone_died || philo->eaten)
		return (mutex_unlock(&philo->data->print), (void)false);
	printf(EAT, get_time(philo->data->start), philo->id);
	mutex_unlock(&philo->data->print);
	mutex_lock(&philo->status);
	philo->last_meal = get_time(philo->data->start);
	ft_mssleep(philo->data->time_to_eat);
	philo->meal_counter++;
	if (philo->meal_counter == philo->data->meals)
	{
		philo->eaten = true;
		philo->data->total_eaten++;
	}
	mutex_unlock(&philo->status);
	mutex_unlock(philo->right_fork);
	philo->r_locked = false;
	mutex_unlock(philo->left_fork);
	philo->l_locked = false;
	return ;
}

void	philo_sleep(t_philo *philo)
{
	mutex_lock(&philo->data->print);
	if (philo->data->someone_died || philo->eaten)
		return (mutex_unlock(&philo->data->print), (void)false);
	printf(SLEEP, get_time(philo->data->start), philo->id);
	mutex_unlock(&philo->data->print);
	ft_mssleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	mutex_lock(&philo->data->print);
	if (philo->data->someone_died || philo->eaten)
		return (mutex_unlock(&philo->data->print), (void)false);
	printf(THINK, get_time(philo->data->start), philo->id);
	mutex_unlock(&philo->data->print);
	usleep(500);
}
