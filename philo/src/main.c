/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:23:27 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/07 18:08:23 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf(USAGE);
		return (EXIT_FAILURE);
	}
	data = (t_data){0};
	if (!parse_args(&data, ac, av))
		return (EXIT_FAILURE);
	philosophers(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
