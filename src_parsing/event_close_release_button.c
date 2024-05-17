/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_close_release_button.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:13:14 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/15 12:09:38 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_with_esc(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		free_vars(vars);
	return (0);
}

int	close_with_x(t_vars *vars)
{
	free_vars(vars);
	return (0);
}
