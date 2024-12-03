/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:52:22 by crocha-s          #+#    #+#             */
/*   Updated: 2024/12/03 21:00:44 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	arr_len(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int check_alpha(char *line)
{
	char *str;
	int i;
	
	str = line + 1;
	i = 0;
	while(str[i])
	{
		if((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == ',')
		{
			i++;
			continue;
		}
		else
		{
			printf("%c", str[i]);
			return (1);
		}
			
	}
	return (0);
}