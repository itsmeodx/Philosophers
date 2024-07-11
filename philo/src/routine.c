/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:56:24 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/11 18:23:29 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_mssleep(50);
	while (!philo->data->someone_died || !philo->eaten)
	{
		if (!philo_eat(philo))
			break ;
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
	}
	ft_mssleep(philo->id);
	if (philo->r_locked)
		mutex_unlock(philo->right_fork);
	if (philo->l_locked)
		mutex_unlock(philo->left_fork);
	return (NULL);
}

bool	take_forks(t_philo *philo)
{
	while (mutex_trylock(philo->right_fork) == false
		&& !philo->data->someone_died)
		;
	philo->r_locked = true && !philo->data->someone_died;
	if (!print_status(philo, "has taken a fork"))
		return (false);
	while (mutex_trylock(philo->left_fork) == false
		&& !philo->data->someone_died)
		;
	philo->l_locked = true && !philo->data->someone_died;
	if (!print_status(philo, "has taken a fork"))
		return (false);
	return (true);
}

bool	put_forks(t_philo *philo)
{
	mutex_unlock(philo->left_fork);
	philo->l_locked = false;
	mutex_unlock(philo->right_fork);
	philo->r_locked = false;
	return (true);
}

bool	philo_eat(t_philo *philo)
{
	if (!take_forks(philo))
		return (false);
	if (!print_status(philo, "is eating"))
		return (false);
	philo->last_meal = get_time(philo->data->start);
	ft_mssleep(philo->data->time_to_eat);
	philo->meal_counter++;
	if (philo->meal_counter == philo->data->meals)
	{
		philo->eaten = true;
		philo->data->total_eaten++;
	}
	if (!put_forks(philo))
		return (false);
	return (true);
}

bool	philo_sleep(t_philo *philo)
{
	if (!print_status(philo, "is sleeping"))
		return (false);
	ft_mssleep(philo->data->time_to_sleep);
	return (true);
}

bool	philo_think(t_philo *philo)
{
	if (!print_status(philo, "is thinking"))
		return (false);
	return (true);
}
