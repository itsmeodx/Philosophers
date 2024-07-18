/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:10:19 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/18 16:02:24 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_status(t_philo *philo, char *message)
{
	if (philo->data->someone_died || philo->eaten)
	{
		if (philo->r_locked)
			mutex_unlock(philo->right_fork);
		if (philo->l_locked)
			mutex_unlock(philo->left_fork);
		return (false);
	}
	philo->data->printing = printf("%ld %d %s\n", \
	get_time(philo->data->start), philo->id, message);
	return (true);
}
