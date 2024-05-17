/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:55:38 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/15 15:04:59 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_epc(t_vars *vars)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (a < vars->l)
	{
		while (vars->map[a][i])
		{
			if (vars->map[a][i] == 'E')
				vars->e += 1;
			if (vars->map[a][i] == 'P')
				vars->p += 1;
			if (vars->map[a][i] == 'C')
				vars->c += 1;
			i++;
		}
		i = 0;
		a++;
	}
	// if (vars->e == 1 && vars->p == 1 && vars->c >= 1)
	// 	return (1);
	// ft_printf("Error\nMissing element(s) or to much P/E\n");
	return (0);
}

int	nb_line(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (line || i == 0)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		free(line);
	}
	return (i);
}

void	find_a_way(t_vars *vars, int x, int y)
{
	if (y < 0 || y >= vars->l || x < 0 || x >= vars->ll
		|| vars->map[y][x] == '1' || vars->map[y][x] == 'V')
		return ;
	if (vars->map[y][x] == 'P')
		vars->p += 1;
	if (vars->map[y][x] == 'E')
		vars->e += 1;
	if (vars->map[y][x] == 'C')
		vars->c += 1;
	if (vars->map[y][x] != 'C' && vars->map[y][x] != 'P'
		&& vars->map[y][x] != 'E' && vars->map[y][x] != '0')
	{
		ft_printf("Error\n Wrong caracter found\n");
		vars->wrong += 1;
	}
	vars->map[y][x] = 'V';
	find_a_way(vars, x - 1, y);
	find_a_way(vars, x + 1, y);
	find_a_way(vars, x, y - 1);
	find_a_way(vars, x, y + 1);
}

void	find_p(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i])
	{
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
			{
				vars->p_y = i;
				vars->p_x = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
