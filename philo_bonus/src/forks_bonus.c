/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:35:27 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/20 16:12:55 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	take_forks(t_philo *philo)
{
	while (ft_sem_trywait(philo->right_fork) == false && !philo->died)
		;
	philo->r_locked = true && !philo->died;
	if (!print_status(philo, "has taken a fork"))
		return (false);
	while (ft_sem_trywait(philo->left_fork) == false && !philo->died)
		;
	philo->l_locked = true && !philo->died;
	if (!print_status(philo, "has taken a fork"))
		return (false);
	return (true);
}

bool	put_forks(t_philo *philo)
{
	sem_post(philo->left_fork);
	philo->l_locked = false;
	sem_post(philo->right_fork);
	philo->r_locked = false;
	return (true);
}
