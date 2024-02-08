/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:26:25 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 17:16:19 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	display_wall2(t_all *info, int x_size, int y_size, char coord)
{
	if (coord == '6')
		display_sprite(info, "./xpm/wall_r_d.xpm", x_size, y_size);
	else if (coord == '7')
		display_sprite(info, "./xpm/wall_r_l.xpm", x_size, y_size);
	else if (coord == '8')
		display_sprite(info, "./xpm/wall_t_d_l.xpm", x_size, y_size);
	else if (coord == '9')
		display_sprite(info, "./xpm/wall_t_d.xpm", x_size, y_size);
	else if (coord == 'a')
		display_sprite(info, "./xpm/wall_t_r_d.xpm", x_size, y_size);
	else if (coord == 'b')
		display_sprite(info, "./xpm/wall_t_r_l.xpm", x_size, y_size);
	else if (coord == 'c')
		display_sprite(info, "./xpm/wall_t_r.xpm", x_size, y_size);
	else if (coord == 'd')
		display_sprite(info, "./xpm/wall_t.xpm", x_size, y_size);
	else if (coord == 'e')
		display_sprite(info, "./xpm/wall_r.xpm", x_size, y_size);
	else if (coord == 'f')
		display_sprite(info, "./xpm/wall_l.xpm", x_size, y_size);
}

static void	display_wall(t_all *info, int x, int y)
{
	int			x_size;
	int			y_size;
	int			j;
	char		coord;

	if (y > 0)
		j = y;
	else
		j = 0;
	x_size = (x + 1) * 32;
	y_size = (y + 1) * 32;
	coord = info->map_coords[(((info->map_info.width + 1) * j) + x)];
	if (coord == '1')
		display_sprite(info, "./xpm/wall_.xpm", x_size, y_size);
	else if (coord == '2')
		display_sprite(info, "./xpm/wall_d_l.xpm", x_size, y_size);
	else if (coord == '3')
		display_sprite(info, "./xpm/wall_d.xpm", x_size, y_size);
	else if (coord == '4')
		display_sprite(info, "./xpm/wall_l_t.xpm", x_size, y_size);
	else if (coord == '5')
		display_sprite(info, "./xpm/wall_r_d_l.xpm", x_size, y_size);
	else
		display_wall2(info, x_size, y_size, coord);
}

static void	display_coin(t_all *info, t_pos *map)
{
	int	n;

	n = (int)info->mlx;
	n = (n % (map->x * map->y)) % 20;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		display_sprite(info, "./xpm/coin6.xpm", (1 + map->x) * 32, \
		(1 + map->y) * 32);
	else if (n != 0 && n <= 15)
		display_sprite(info, "./xpm/coin1.xpm", (1 + map->x) * 32, \
		(1 + map->y) * 32);
	else if (n == 16)
		display_sprite(info, "./xpm/coin2.xpm", (1 + map->x) * 32, \
		(1 + map->y) * 32);
	else if (n == 17)
		display_sprite(info, "./xpm/coin3.xpm", (1 + map->x) * 32, \
		(1 + map->y) * 32);
	else if (n == 18)
		display_sprite(info, "./xpm/coin4.xpm", (1 + map->x) * 32, \
		(1 + map->y) * 32);
	else if (n == 19)
		display_sprite(info, "./xpm/coin5.xpm", (1 + map->x) * 32, \
		(1 + map->y) * 32);
}

void	display_map(t_all *info, int wall_only)
{
	t_pos	*map;

	map = info->map_list;
	while (map)
	{
		if (map->type == '1')
			display_wall(info, map->x, map->y);
		else if (map->type == 'E' && info->map_info.coin <= 0 && !wall_only)
			display_sprite(info, "./xpm/end_full.xpm", (1 + map->x) * 32, \
				(1 + map->y) * 32);
		else if (map->type == 'E' && info->map_info.coin > 0 && !wall_only)
			display_sprite(info, "./xpm/end_empty.xpm", (1 + map->x) * 32, \
				(1 + map->y) * 32);
		else if (map->type == 'C' && !wall_only)
			display_coin(info, map);
		map = map->next;
	}
}
