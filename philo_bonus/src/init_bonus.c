/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:55:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/18 17:16:02 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	data_init(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (data->philos)
		memset(data->philos, 0, sizeof(t_philo) * data->philo_count);
	data->pids = malloc(sizeof(pid_t) * data->philo_count);
	if (data->pids)
		memset(data->pids, 0, sizeof(pid_t) * data->philo_count);
	sem_unlink("forks");
	data->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, data->philo_count);
	if (data->forks == SEM_FAILED)
		return (printf("Error: sem_open: can't open forks\n"), free_data(data),
			false);
	sem_unlink("print");
	data->print = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	if (data->print == SEM_FAILED)
		return (printf("Error: sem_open: can't open print\n"), free_data(data),
			false);
	if (!data->philos || !data->pids)
		return (free_data(data), false);
	return (true);
}

t_string	get_sem_name(t_string prefix, int id)
{
	t_string	sem_name;
	t_string	id_str;
	int			i;
	int			j;

	id_str = ft_itoa(id);
	sem_name = malloc(sizeof(char) * (ft_strlen(prefix) + ft_strlen(id_str)
				+ 1));
	if (!sem_name)
		return (NULL);
	i = -1;
	while (prefix[++i])
		sem_name[i] = prefix[i];
	j = -1;
	while (id_str[++j])
		sem_name[i++] = id_str[j];
	sem_name[i] = '\0';
	free(id_str);
	return (sem_name);
}

bool	philo_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].right_fork = data->forks;
		data->philos[i].left_fork = data->forks;
	}
	if (gettimeofday(&data->start, NULL) == -1)
		return (free_data(data), false);
	return (true);
}
