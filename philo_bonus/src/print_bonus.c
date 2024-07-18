/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:10:19 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/18 16:59:29 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	print_status(t_philo *philo, t_string message)
{
	if (philo->died || philo->eaten)
	{
		if (philo->r_locked)
		{
			sem_post(philo->right_fork);
			philo->r_locked = false;
		}
		if (philo->l_locked)
		{
			sem_post(philo->left_fork);
			philo->l_locked = false;
		}
		return (false);
	}
	sem_wait(philo->data->print);
	philo->data->printing = printf("%ld %d %s\n", \
	get_time(philo->data->start), philo->id, message);
	sem_post(philo->data->print);
	return (true);
}
