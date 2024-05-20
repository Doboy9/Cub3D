/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:34 by dboire            #+#    #+#             */
/*   Updated: 2024/05/20 14:27:20 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

void rotation_matrix(t_vars *vars)
{
	double radian;
	double cos_a;
	double sin_a;
	double dx;
	double dy;


	radian = 0;
	cos_a = 0;
	sin_a = 0;
	dx = 0;
	dy = 0;
	radian = vars->angle *  (PI / 180);
	cos_a = cos(radian);
	sin_a = sin(radian);
	dx = vars->ray_x1 - vars->ray_x0;
	dy = vars->ray_y1 - vars->ray_y0;
	vars->rotate_x1 = (dx * cos_a) - (dy * sin_a);
	vars->rotate_y1 =(dx * sin_a) + (dy * cos_a);
}

void	draw_rays_north(t_vars *vars)
{
	int	i;
	float	angle;
	int	y;

	y = 60;
	i = 0;
	angle = vars->angle - (y / 2);
	while(i < y)
	{
		vars->ray_x0 = vars->play_x;
		vars->ray_x1 = vars->play_x;
		vars->ray_y0 = vars->play_y;
		vars->ray_y1 = vars->play_y;
		while(check_walls_ray(vars) != 1)
		{
			vars->ray_x1 = cos(vars->angle * PI / 180);
			vars->ray_y1 = sin(vars->angle * PI / 180);
		}
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		vars->angle += 1;
		if(vars->angle == -1)
			vars->angle = 359;
		vars->angle =  vars->angle % 360;
		i++;
	}
	vars->angle = angle + (y * 0.5);
}

void	draw_rays_south(t_vars *vars)
{
	float	angle;
	int	i;
	
	i = 0;
	angle = vars->angle;
	while(i < 90)
	{
		vars->ray_x1 = vars->play_x;
		vars->ray_y0 = vars->play_y;
		vars->ray_y1 = vars->play_y;
		vars->ray_x0 = vars->play_x;
		while(check_walls_ray(vars) != 1)
			vars->ray_y1++;
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		vars->angle += 1;
		if(vars->angle == -1)
			vars->angle = 359;
		vars->angle =  vars->angle % 360;
		i++;
	}
	vars->angle = angle;
}


void	draw_rays_west(t_vars *vars)
{
	float	angle;
	int	i;
	
	i = 0;
	angle = vars->angle;
	while(i < 90)
	{
		vars->ray_x1 = vars->play_x;
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
		vars->angle += 1;
		if(vars->angle == -1)
			vars->angle = 359;
		vars->angle =  vars->angle % 360;
		i++;
	}
	vars->angle = angle;
}


void	draw_rays_east(t_vars *vars)
{
	float	angle;
	int	i;
	
	i = 0;
	angle = vars->angle;
	while(i < 90)
	{
		vars->ray_x1 = vars->play_x;
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
		vars->angle += 1;
		if(vars->angle == -1)
			vars->angle = 359;
		vars->angle =  vars->angle % 360;
		i++;
	}
	vars->angle = angle;
}
