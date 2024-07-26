/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:05:18 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/25 20:35:45 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_mssleep(long time)
{
	struct timeval	start;
	struct timeval	now;

	time = time * 1000;
	gettimeofday(&start, NULL);
	if (time - 20 * 1000 > 0)
		usleep(time - 20 * 1000);
	// while (get_time(start) < time / 1000)
	// 	;
	while (true)
	{
		gettimeofday(&now, NULL);
		if ((now.tv_sec * 1000 + now.tv_usec / 1000)
			- (start.tv_sec * 1000 + start.tv_usec / 1000) >= time / 1000)
			break ;
	}
}
