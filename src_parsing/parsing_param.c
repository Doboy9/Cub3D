/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:28:04 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/22 16:10:00 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int found_map(char *line)
{
 	int i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			return (1);
		return (0);
	}
	return (0);
}

char *stock_path(char *line, int i)
{
	int j;
	char *texture;

	j = 0;
	line = remove_space(line);
	texture = malloc(sizeof(char) * ft_strlen(line));
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		texture[j] = line[i];
		i++;
		j++;
	}
	texture[j] = '\0';
	free(line);
	line = NULL;
	return (texture);
}

int check_param(char *map, t_vars *vars)
{
	int fd;
	int i;
	char *line;

	i = 0;
	line = NULL;
	vars->texture = malloc(sizeof(char *) * 7);
	if (vars->texture == NULL)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Can't upload texture\n"RESET);
		return (1);
	}
	vars->texture[6] = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Can't open map\n"RESET);
		return (1);
	}
	while (line || i == 0)
	{
		line = get_next_line(fd);
		if (ft_strncmp(line, "NO ", 3) == 0 && vars->no == 0)
		{	
			vars->no = 1;
			vars->texture[0] = stock_path(line, 2);
		}
		else if (ft_strncmp(line, "SO ", 3) == 0 && vars->so == 0)
		{
			vars->so = 1;
			vars->texture[1] = stock_path(line, 2);
		}
		else if (ft_strncmp(line, "WE ", 3) == 0 && vars->we == 0)
		{
			vars->we = 1;
			vars->texture[2] = stock_path(line, 2);
		}
		else if (ft_strncmp(line, "EA ", 3) == 0 && vars->ea == 0)
		{
			vars->ea = 1;
			vars->texture[3] = stock_path(line, 2);
		}
		else if (ft_strncmp(line, "F ", 2) == 0 && vars->f == 0)
		{
			vars->f = 1;
			vars->texture[4] = stock_path(line, 1);
		}
		else if (ft_strncmp(line, "C ", 2) == 0 && vars->c == 0)
		{
			vars->c = 1;
			vars->texture[5] = stock_path(line, 1);
		}
		else if (found_map(line) == 1)
		{
			if (vars->no == 1 && vars->so == 1 && vars->we == 1 && vars->ea == 1 && vars->f == 1 && vars->c == 1)
			{
				free(line);
				vars->line_map = i;
				return (0);
			}
			else
			{
				printf(RED"Error\n"RESET);
				printf(YELLOW"Missing parameter\n"RESET);
				free(line);
				return (1);
			}
		}
		else
		{
			int a;
			
			a = 0;
			while(line[a])
			{
				if (line[a] != ' ' && line[a] != '\n')
				{
					printf(RED"Error\n"RESET);
					printf(YELLOW"Wrong parameter -> %c\n"RESET, line[a]);
					free(line);
					return (1);
				}
				a++;
			}
		}
		free(line);
		i++;
	}
	printf(RED"Error\n"RESET);
	printf(YELLOW"Missing map\n"RESET);
	return (1);
	
}
