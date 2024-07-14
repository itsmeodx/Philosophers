/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:39:18 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/12 21:49:45 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_exit(t_data *data, int status, char *msg)
{
	int	i;

	i = -1;
	if (msg && status == EXIT_FAILURE)
		printf("%s\n", msg);
	while (++i < data->philo_count)
		kill(data->pids[i], SIGKILL);
	free_data(data);
	exit(status);
}
