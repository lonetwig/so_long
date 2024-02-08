/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 10:48:38 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:05:32 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

// all modes of sprites
typedef enum all_modes
{
	NORMAL,
	GHOST,
	POWERFUL,
	DEAD,
	WIN
}	t_mode;

// content of the surroundings of the sprite
typedef struct s_content
{
	int	is_player;
	int	is_wall;
	int	is_enemy;
	int	is_coin;
	int	is_exit;
}	t_content;

typedef struct s_nearby
{
	t_content	top;
	t_content	right;
	t_content	down;
	t_content	left;
}	t_nearby;

// all coordinations of the sprites
typedef struct s_direction
{
	int		top;
	int		right;
	int		down;
	int		left;
}	t_direction;

typedef struct s_coordinate
{
	int					x;
	int					y;
	int					type;
	t_mode				mode;
	t_direction			move;
	int					sprite;
	struct s_coordinate	*next;
}	t_coordinate;

typedef struct s_syncs
{
	t_coordinate	player;
	t_coordinate	*enemies;
}	t_syncs;

// all about the map
typedef struct s_pos
{
	char			type;
	int				x;
	int				y;
	int				is_valid;
	struct s_pos	*next;
}	t_pos;

typedef struct s_map_info
{
	int	width;
	int	height;
	int	pad_x;
	int	pad_y;
	int	zero;
	int	coin;
	int	enemies;
	int	exit;
	int	player;
}	t_map_info;

// HUD
typedef struct s_status
{
	int		coins;
	int		steps;
}	t_status;

// all sprites
typedef struct s_all_sprites
{
	void					*img;
	struct s_all_sprites	*next;
}	t_all_sprites;

// all game info / all the upper structs
typedef struct s_all
{
	void			*mlx;
	void			*win;
	t_map_info		map_info;
	t_pos			*map_list;
	t_status		status;
	t_syncs			all_syncs;
	t_all_sprites	*all_sprites;			
	char			*map_coords;
	int				time;
	int				powerfull_timer;
	int				last_command;
}	t_all;

void	check_map(t_all *info);
void	map(t_all *info, char *map_path);
void	check_path(t_all *info);
void	display_all(t_all *info);
void	display_sprite(t_all *info, char *path, int x, int y);
void	display_map(t_all *info, int wall_only);
void	display_hud(t_all *info);
void	display_player(t_all *info);
void	get_player_pos(t_all *info);
void	initialize_info(t_all *info, char *path);
int		get_key(int key, void *param);
void	get_nearby(t_all *info, int x, int y, t_nearby *nearby);
int		check_wall(int key, t_nearby *nearby);
int		check_coin(int key, t_nearby *nearby);
int		check_exit(int key, t_nearby *nearby);
int		check_enemy(int key, t_nearby *nearby);
void	init_map_coordinations(t_all *info);
void	free_sprites(t_all *info, t_all_sprites *sprites);
int		loop(void *param);
int		change_command(int key, void *param);
void	get_enemies_pos(t_all *info);
void	enemies(t_all *all);
int		enemie_next_move(t_all *info, t_coordinate *enemie, int *ran_i);
void	display_enemies(t_all *info);
void	check_death(t_all *info);
void	normal(t_all *info, int multi);
void	display_death(t_all *info, char *str);
void	dead(t_all *info);
void	powerfull(t_all *info);
void	win(t_all *info);
void	free_all(t_all *info, t_all_sprites *sprites);
void	print_free_exit(t_all *info, char *str, int fd);
void	print_steps(t_all *info);

#endif