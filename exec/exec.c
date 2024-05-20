/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:54:10 by dboire            #+#    #+#             */
/*   Updated: 2024/05/20 14:24:07 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_walls_path(t_vars *vars)
{
	double	i;
	int		x_map;
	int		y_map;
	double	y;
	
	x_map = 0;
	y_map = 0;
	i = (WIDTH / 3);
	while(i < vars->ray_x0)
	{
		i += EDGE;
		x_map++;
	}
	i = (i - vars->ray_x0) / EDGE; // i = position precis du pixel i
	y = (HEIGHT / 3);
	while(y < vars->ray_y0)
	{
		y += EDGE;
		y_map++;
	}
	y = (y - vars->ray_y0) / EDGE; // y = position precis du pixel y
	//vars->map[y_map - 1][x_map - 1]
	if(x_map > 0)
		x_map -= 1;
	if(y_map > 0)
		y_map -= 1;
	// printf("path :y_map:%d\n", y_map);
	// printf("path :x_map:%d\n", x_map);
	if(vars->map[y_map][x_map] == '1')
		return (1);
	return (0);
}

int	check_walls_ray(t_vars *vars)
{
	float	i;
	int		x_map;
	int		y_map;
	float	y;
	
	x_map = 0;
	y_map = 0;
	i = (WIDTH / 3);
	while(i <= vars->ray_x1)
	{
		i += EDGE;
		x_map++;
	}
	i = (i - vars->ray_x1) / EDGE; // i = position precis du pixel i
	y = (HEIGHT / 3);
	while(y <= vars->ray_y1)
	{
		y += EDGE;
		y_map++;
	}
	y = (y - vars->ray_y1) / EDGE; // y = position precis du pixel y
	//vars->map[y_map - 1][x_map - 1]
	if(x_map > 1)
		x_map -= 1;
	if(y_map > 1)
		y_map -=1;
	// printf("ray : y_map:%d\n", y_map);
	// printf("ray : x_map:%d\n", x_map);
	if(vars->map[y_map][x_map] == '1')
		return (1);
	return (0);
}

int	check_walls2(t_vars *vars)
{
	float	i;
	int		x_map;
	int		y_map;
	float	y;
	
	x_map = 0;
	y_map = 0;
	i = (WIDTH / 3);
	while(i < vars->play_x + 2)
	{
		i += EDGE;
		x_map++;
	}
	i = (i - vars->play_x) / EDGE; // i = position precis du pixel i
	y = (HEIGHT / 3);
	while(y < vars->play_y + 2)
	{
		y += EDGE;
		y_map++;
	}
	y = (y - vars->play_y) / EDGE; // y = position precis du pixel y
	//vars->map[y_map - 1][x_map - 1]
	if(vars->map[y_map - 1][x_map - 1] == '1')
		return (1);
	return (0);
}

int	check_walls(t_vars *vars)
{
	float	i;
	int		x_map;
	int		y_map;
	float	y;
	
	x_map = 0;
	y_map = 0;
	i = (WIDTH / 3);
	while(i < vars->play_x)
	{
		i += EDGE;
		x_map++;
	}
	i = (i - vars->play_x) / EDGE; // i = position precis du pixel i
	y = (HEIGHT / 3);
	while(y < vars->play_y)
	{
		y += EDGE;
		y_map++;
	}
	y = (y - vars->play_y) / EDGE; // y = position precis du pixel y
	//vars->map[y_map - 1][x_map - 1]
	if(vars->map[y_map - 1][x_map - 1] == '1')
		return (1);
	return (0);
}

void	draw_grid(t_vars *vars)
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
			if(vars->map[i][y] == 'N')
				draw_player(vars);
			y++;
		}
		vars->y = vars->y + EDGE;
		i++;
	}
}

int	move(int keycode, t_vars *vars)
{
	if (keycode == XK_Left)
		vars->angle -= 1;
	if (keycode == XK_Right)
		vars->angle += 1;
	if (keycode == XK_w)
	{
		vars->play_y -= 1;
		if(check_walls(vars) == 1 || check_walls2(vars) == 1)
		{
			vars->play_y += 1;
			return (1);
		}
	}
	if (keycode == XK_a)
	{
		vars->play_x -= 1;
		if(check_walls(vars) == 1 || check_walls2(vars) == 1 )
		{
			vars->play_x += 1;
			return (1);
		}
	}
	if (keycode == XK_s)
	{
		vars->play_y += 1;
		if(check_walls(vars) == 1 || check_walls2(vars) == 1)
		{
			vars->play_y -= 1;
			return (1);
		}
	}
	if (keycode == XK_d)
	{
		vars->play_x += 1;
		if(check_walls(vars) == 1 || check_walls2(vars) == 1)
		{
			vars->play_x -= 1;
			return (1);
		}
	}
	if (keycode == XK_Escape)
		exit(0);
	vars->y = HEIGHT / 3;
	vars->y0 = vars->y;
	vars->x = WIDTH / 3;
	vars->x0 = vars->x;
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
		&vars->line_length, &vars->endian);
	redraw_grid(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	exec(t_vars *vars)
{
	int i;
	int y;

	i = 0;
	y = 0;
	vars->angle = 360;
	vars->y = HEIGHT / 3;
	vars->y0 = vars->y;
	mlx_clear_window(vars->mlx, vars->win);
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	draw_grid(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	mlx_hook(vars->win, KeyPress, KeyPressMask, move, vars);
	mlx_loop(vars->mlx);
	return (0);	
}