/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:34 by dboire            #+#    #+#             */
/*   Updated: 2024/05/17 18:39:08 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void rotation_matrix(t_vars *vars)
{
	float radian = vars->angle * PI / 180.0; // Convertir l'angle en radians
	float cos_a = cos(radian);
	float sin_a = sin(radian);

	float dx = vars->ray_x1 - vars->ray_x0;
	float dy = vars->ray_y1 - vars->ray_y0;

	vars->rotate_x1 = dx * cos_a - dy * sin_a;
	vars->rotate_y1 = dx * sin_a + dy * cos_a;
}

void	draw_rays_south(t_vars *vars)
{
	(void)vars;
	int	i;
	
	i = 0;
	vars->ray_x1 = vars->play_x;
	while(i < 1)
	{
		vars->ray_y0 = vars->play_y;
		vars->ray_y1 = vars->play_y;
		vars->ray_x0 = vars->play_x;
		while(check_walls_ray(vars) != 1)
		{
			vars->ray_y1++;
			vars->ray_x1++;
		}
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		i++;
	}
}

void	draw_rays_north(t_vars *vars)
{
	(void)vars;
	int	i;
	
	i = 0;
	vars->ray_x1 = vars->play_x;
	while(i < 1)
	{
		vars->ray_y0 = vars->play_y;
		vars->ray_y1 = vars->play_y;
		vars->ray_x0 = vars->play_x;
		while(check_walls_ray(vars) != 1)
		{
			vars->ray_y1--;
			vars->ray_x1 += (vars->ray_x1 - vars->play_x) / (vars->ray_y1 - vars->play_y);
		}
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		i++;
	}
}

void	draw_rays_west(t_vars *vars)
{
	(void)vars;
	int	i;
	
	i = 0;
	vars->ray_x1 = vars->play_x;
	while(i < 1)
	{
		vars->ray_y0 = vars->play_y;
		vars->ray_y1 = vars->play_y;
		vars->ray_x0 = vars->play_x;
		while(check_walls_ray(vars) != 1)
		{
			vars->ray_x1--;
			vars->ray_y1 += (vars->ray_y1 - vars->play_y) / (vars->ray_x1 - vars->play_x);
		}
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		i++;
	}
}


void	draw_rays_east(t_vars *vars)
{
	(void)vars;
	int	i;
	
	i = 0;
	vars->ray_x1 = vars->play_x;
	while(i < 1)
	{
		vars->ray_y0 = vars->play_y;
		vars->ray_y1 = vars->play_y;
		vars->ray_x0 = vars->play_x;
		while(check_walls_ray(vars) != 1)
		{
			vars->ray_x1++;
			vars->ray_y1 += (vars->ray_y1 - vars->play_y) / (vars->ray_x1 - vars->play_x);
		}
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		i++;
	}
}
