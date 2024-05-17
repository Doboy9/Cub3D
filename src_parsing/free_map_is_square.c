/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_is_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:13:25 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/15 12:09:38 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map)
	{
		while (i < vars->l)
			free(vars->map[i++]);
		free(vars->map);
	}
	free (vars);
	exit(0);
}

int	is_square(t_vars *vars)
{
	if (vars->l == vars->ll)
		return (0);
	if (vars->ll * 64 > 1920 || vars->l * 64 > 1080)
		return (0);
	return (1);
}

int	count_c(t_vars *vars)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0')
		{
			if (vars->map[i][j] == 'C')
				c += 1;
			j++;
		}
		i++;
	}
	return (c);
}
