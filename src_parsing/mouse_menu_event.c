/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_menu_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:47:29 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/19 17:37:11 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_over(int x, int y, t_vars *vars)
{
	if (vars->play_click && vars->play_selec)
	{
		if (x >= vars->play_x && x <= vars->play_x + 90 && y >= vars->play_y
			&& y <= vars->play_y + 90)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->play_selec,
				vars->play_x, vars->play_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->play_click,
				vars->play_x, vars->play_y);
	}
	return (0);
}

int	mouse_click(int button, int x, int y, t_vars *vars)
{
	int	mouse_x;
	int	mouse_y;

	x++;
	y++;
	mlx_mouse_get_pos(vars->mlx, vars->win, &mouse_x, &mouse_y);
	if (button == 1)
	{
		if (mouse_x >= vars->play_x && mouse_x <= vars->play_x + 100
			&& mouse_y >= vars->play_y && mouse_y <= vars->play_y + 100
			&& vars->play_click)
		{
			vars->button_clicked = 1;
			go_in_game(vars);
			return (0);
		}
	}
	return (0);
}

void	event_game(t_vars *vars)
{
	mlx_hook(vars->win, MotionNotify, PointerMotionMask, mouse_over, vars);
	mlx_mouse_hook(vars->win, mouse_click, vars);
	mlx_hook(vars->win, 17, 1L << 17, close_with_x, vars);
	mlx_key_hook(vars->win, close_with_esc, vars);
	
	/////////////////////
	// hook mouvement? //
	/////////////////////
	
	mlx_loop(vars->mlx);
}

void	go_in_game(t_vars *vars)
{
	vars->button_clicked = 1;
	mlx_destroy_image(vars->mlx, vars->play_click);
	vars->play_click = NULL;
	mlx_destroy_image(vars->mlx, vars->play_selec);
	vars->play_selec = NULL;
	mlx_destroy_image(vars->mlx, vars->title);
	vars->map[0] = ft_strdup("111111111");
	vars->map[1] = ft_strdup("100001001");
	vars->map[2] = ft_strdup("100000101");
	vars->map[3] = ft_strdup("100100001");
	vars->map[4] = ft_strdup("101000001");
	vars->map[5] = ft_strdup("1001000N1");
	vars->map[6] = ft_strdup("100000101");
	vars->map[7] = ft_strdup("111111111");
	vars->map[8] = NULL;
	exec(vars);
	
	//////////////////////
	// START GAME HERE //
	/////////////////////
	
}
