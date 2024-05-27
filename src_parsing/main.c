/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:39:52 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/27 18:33:36 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int **load_texture(t_vars *vars, char *texture_path)
{
	void	*img;
	char	*img_data;
	int		y;
	int		x;
	int		width = 128;
	int		height = 128;
	int		bits_per_pixel = 32;
	int 	endian = 1;
	int		size_line = 128 * (32 / 8);
	int		index;
	int		**texture;

	img = mlx_xpm_file_to_image(vars->mlx, texture_path, &width, &height);

	img_data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	texture = malloc(height * sizeof(int*));
	y = 0;
	while(y < height)
	{
		texture[y] = malloc(width * sizeof(int));
		y++;
	}
	y = 0;
	while(y < height)
	{
		x = 0;
		while(x < width)
		{
			index = (y * size_line + x * (bits_per_pixel / 8));
			texture[y][x] = *(int*)(img_data + index);
			x++;
		}
		y++;
	}
	return (texture);
}

void	load_img(t_vars *vars)
{
	///MENU
	vars->play_click = mlx_xpm_file_to_image(vars->mlx,
			"./img/play.xpm", &vars->width, &vars->height);
	vars->play_selec = mlx_xpm_file_to_image(vars->mlx,
			"./img/play_selec.xpm", &vars->width, &vars->height);
	vars->title = mlx_xpm_file_to_image(vars->mlx,
			"./img/title.xpm", &vars->width, &vars->height);
	vars->you_win = mlx_xpm_file_to_image(vars->mlx,
			"./img/win.xpm", &vars->width, &vars->height);
	
	///GAME TEXTURES
	vars->texture_N = load_texture(vars, "./img/texture_N.xpm");
	vars->texture_W = load_texture(vars, "./img/texture_E.xpm");
	vars->texture_S = load_texture(vars, "./img/texture_N.xpm");
	vars->texture_E = load_texture(vars, "./img/texture_E.xpm");
}

void	init_vars(t_vars *vars)
{
	vars->bool = 0;
	vars->victory = 0;
	vars->start = 0;
	vars->line = NULL;
	vars->button_clicked = 0;
	vars->l = 0;
	vars->ll = 0;
	vars->e = 0;
	vars->p = 0;
	vars->c = 0;
	vars->wrong = 0;
	vars->width = 0;
	vars->height = 0;
	vars->map = NULL;
}

void	init_vars2(t_vars *vars)
{
	vars->play_button_x = (1920 / 2) - 64;
	vars->play_button_y = 500;
	vars->title_x = (1920 / 2) - 380;
	vars->title_y = 300;
}

int	menu_player(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT,
			"cub3D");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->play_click,
		vars->play_button_x, vars->play_button_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->title,
		vars->title_x, vars->title_y);
	event_game(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_vars	*vars;
	
	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
	{
		printf("Error\nMalloc failure\n");
		return (0);
	}
	init_vars(vars);
	if (parsing(vars, argv, argc) == 1)
	{
		return (1);
	}
	init_vars2(vars);
	vars->mlx = mlx_init();
	load_img(vars);
	menu_player(vars);
	return (0);
}
