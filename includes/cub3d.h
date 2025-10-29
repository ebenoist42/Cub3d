/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:46:26 by ebenoist          #+#    #+#             */
/*   Updated: 2025/10/29 14:44:22 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
#define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;
	void	*img_wall_no;
	void	*img_wall_ea;
	void	*img_wall_so;
	void	*img_wall_we;
	void	*img_floor;
	void	*img_player;
	void	*img_enemy; //bonus
}	t_game;

typedef struct s_token
{
	int NO;
	int SO;
	int WE;
	int EA;
	int F;
	int C;
	int error;
	
}	t_token;


//Parsing
int	check_arg(int ac, char **av);
int	check_map_valide(t_game game);
int	check_map(char **map, int i, int j);

//Init
char**	init_maps(char *av);

//Error
void	free_end_of_programme(t_game game);
void	ft_error_file(void);
void	ft_error_malloc(char **map);
void	free_map(char **map);

#endif