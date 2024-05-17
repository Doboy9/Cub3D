/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:14:21 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/15 13:29:14 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		parsing(t_vars *vars, char **argv, int argc)
{
	if (argc > 2)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Too much arguments\n"RESET);
		return (1);
	}
	else if (argc == 1)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Please specify a map\n"RESET);
		return (1);
	}
	else if (check_caracters(argv[1], vars) == 1)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Wrong caracters in the map\n"RESET);
		free_map(vars);
	}
	return (0);
}
