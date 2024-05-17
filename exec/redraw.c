/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:44:44 by dboire            #+#    #+#             */
/*   Updated: 2024/05/17 18:36:26 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void	redraw_player(t_vars *vars)
{
	if(check_walls(vars) == 1)
		return ;
	if(check_walls2(vars) == 1)
		return ;
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

void	redraw_grid(t_vars *vars)
{
	int	i;
	int	y;
	
	i = 0;
	while (vars->map[i])
	{
		y = 0;
		vars->x = WIDTH / 3;
		vars->y0 = vars->y;
		while (vars->map[i][y])
		{
			if (vars->map[i][y] == '1')
				draw_wall_tile(vars);
			else if(vars->map[i][y] != '1')
			{
				draw_floor_tile(vars);
				vars->y = vars->y0;
			}
			y++;
		}
		vars->y = vars->y + EDGE;
		i++;
	}
	redraw_player(vars);
}