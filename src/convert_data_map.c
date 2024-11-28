/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_data_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:52:08 by crocha-s          #+#    #+#             */
/*   Updated: 2024/11/28 18:36:41 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	rgb_to_hex(int *rgb)
{
	int	color;

	color = (rgb[0] << 16 | rgb[1] << 8
			| rgb[2]);
	return (color);
}

static int	are_color_valid(t_game *game)
{
	int	i;
	int	*color;
	int	*color2;

	i = 0;
	color = game->map->ceiling;
	while (color[i] && i < 3)
	{
		if (color[i] > 255 || color[i] < 0)
			return (ft_print_err("Error: Ceiling color index is not valid."));
		i++;
	}
	if (i < 2)
		return (ft_print_err("Error: Ceiling color is missing values."));
	i = 0;
	color2 = game->map->floor;
	while (color2[i] && i < 3)
	{
		if (color2[i] > 255 || color2[i] < 0)
			return (ft_print_err("Error: Floor color index is not valid."));
		i++;
	}
	if (i < 2)
		return (ft_print_err("Error: Floor color is missing values."));
	return (0);
}

static void	read_fc_color(t_game *game, char *line)
{
	char	**temp;
	char	*trimmed;
	int		i;
	
	trimmed = ft_strtrim(line, " ");
	i = -1;
	if (!ft_strncmp(trimmed, "F ", 1))
	{
		temp = ft_split(trimmed + 1, ',');
		while (temp[++i])
			game->map->floor[i] = ft_atoi(temp[i]);
		free_arr(temp);
		game->map->f_color = rgb_to_hex(game->map->floor);
	}
	i = -1;
	if (!ft_strncmp(trimmed, "C ", 1))
	{
		temp = ft_split(trimmed + 1, ',');
		while (temp[++i])
			game->map->ceiling[i] = ft_atoi(temp[i]);
		free_arr(temp);
		game->map->c_color = rgb_to_hex(game->map->ceiling);
	}
	free(trimmed);
}

static int check_duplicates(char **map_arr)
{
	int	path_counter;
	int color_counter;
	int	i;
	char*	trimmed;
	
	path_counter = 0;
	color_counter = 0;
	i = 0;
	while(map_arr[i])
	{
		trimmed = ft_strtrim(map_arr[i], " ");
		if (!ft_strncmp(trimmed,"NO", 2))
			path_counter++;
		if (!ft_strncmp(trimmed,"SO", 2))
			path_counter++;
		if (!ft_strncmp(trimmed,"WE", 2))
			path_counter++;
		if (!ft_strncmp(trimmed,"EA", 2))
			path_counter++;
		if (!ft_strncmp(trimmed,"F", 1))
			color_counter++;
		if (!ft_strncmp(trimmed,"C", 1))
			color_counter++;
		free(trimmed);
		i++;
	}
	if (path_counter > 4 || color_counter > 2)
		return (ft_print_err("Error: Duplicated paths or colors detected."));
	
}
int	convert_data_map(t_game *game, char *temp_raw_map)
{
	char		**map_arr;
	char		**map_matrix;
	int			i;

	i = 0;
	map_arr = ft_split(temp_raw_map, '\n');
	
	if (check_duplicates(map_arr) != 0 || check_tex_path(game, map_arr) != 0)
	{
		free_arr(map_arr);
		return (1);
	}
	while (map_arr[i])
		read_fc_color(game, map_arr[i++]);
	free_arr(map_arr);
	map_matrix = ft_split(temp_raw_map, '\n');
	if (are_color_valid(game) != 0 || parse_map_matrix(map_matrix, game) != 0)
	{
		free_arr(map_matrix);
		return (1);
	}
	free_arr(map_matrix);
	return (0);
}
