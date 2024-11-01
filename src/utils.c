/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:52:22 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/20 17:20:05 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_perror(char *msg, t_game *game)
{
	int	i;

	i = -1;
	printf("%s", msg);
	if (!game)
		exit (EXIT_FAILURE);
	while (++i < 4)
	{
		if (game->render[i].image.img_ptr)
			mlx_destroy_image(game->mlx, game->render[i].image.img_ptr);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free (game->mlx);
	}
	if (game->map->map_matrix)
		free_arr(game->map->map_matrix);
	exit (EXIT_SUCCESS);
}

int	arr_len(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
