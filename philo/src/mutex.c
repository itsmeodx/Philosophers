/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:51:39 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/20 15:46:50 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	mutex_init(t_mutex *mutex)
{
	if (pthread_mutex_init(&mutex->mutex, NULL) != 0)
		return (false);
	mutex->locked = false;
	return (true);
}

bool	mutex_destroy(t_mutex *mutex)
{
	if (mutex->locked == true)
		return (false);
	pthread_mutex_destroy(&mutex->mutex);
	return (true);
}

bool	mutex_lock(t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->mutex);
	pthread_mutex_lock(&mutex->lock);
	mutex->locked = true;
	pthread_mutex_unlock(&mutex->lock);
	return (true);
}

bool	mutex_trylock(t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->lock);
	if (mutex->locked == true)
		return (pthread_mutex_unlock(&mutex->lock), false);
	mutex->locked = true;
	pthread_mutex_unlock(&mutex->lock);
	pthread_mutex_lock(&mutex->mutex);
	return (true);
}

bool	mutex_unlock(t_mutex *mutex)
{
	pthread_mutex_lock(&mutex->lock);
	if (mutex->locked == false)
		return (pthread_mutex_unlock(&mutex->lock), false);
	mutex->locked = false;
	pthread_mutex_unlock(&mutex->lock);
	pthread_mutex_unlock(&mutex->mutex);
	return (true);
}
