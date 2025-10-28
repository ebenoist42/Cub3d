/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:49:09 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/28 15:15:36 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_arg(int ac, char **av)
{
	size_t	len;

	if (ac == 1)
		return (printf("Error\nNo Maps Provided\n"), 0);
	if (ac == 2)
	{
		len = strlen(av[1]);
		if (ft_strncmp(av[1] + (len - 4), ".cub", 4))
			return (printf("Error\nWrong Maps Provided\n"), 0);
	}
	if (ac > 2)
		return (printf("Error\nToo Much Arguments\n"), 0);
	return (1);
}
