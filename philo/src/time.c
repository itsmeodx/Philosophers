/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:15:09 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/08 21:28:52 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timetoms(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	get_time(struct timeval start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec / 1000)
		- (start.tv_sec * 1000 + start.tv_usec / 1000));
}
