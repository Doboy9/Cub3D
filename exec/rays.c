/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:15:34 by dboire            #+#    #+#             */
/*   Updated: 2024/05/27 18:26:51 by kprigent         ###   ########.fr       */
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

double calculate_wall_height(t_vars *vars, double distance, double ray_angle)
{
    int wall_height;
	(void)vars;
	
    double corrected_distance = distance * cos(((ray_angle * (PI / 180.0)) - (vars->angle * (PI / 180.0))) * PI / 180.0);
    wall_height = (HEIGHT / corrected_distance) * 20;
    // pas plus grand que la hauteur de l'écran
    if (wall_height > HEIGHT)
        wall_height = HEIGHT;
    return (wall_height);
}
void draw_wall(t_vars *vars, int x, int wall_height)
{
	// int centerX = WIDTH / 2;
	int centerY = HEIGHT / 2;

	int draw_start = centerY - wall_height;	
	if(draw_start < 0)
		draw_start = 0;
	int draw_end = centerY + wall_height;
	if(draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	int j = draw_start;
	int tex_height = 128; // la hauteur de la texture
	int line_height = draw_end - draw_start; // la hauteur du mur à l'écran

	int direction = check_walls_ray(vars);
	if (direction == NORTH)
	{
		while (j < draw_end)
		{
			int tex_y = ((j - draw_start) * tex_height) / line_height;

			int po;

			po = vars->pos_x * 128;
			my_mlx_pixel_put(vars, x, j, vars->texture_N[tex_y][po]);
			j++;
		}
	}
	if (direction == EAST)
	{
		while (j < draw_end)
		{
			int tex_y = ((j - draw_start) * tex_height) / line_height;

			int po;

			po = vars->pos_x * 128;
			my_mlx_pixel_put(vars, x, j, vars->texture_E[tex_y][po]);
			j++;
		}
	}
	if (direction == SOUTH)
	{
		while (j < draw_end)
		{
			int tex_y = ((j - draw_start) * tex_height) / line_height;

			int po;

			po = vars->pos_x * 128;
			my_mlx_pixel_put(vars, x, j, vars->texture_S[tex_y][po]);
			j++;
		}
	}
	if (direction == WEST)
	{
		while (j < draw_end)
		{
			int tex_y = ((j - draw_start) * tex_height) / line_height;

			int po;

			po = vars->pos_x * 128;
			my_mlx_pixel_put(vars, x, j, vars->texture_W[tex_y][po]);
			j++;
		}
	}
	while (j <= HEIGHT)
	{
		my_mlx_pixel_put(vars, x, j, vars->floor_color);
		j++;
	}
	j = draw_start;
	while (j >= 0)
	{
		my_mlx_pixel_put(vars, x, j, vars->celing_color);
		j--;
	}
}

void	draw_rays(t_vars *vars)
{
	double	angle_step;
	double	distance = 0;
	// int	y;
	int	rays_number = 192;
	float x = 0;
	float column_end;
	float column_start;
	// double angle;

	// y = 1919;
	angle_step = 0.3125;
	printf("angle_step: %f \n", angle_step);
	printf("angle_total: %f \n", angle_step * rays_number);
	vars->angle -= 30;
	if (vars->angle < 0)
		vars->angle += 360.0;
	if (vars->angle >= 360)
		vars->angle -= 360.0;
	printf("angle: %f \n", vars->angle);
	// angle = vars->angle;
	column_start = x * (WIDTH / rays_number);
	while(x < rays_number)
	{
		double ray_angle = vars->angle + (x * angle_step);
		vars->ray_x0 = vars->play_x;
		vars->ray_y0 = vars->play_y;
		vars->ray_y = vars->ray_y0;
		vars->ray_x = vars->ray_x0;
		vars->ray_x1 = cos((vars->angle * PI) / 180) + vars->ray_x0;
		vars->ray_y1 = sin((vars->angle * PI) / 180) + vars->ray_x0;
		rotation_matrix(vars);
		vars->ray_x1 = vars->ray_x0 + vars->rotate_x1;
		vars->ray_y1 = vars->ray_y0 + vars->rotate_y1;
		ft_draw_line_bresenham(vars);
		distance = sqrt(pow(vars->ray_x - vars->play_x, 2) + pow(vars->ray_y - vars->play_y, 2));
		int h = calculate_wall_height(vars, distance, ray_angle);
        column_end = (x + 1) * (WIDTH / rays_number);
        while(column_start < column_end)
        {
			draw_wall(vars, column_start, h);
			column_start++;
		}
		x++;
		vars->angle += angle_step;
		if (vars->angle < 0)
			vars->angle += 360.0;
		if (vars->angle >= 360)
			vars->angle -= 360.0;
	}
	vars->angle -= 30;
	if (vars->angle < 0)
		vars->angle += 360.0;
	if (vars->angle >= 360)
		vars->angle -= 360.0;
	printf("inc x: %f \n", x);
	printf("angle: %f \n", vars->angle);
}
