/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:10:19 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/06 19:32:26 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->someone_died || philo->eaten)
	{
		pthread_mutex_unlock(&philo->data->print);
		return (false);
	}
	printf("%ld %d %s\n", get_time(philo->data->start), philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
	return (true);
}
