/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:35:27 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/20 16:13:47 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	right_left(t_philo *philo)
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

bool	left_right(t_philo *philo)
{
	while (mutex_trylock(philo->left_fork) == false
		&& !philo->data->someone_died)
		;
	philo->l_locked = true && !philo->data->someone_died;
	if (!print_status(philo, "has taken a fork"))
		return (false);
	while (mutex_trylock(philo->right_fork) == false
		&& !philo->data->someone_died)
		;
	philo->r_locked = true && !philo->data->someone_died;
	if (!print_status(philo, "has taken a fork"))
		return (false);
	return (true);
}

bool	take_forks(t_philo *philo)
{
	if (philo->right_fork > philo->left_fork)
	{
		if (!right_left(philo))
			return (false);
	}
	else
	{
		if (!left_right(philo))
			return (false);
	}
	return (true);
}

bool	put_forks(t_philo *philo)
{
	mutex_unlock(philo->right_fork);
	philo->r_locked = false;
	mutex_unlock(philo->left_fork);
	philo->l_locked = false;
	return (true);
}
