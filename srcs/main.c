/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:47:39 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/28 15:51:12 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game game;
	memset(&game, 0, sizeof(t_game));

	if(!check_arg(ac, av))
		return(1);
	game.map = init_maps(av[1]);
	check_map_valide(game);
	free_end_of_programme(game);
}
