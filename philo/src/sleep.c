/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:05:18 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/10 09:47:35 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mssleep(long time)
{
	struct timeval	start;

	time = time * 1000;
	gettimeofday(&start, NULL);
	if (time - 20 * 1000 > 0)
		usleep(time - 20 * 1000);
	while (get_time(start) < time / 1000)
		;
}
