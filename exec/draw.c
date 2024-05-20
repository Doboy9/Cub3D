/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:41:55 by dboire            #+#    #+#             */
/*   Updated: 2024/05/20 13:27:28 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void	draw_player(t_vars *vars)
{
	int i;
	
	i = 0;
	vars->play_x = vars->x - EDGE / 2;
	vars->play_y = vars->y + EDGE / 2;
	my_mlx_pixel_put(vars, vars->play_x, vars->play_y, 0x00FF0000);
	my_mlx_pixel_put(vars, vars->play_x + 1, vars->play_y, 0x00FF0000);
	my_mlx_pixel_put(vars, vars->play_x, vars->play_y + 1, 0x00FF0000);
	my_mlx_pixel_put(vars, vars->play_x + 1, vars->play_y + 1, 0x00FF0000);
	if(vars->angle >= 45 && vars->angle < 135)
		draw_rays_south(vars);
	if(vars->angle >= 135 && vars->angle < 225)
		draw_rays_west(vars);
	if(vars->angle >= 315 || vars->angle < 45)
		draw_rays_east(vars);
	else
		draw_rays_north(vars);
}

void	draw_floor_tile(t_vars *vars)
{
	int	i;

	i = 0;
	vars->x0 = vars->x;
	vars->x1 = vars->x + EDGE;
	vars->y0 = vars->y;
	vars->y1 = vars->y + EDGE;
	while (vars->x < vars->x1)
	{
		my_mlx_pixel_put(vars, vars->x, vars->y0, 0x00FFFFFF);
		vars->x++;
	}
	while (vars->y < vars->y1)
	{
		my_mlx_pixel_put(vars, vars->x, vars->y, 0x00FFFFFF);
		vars->y++;
	}
}

void	draw_wall_tile(t_vars *vars)
{
	int	i;

	i = 0;
	vars->x0 = vars->x;
	vars->x1 = vars->x + EDGE;
	vars->y = vars->y0;
	vars->y1 = vars->y + EDGE;
	while (vars->y < vars->y1)
	{
		vars->x = vars->x0;
		while (vars->x < vars->x1)
		{
			my_mlx_pixel_put(vars, vars->x, vars->y, 0x00FFFFFF);
			vars->x++;
		}
		vars->y++;
	}
	vars->y = vars->y0;
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}