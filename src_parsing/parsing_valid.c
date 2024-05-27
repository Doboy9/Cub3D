/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:19:13 by kprigent          #+#    #+#             */
/*   Updated: 2024/05/16 16:59:20 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *remove_space(char *input)
{
	int i;
	int j;
	char *output;
	
	i = 0;
	j = 0;
	output = malloc(sizeof(char) * (ft_strlen(input) + 1));
	while(i < (int)ft_strlen(input))
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
		{
			output[j] = input[i];
			j++;
		}
		i++;
	}
	output[j] = '\0';
	return (output);
}

int test_path(char *path)
{
	int fd;

	path = remove_space(path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf(RED"Error\n"RESET);
		printf(YELLOW"Texture path is invalid\n"RESET);
		free(path);
		path = NULL;
		return(1);
	}
	close(fd);
	free(path);
	path = NULL;
	return (0);
}
int test_color(char *tab)
{
	int i;
	int n;

	n = 0;
	i = 0;
	tab = remove_space(tab);
	while (tab[i])
	{
		while (tab[i] >= '0' && tab[i] <= '9')
		{	
			i++;
			n++;
		}
		if (n > 3)
		{
			printf(RED"Error\n"RESET);
			printf(YELLOW"Color is invalid\n"RESET);
			free(tab);
			tab = NULL;
			return (1);
		}
		if ((tab[i] < '0' || tab[i] > '9') && tab[i] != ',' && tab[i] != '\0')
		{
			printf(RED"Error\n"RESET);
			printf(YELLOW"Color is invalid\n"RESET);
			free(tab);
			tab = NULL;
			return (1);
		}
		if (tab[i] != '\0')
			i++;
		n = 0;
	}
	free(tab);
	tab = NULL;
	return (0);
}

int	check_param_valid(t_vars *vars)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (test_path(vars->texture[i]) == 1)
			return (1);
		i++;
	}
	if (test_color(vars->texture[4]) == 1 || test_color(vars->texture[5]) == 1)
		return (1);
	// for (int i = 0; vars->texture[i]; i++)
	// 	printf("%s\n", vars->texture[i]);
	return(0);
}