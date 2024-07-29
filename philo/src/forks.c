/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:35:27 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/27 11:28:41 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	right_left(t_philo *philo)
{
	while (!philo->r_locked && !philo->data->someone_died)
		philo->r_locked = mutex_trylock(philo->right_fork);
	if (philo->data->someone_died)
		return (false);
	mutex_lock(&philo->data->print);
	if (philo->data->someone_died || philo->eaten)
		return (mutex_unlock(&philo->data->print), false);
	printf(TAKE, get_time(philo->data->start), philo->id);
	mutex_unlock(&philo->data->print);
	while (!philo->l_locked && !philo->data->someone_died)
		philo->l_locked = mutex_trylock(philo->left_fork);
	if (philo->data->someone_died)
		return (false);
	mutex_lock(&philo->data->print);
	if (philo->data->someone_died || philo->eaten)
		return (mutex_unlock(&philo->data->print), false);
	printf(TAKE, get_time(philo->data->start), philo->id);
	return (true);
}

bool	left_right(t_philo *philo)
{
	while (!philo->l_locked && !philo->data->someone_died)
		philo->l_locked = mutex_trylock(philo->left_fork);
	if (philo->data->someone_died)
		return (false);
	mutex_lock(&philo->data->print);
	if (philo->data->someone_died || philo->eaten)
		return (mutex_unlock(&philo->data->print), false);
	printf(TAKE, get_time(philo->data->start), philo->id);
	mutex_unlock(&philo->data->print);
	while (!philo->r_locked && !philo->data->someone_died)
		philo->r_locked = mutex_trylock(philo->right_fork);
	if (philo->data->someone_died)
		return (false);
	mutex_lock(&philo->data->print);
	if (philo->data->someone_died || philo->eaten)
		return (mutex_unlock(&philo->data->print), false);
	printf(TAKE, get_time(philo->data->start), philo->id);
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
