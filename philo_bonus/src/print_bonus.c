/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:10:19 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/26 19:33:44 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	print_status(t_philo *philo, t_string message)
{
	struct timeval	now;

	sem_wait(philo->data->print);
	gettimeofday(&now, NULL);
	printf("%ld %d %s\n", (now.tv_sec * 1000 + now.tv_usec / 1000)
		- (philo->data->start.tv_sec * 1000
			+ philo->data->start.tv_usec / 1000), philo->id, message);
	sem_post(philo->data->print);
	return (true);
}
