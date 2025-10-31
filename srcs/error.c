/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:27:48 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/31 10:29:53 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error_file(void)
{
	ft_putstr_fd("Error\nWrong File\n", 2);
	exit(1);
}

void	ft_error_malloc(char **map)
{
	if (map)
		free_map(map);
	ft_putstr_fd("Error\nMemory Allocation Error\n", 2);
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
