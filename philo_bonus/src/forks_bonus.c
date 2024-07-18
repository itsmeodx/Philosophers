/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:35:27 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/18 17:16:02 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	take_forks(t_philo *philo)
{
	int	sval;

	sem_wait(philo->right_fork);
	sem_getvalue(philo->right_fork, &sval);
	philo->r_locked = true;
	if (!print_status(philo, "has taken a fork"))
		return (false);
	sem_wait(philo->left_fork);
	sem_getvalue(philo->left_fork, &sval);
	philo->l_locked = true;
	if (!print_status(philo, "has taken a fork"))
		return (false);
	return (true);
}

bool	put_forks(t_philo *philo)
{
	int	sval;

	sem_post(philo->left_fork);
	sem_getvalue(philo->left_fork, &sval);
	philo->l_locked = false;
	sem_post(philo->right_fork);
	sem_getvalue(philo->right_fork, &sval);
	philo->r_locked = false;
	return (true);
}
