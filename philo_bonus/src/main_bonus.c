/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:21:41 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/29 13:39:17 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char *av[])
{
	t_data	*data;

	if (ac < 5 || ac > 6)
	{
		printf(USAGE);
		return (EXIT_FAILURE);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("Error: malloc: couldn't allocate data\n"));
	*data = (t_data){0};
	if (!parse_args(data, ac, av))
		return (free_data(data), EXIT_FAILURE);
	if (philosophers(data) == EXIT_FAILURE)
		return (free_data(data), EXIT_FAILURE);
	free_data(data);
	return (EXIT_SUCCESS);
}
