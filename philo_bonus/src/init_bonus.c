/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:55:45 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/25 19:03:28 by oouaadic         ###   ########.fr       */
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
	if (!ft_sem_open(&data->forks, "forks", data->philo_count))
		return (free_data(data), false);
	if (!ft_sem_open(&data->print, "print", 1))
		return (free_data(data), false);
	if (!ft_sem_open(&data->killall, "killall", 0))
		return (free_data(data), false);
	if (!ft_sem_open(&data->exitted, "exitted", 0))
		return (free_data(data), false);
	if (!ft_sem_open(&data->starting, "starting", data->philo_count - 1))
		return (free_data(data), false);
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
		data->philos[i].name = get_sem_name("status ", i + 1);
		if (!data->philos[i].name)
			return (free_data(data), false);
		if (!ft_sem_open(&data->philos[i].status, data->philos[i].name, 1))
			return (free_data(data), false);
	}
	return (true);
}
