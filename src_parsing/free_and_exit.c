/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:29:24 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/20 15:25:19 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_image(t_vars *vars)
{
	if (vars->play_click)
	{
		mlx_destroy_image(vars->mlx, vars->play_click);
		mlx_destroy_image(vars->mlx, vars->play_selec);
		mlx_destroy_image(vars->mlx, vars->title);
	}
	//mlx_destroy_image(vars->mlx, vars->you_win);
	
}

void	free_vars(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map)
	{
		while (vars->map[i])
			free(vars->map[i++]);
		free(vars->map);
	}
	if (vars->texture)
	{
		i = 0;
		while (i < 7)
			free(vars->texture[i++]);
		free(vars->texture);
	}
	destroy_image(vars);
	if (vars->mlx && vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free(vars);
	exit(0);
}

void	free_modified_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->l)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}
