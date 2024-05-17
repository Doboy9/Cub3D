/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:43:32 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/15 15:06:13 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_top_bottom(t_vars *vars, int last)
{
	int	i;

	i = 0;
	while (vars->map[last][i] != '\0')
	{
		if (vars->map[last][i] != '1')
		{
			ft_printf("Error\nbottom border\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (vars->map[0][i] != '\0')
	{
		if (vars->map[0][i] != '1')
		{
			ft_printf("Error\ntop border\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_border(t_vars *vars)
{
	int	a;
	int	last;
	int	last2;

	last2 = ft_strlen(vars->map[0]);
	last = vars->l - 1;
	if (check_top_bottom(vars, last) == 0)
		return (0);
	a = 0;
	while (a <= last)
	{
		if (vars->map[a][0] != '1' || vars->map[a][last2 - 1] != '1')
		{
			ft_printf("Error\nR or L border\n");
			return (0);
		}
		a++;
	}
	return (1);
}

void	map_to_chart(t_vars *vars, int fd)
{
	int		a;
	int		i;

	a = 0;
	i = 0;
	while (vars->line || a == 0)
	{
		vars->line = get_next_line(fd);
		if (vars->line == NULL)
			break ;
		vars->map[a] = (char *)malloc(sizeof(char)
				* (ft_strlen(vars->line) + 1));
		while (vars->line[i] != '\n')
		{
			vars->map[a][i] = vars->line[i];
			i++;
		}
		free(vars->line);
		vars->map[a][i] = '\0';
		i = 0;
		a++;
		vars->l = a;
		vars->ll = ft_strlen(vars->map[0]);
	}
	vars->map[a] = NULL;
}

int	stock_map(char *map, t_vars *vars)
{
	int	fd;
	int	a;

	a = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Can't open map\n"RESET);
		return (0);
	}
	vars->map = malloc(sizeof(char *) * (nb_line(fd) + 1));
	if (vars->map == NULL)
	{
		ft_printf("Error\n Can't upload map\n");
		return (0);
	}
	close(fd);
	fd = open(map, O_RDONLY);
	map_to_chart(vars, fd);
	return (1);
}

int	check_caracters(char *map, t_vars *vars)
{
	if (stock_map(map, vars) == 0 || check_border(vars) == 0
		|| check_epc(vars) == 0 || is_square(vars) == 0)
		return (0);
	find_p(vars);
	vars->p = 0;
	vars->e = 0;
	vars->c = 0;
	find_a_way(vars, vars->p_x, vars->p_y);
	free_modified_map(vars);
	stock_map(map, vars);
	if (vars->p != 1 || vars->e != 1 || vars->c != count_c(vars)
		|| vars->wrong >= 1)
	{
		ft_printf("Error\nNO PATH FOUND\n");
		return (0);
	}
	else
		return (1);
}
