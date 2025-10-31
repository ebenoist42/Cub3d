/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:15:18 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/31 10:31:00 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	all_tokens_are_one(t_token token)
{
	if (token.NO != 1)
		return (0);
	if (token.SO != 1)
		return (0);
	if (token.WE != 1)
		return (0);
	if (token.EA != 1)
		return (0);
	if (token.F != 1)
		return (0);
	if (token.C != 1)
		return (0);
	return (1);
}

static t_token	check_texture_color(char *map, t_token token, int j)
{
	while (map[j] && !all_tokens_are_one(token))
	{
		while (map[j] && ft_isspace(map[j]))
			j++;
		if (!map[j])
			return (token);
		if (!strncmp(&map[j], "NO ", 3))
			token.NO++;
		else if (!strncmp(&map[j], "WE ", 3))
			token.WE++;
		else if (!strncmp(&map[j], "EA ", 3))
			token.EA++;
		else if (!strncmp(&map[j], "SO ", 3))
			token.SO++;
		else if (!strncmp(&map[j], "C ", 2))
			token.C++;
		else if (!strncmp(&map[j], "F ", 2))
			token.F++;
		else
			token.error++;
		break ;
	}
	return (token);
}

static int	check_texture(char **map, int i)
{
	t_token	token;

	memset(&token, 0, sizeof(t_token));
	while (map[i] && !all_tokens_are_one(token))
	{
		token = check_texture_color(map[i], token, 0);
		i++;
	}
	if (token.EA == 1 && token.WE == 1 && token.SO == 1 && token.NO == 1
		&& token.C == 1 && token.F == 1 && token.error == 0)
		return (i);
	return (0);
}

int	check_map_valide(t_game game)
{
	int		i;
	char	**map;

	i = 0;
	map = game.map;
	i = check_texture(map, i);
	if (i == 0)
	{
		ft_putstr_fd("Error\nMap invalide, bad texture/colors\n", 2);
		free_end_of_programme(game);
	}
	if (!check_map(map, i, 0, 0))
	{
		ft_putstr_fd("Error\nMap invalide\n", 2);
		free_end_of_programme(game);
	}
	return (1);
}
