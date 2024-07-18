/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:38 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/18 17:16:02 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	run_process(t_philo *philo)
{
	philo->left_fork = sem_open("forks", O_CREAT, 0644,
			philo->data->philo_count);
	philo->right_fork = sem_open("forks", O_CREAT, 0644,
			philo->data->philo_count);
	if (!run_monitor(philo))
		ft_exit(philo->data, EXIT_FAILURE, "Error: run_monitor failed\n");
	routine(philo);
	ft_exit(philo->data, EXIT_SUCCESS, NULL);
}

bool	check_death(t_data *data, int i)
{
	int		status;
	pid_t	died;

	died = 0;
	while (died != -1)
	{
		died = wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		{
			while (i--)
			{
				if (data->pids[i] != died)
					kill(data->pids[i], SIGKILL);
			}
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	philosophers(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->philo_count)
	{
		data->pids[i] = ft_fork(data);
		if (data->pids[i] == 0)
			run_process(&data->philos[i]);
	}
	if (!check_death(data, i))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
