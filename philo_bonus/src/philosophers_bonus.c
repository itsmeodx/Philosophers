/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:38 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/12 21:53:52 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philosophers(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->philo_count)
	{
		data->pids[i] = ft_fork(data);
		if (data->pids[i] == 0)
		{
			routine(data, &data->philos[i]);
			ft_exit(data, EXIT_SUCCESS, NULL);
		}
	}
}
