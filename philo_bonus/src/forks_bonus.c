/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:35:27 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/25 20:22:01 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	take_forks(t_philo *philo)
{
	sem_wait(philo->right_fork);
	philo->r_locked = true;
	print_status(philo, "has taken a fork");
	sem_wait(philo->left_fork);
	philo->l_locked = true;
	print_status(philo, "has taken a fork");
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
