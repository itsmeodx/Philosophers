/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:28:14 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/25 18:02:31 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	ft_sem_open(sem_t **sem, t_string name, int value)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (*sem == SEM_FAILED)
		return (false);
	return (true);
}

bool	ft_sem_trywait(sem_t *sem)
{
	_Atomic static long int	sval;

	sval = sem->__align;
	if (sval == 0)
		return (false);
	sem_wait(sem);
	return (true);
}

long int	ft_sem_getvalue(sem_t *sem)
{
	_Atomic static long int	sval;

	sval = sem->__align;
	return (sval);
}
