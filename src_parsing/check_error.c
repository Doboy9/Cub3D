/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboire <dboire@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:43:32 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/20 15:23:55 by dboire           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_nsew(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_left_right(t_vars *vars, int a, int i)
{
	if (vars->map[a][i - 1] != '0' && vars->map[a][i - 1] != '1'
		&& is_nsew(vars->map[a][i - 1]) == 0)
		return (1);
	if (vars->map[a][i + 1] != '0' && vars->map[a][i + 1] != '1'
		&& is_nsew(vars->map[a][i + 1]) == 0)
		return (1);
	return (0);
}

int	check_top_bottom(t_vars *vars, int a, int i)
{
	if (a < 1 || vars->map[a + 1] == NULL) 
		return (1);
	if (vars->map[a - 1][i] != '0' && vars->map[a - 1][i] != '1' 
		&& is_nsew(vars->map[a - 1][i]) == 0)	
		return (1);
	if (vars->map[a + 1][i] != '0' && vars->map[a + 1][i] != '1'
		&& is_nsew(vars->map[a + 1][i]) == 0)
		return (1);
	return (0);
}

int check_diagonal(t_vars *vars, int a, int i)
{
	if (vars->map[a - 1][i - 1] != '0' && vars->map[a - 1][i - 1] != '1'
		&& is_nsew(vars->map[a - 1][i - 1]) == 0)
		return (1);
	if (vars->map[a - 1][i + 1] != '0' && vars->map[a - 1][i + 1] != '1'
		&& is_nsew(vars->map[a - 1][i + 1]) == 0)
		return (1);
	if (vars->map[a + 1][i - 1] != '0' && vars->map[a + 1][i - 1] != '1'
		&& is_nsew(vars->map[a + 1][i - 1]) == 0)
		return (1);
	if (vars->map[a + 1][i + 1] != '0' && vars->map[a + 1][i + 1] != '1'
		&& is_nsew(vars->map[a + 1][i + 1]) == 0)
		return (1);
	return (0);
}

int	check_border(t_vars *vars)
{
	int	a;
	int i;
	
	i = 0;
	a = 0;
	while (vars->map[a])
	{	
		i = 0;
		while(vars->map[a][i] != '\0')
		{
			if (vars->map[a][i] == '0' || is_nsew(vars->map[a][i]) == 1)
			{
				if (check_left_right(vars, a, i) == 1)
					return (1);
				if (check_top_bottom(vars, a, i) == 1)
					return (1);
				if (check_diagonal(vars, a, i) == 1)
					return (1);
			}
			i++;
		}
		a++;
	}
	return (0);
}

int check_char(char **tab)
{
	int	a;
	int	i;

	a = 0;
	i = 0;
	while (tab[a])
	{
		while (tab[a][i])
		{
			if (tab[a][i] != '0' && tab[a][i] != '1' && is_nsew(tab[a][i]) == 0
				&& tab[a][i] != ' ' && tab[a][i] != '\t' && tab[a][i] != '\n')
			{
				printf(RED"Error\n"RESET);
				printf(YELLOW"Wrong caracter found\n"RESET);
				return (1);
			}
			i++;
		}
		i = 0;
		a++;
	}
	return (0);	
}
void	map_to_chart(t_vars *vars, int fd)
{
	int		a;
	int		i;
	int 	b;

	a = 0;
	b = 0;
	i = 0;
	while (vars->line || a == 0)
	{
		while (b < vars->line_map)
		{
			vars->line = get_next_line(fd);
			free(vars->line);
			b++;
		}
		vars->line = get_next_line(fd);
		if (vars->line == NULL)
			break ;
		vars->map[a] = (char *)malloc(sizeof(char)
				* (ft_strlen(vars->line) + 1));
		while (vars->line[i])
		{
			vars->map[a][i] = vars->line[i];
			i++;
		}
		free(vars->line);
		vars->map[a][i] = '\0';
		i = 0;
		a++;
	}
	vars->map[a] = NULL;
}

int	stock_map(char *map, t_vars *vars)
{
	int	fd;
	// int	a;

	// a = 0;
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
		printf(RED"Error\n Can't upload map\n" RESET);
		return (1);
	}
	close(fd);
	fd = open(map, O_RDONLY);
	map_to_chart(vars, fd);
	return (0);
}

int	check_map(char *map, t_vars *vars)
{
	if (stock_map(map, vars) == 1)
		return (1);
	if (check_char(vars->map) == 1)
		return (1);
	// if (check_nsew(vars) == 1)
	// 	return (1);
	if (check_border(vars) == 1)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Check border of the map\n"RESET);
		return (1);
	}
	return (0);
}
