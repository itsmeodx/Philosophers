/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:39:18 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/18 16:59:29 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_exit(t_data *data, int status, t_string msg)
{
	int	i;

	i = -1;
	if (msg && status == EXIT_FAILURE)
		printf("%s\n", msg);
	free_data(data);
	(void)data;
	exit(status);
}
