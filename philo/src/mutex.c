/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:51:39 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/11 16:50:44 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	mutex_init(t_mutex *mutex)
{
	if (pthread_mutex_init(&mutex->mutex, NULL) != 0)
		return (false);
	return (mutex->locked = false, true);
}

bool	mutex_destroy(t_mutex *mutex)
{
	if (mutex->locked == true)
		return (false);
	return (pthread_mutex_destroy(&mutex->mutex), true);
}

bool	mutex_lock(t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->mutex);
	return (mutex->locked = true, true);
}

bool	mutex_trylock(t_mutex *mutex)
{
	if (mutex->locked == true)
		return (false);
	pthread_mutex_lock(&mutex->mutex);
	return (mutex->locked = true, true);
}

bool	mutex_unlock(t_mutex *mutex)
{
	if (mutex->locked == false)
		return (false);
	return (pthread_mutex_unlock(&mutex->mutex), mutex->locked = false, true);
}
