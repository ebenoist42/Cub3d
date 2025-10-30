/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:47:39 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/30 10:47:49 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game game;
	memset(&game, 0, sizeof(t_game));

	check_arg(ac, av);
	game.map = init_maps(av[1]);
	check_map_valide(game);
	free_end_of_programme(game);
}
