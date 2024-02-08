/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:26:25 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 16:31:27 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	display_wall2(t_all *info, int x, int y, char coord)
{
	int			x_size;
	int			y_size;

	x_size = (x + 1 +(info->map_info.pad_x / 2)) * 32;
	y_size = (y + 3 +(info->map_info.pad_y / 2)) * 32;
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
	coord = info->map_coords[(((info->map_info.width + 1) * j) + x)];
	x_size = (x + 1 +(info->map_info.pad_x / 2)) * 32;
	y_size = (y + 3 +(info->map_info.pad_y / 2)) * 32;
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
		display_wall2(info, x, y, coord);
}

static void	display_coin(t_all *info, t_pos *map, int x_pad, int y_pad)
{
	int	n;

	n = (int)info->mlx;
	n = (n % (map->x * map->y)) % 20;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		display_sprite(info, "./xpm/coin6.xpm", x_pad + map->x * 32, \
			y_pad + map->y * 32);
	else if (n != 0 && n <= 15)
		display_sprite(info, "./xpm/coin1.xpm", x_pad + map->x * 32, \
			y_pad + map->y * 32);
	else if (n == 16)
		display_sprite(info, "./xpm/coin2.xpm", x_pad + map->x * 32, \
			y_pad + map->y * 32);
	else if (n == 17)
		display_sprite(info, "./xpm/coin3.xpm", x_pad + map->x * 32, \
			y_pad + map->y * 32);
	else if (n == 18)
		display_sprite(info, "./xpm/coin4.xpm", x_pad + map->x * 32, \
			y_pad + map->y * 32);
	else if (n == 19)
		display_sprite(info, "./xpm/coin5.xpm", x_pad + map->x * 32, \
			y_pad + map->y * 32);
}

void	display_map(t_all *info, int wall_only)
{
	t_pos	*map;
	int		x_pad;
	int		y_pad;

	map = info->map_list;
	x_pad = (1 + (info->map_info.pad_x / 2)) * 32;
	y_pad = (3 + (info->map_info.pad_y / 2)) * 32;
	while (map)
	{
		if (map->type == '1')
			display_wall(info, map->x, map->y);
		else if (map->type == 'E' && info->map_info.coin <= 0 && !wall_only)
			display_sprite(info, "./xpm/end_full.xpm", x_pad + map->x * 32, \
				y_pad + map->y * 32);
		else if (map->type == 'E' && info->map_info.coin > 0 && !wall_only)
			display_sprite(info, "./xpm/end_empty.xpm", x_pad + map->x * 32, \
				y_pad + map->y * 32);
		else if (map->type == 'C' && !wall_only)
			display_coin(info, map, x_pad, y_pad);
		map = map->next;
	}
}
