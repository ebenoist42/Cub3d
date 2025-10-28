/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:27:48 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/28 15:32:12 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error_file(void)
{
	write(2, "Error\nWrong File\n", 17);
	exit(1);
}

void	ft_error_malloc(char **map)
{
	if (map)
		free_map(map);
	write(2, "Error\nMemory Allocation Error\n", 31);
	exit(1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
