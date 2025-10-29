/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:45:52 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/29 15:20:41 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	check_good_char(char j)
{
	if(j == '1' || j == '0' || j == 'N' || j == 'S' || j == 'E' || j == 'W')
		return(1);
	else if (ft_isspace(j))
		return(1);
	else
		return(0);
}

static	int	check_char(char *map, int j)
{
	while(map[j])
	{
		if(!check_good_char(map[j]))
			return(0);
		if(map[j] == '0' && map[j + 1] == ' ')
			return(0);
		j++;
	}
	return(1);
}


static	int find_first_wall(char **map, int i, int j)
{
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			while(ft_isspace(map[i][j]))
				j++;
			if(check_good_char(map[i][j]))
				return(i);
			j++;
		}
		i++;
	}
	return(-1);
}

int	check_first_wall(char **map, int i, int j)
{
	while(map[i][j])
	{
		while(ft_isspace(map[i][j]))
			j++;
		if(map[i][j] != '1' && map[i][j] != '\0')
			return(write(2,"Error\nFirst Wall Invalid\n", 26),0);
		j++;
	}
	i++;
	return(1);		
}

int	check_map(char **map, int i, int j)
{
	j = i;
	while(map[i])
	{
		if(!check_char(map[i], 0))
			return(0);
		i++;
	}
	i = find_first_wall(map, j, 0);
	if(i < 0)
		return(0);
	if(!check_first_wall(map, i, 0))
		return(0);
	/*while(map[i])
	{
		if(!check_wall(map, i, 0))
			return(printf("ok\n"),0);
		i++;
	}*/
	return(1);
}
