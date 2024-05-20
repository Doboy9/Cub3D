/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:47:54 by dboire            #+#    #+#             */
/*   Updated: 2024/05/20 14:20:10 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int	ft_absolute_number(int value)
{
	if (value < 0)
		value = value * -1;
	return (value);	
}

int	ft_sign(int value)
{
	int	i;

	i = 1;
	if (value < 0)
		i = -1;
	return (i);
}

int	ft_draw_line_bresenham(t_vars *vars)
{
	vars->dx = ft_absolute_number(vars->ray_x1 - vars->ray_x0);
	vars->incx = ft_sign(vars->ray_x1 - vars->ray_x0);
	vars->dy = ft_absolute_number(vars->ray_y1 - vars->ray_y0);
	vars->incy = ft_sign(vars->ray_y1 - vars->ray_y0);
	// printf("dx : %f\n", vars->dx);
	if (vars->dx == 0)
		ft_draw_line_y(vars);
	else if (vars->dy == 0)
		ft_draw_line_x(vars);
	else if (vars->dx >= vars->dy)
		ft_draw_horizontal(vars);
	else
		ft_draw_vertical(vars);
	// printf("angle: %f\n", vars->angle);
	// printf("x0:%f\n", vars->ray_x0);
	// printf("x1:%f\n", vars->ray_x1);
	// printf("y0:%f\n", vars->ray_y0);
	// printf("y1:%f\n", vars->ray_y1);
	// printf("\n");
	return (0);
}

void	ft_draw_line_x(t_vars *vars)
{
	// printf("90\n");
	// printf("x0 : %f\n", vars->ray_x0);
	// printf("x1 : %f\n", vars->ray_x1);
	while(vars->ray_x0 != vars->ray_x1)
	{
		if(check_walls_path(vars) == 1)
			break ;
		my_mlx_pixel_put(vars, vars->ray_x0, vars->play_y, 0x00FF0000);
		vars->ray_x0 += vars->incx;
	}
	// printf("After : x0 : %f\n", vars->ray_x0);
	// printf("x1 : %f\n", vars->ray_x1);
}

void	ft_draw_line_y(t_vars *vars)
{
	while (vars->ray_y0 != vars->ray_y1)
	{
		if(check_walls_path(vars) == 1)
			break ;
		my_mlx_pixel_put(vars, vars->play_x, vars->ray_y0, 0x00FF0000);
		vars->ray_y0 += vars->incy;
	}
}

void	ft_draw_horizontal(t_vars *vars)
{
	float	slope;
	float	error;
	float	errorinc;

	slope = 2 * vars->dy;
	error = -vars->dx;
	errorinc = -2 * vars->dx;
	while (vars->ray_x0 != vars->ray_x1)
	{
		if(check_walls_path(vars) == 1)
			break ;
		my_mlx_pixel_put(vars, vars->ray_x0, vars->ray_y0, 0x00FF0000);
		error += slope;
		if (error >= 0)
		{
			vars->ray_y0 += vars->incy;
			error += errorinc;
		}
		vars->ray_x0 += vars->incx;
	}
}

void	ft_draw_vertical(t_vars *vars)
{
	float	slope;
	float	error;
	float	errorinc;

	slope = 2 * vars->dx;
	error = -vars->dy;
	errorinc = -2 * vars->dy;
	while (vars->ray_y0 != vars->ray_y1)
	{
		if(check_walls_path(vars) == 1)
			break ;
		my_mlx_pixel_put(vars, vars->ray_x0, vars->ray_y0, 0x00FF0000);
		error += slope;
		if (error >= 0)
		{
			vars->ray_x0 += vars->incx;
			error += errorinc;
		}
		vars->ray_y0 += vars->incy;
	}
}
