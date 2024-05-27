/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_menu_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:47:29 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/27 14:48:45 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_over(int x, int y, t_vars *vars)
{
	if (vars->play_click && vars->play_selec)
	{
		if (x >= vars->play_button_x && x <= vars->play_button_x + 90 && y >= vars->play_button_y
			&& y <= vars->play_button_y + 90)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->play_selec,
				vars->play_button_x, vars->play_button_y);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, vars->play_click,
				vars->play_button_x, vars->play_button_y);
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
		if (mouse_x >= vars->play_button_x && mouse_x <= vars->play_button_x + 100
			&& mouse_y >= vars->play_button_y && mouse_y <= vars->play_button_y + 100
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
	//mlx_destroy_image(vars->mlx, vars->title);
	exec(vars);
	
	//////////////////////
	// START GAME HERE //
	/////////////////////
	
}
