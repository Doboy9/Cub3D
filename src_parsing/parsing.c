/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:14:21 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/25 13:27:42 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int convert_color_string_to_int(char* color_string)
{
	int i;
    int red, green, blue;
    char **rgb_values;

	i = 0;
    rgb_values = ft_split(color_string, ',');
    red = ft_atoi(rgb_values[0]);
    green = ft_atoi(rgb_values[1]);
    blue = ft_atoi(rgb_values[2]);
    while (i < 3)
	{
        free(rgb_values[i]);
		i++;
    }
    free(rgb_values);
    int color = (red << 16) | (green << 8) | blue;
    return (color);
}

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
	else if (check_param(argv[1], vars) == 1)
	{
		free_vars(vars);	
		return (1);
	}
	else if ((vars->line_map != 0) && check_map(argv[1], vars) == 1)
	{
		free_vars(vars);
		return (1);
	}
	if (check_param_valid(vars) == 1)
	{
		free_vars(vars);
		return (1);
	}
	vars->floor_color = convert_color_string_to_int(vars->texture[4]);
	vars->celing_color = convert_color_string_to_int(vars->texture[5]);
	return (0);
}
