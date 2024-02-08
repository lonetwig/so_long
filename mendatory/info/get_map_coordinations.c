/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_coordinations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:21:25 by ealislam          #+#    #+#             */
/*   Updated: 2024/02/05 14:08:57 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	find_wall_type(t_direction *w_type, t_all *info, int x, int y)
{
	t_pos	*map;

	map = info->map_list;
	*w_type = (t_direction){0};
	while (map)
	{
		if (map->y == y - 1 && map->x == x && map->type == '1')
			w_type->top = 1;
		if (map->y == y && map->x == x + 1 && map->type == '1')
			w_type->right = 1;
		if (map->y == y + 1 && map->x == x && map->type == '1')
			w_type->down = 1;
		if (map->y == y && map->x == x - 1 && map->type == '1')
			w_type->left = 1;
		map = map->next;
	}
}

static void	add_to_str2(t_all *info, int i, t_direction *w_type, t_pos *map)
{
	int	x_size;
	int	y_size;

	x_size = (map->x + 1 +(info->map_info.pad_x / 2)) * 32;
	y_size = (map->y + 3 +(info->map_info.pad_y / 2)) * 32;
	if (w_type->top && !w_type->right && w_type->down && w_type->left)
		info->map_coords[i] = '8';
	else if (w_type->top && !w_type->right && w_type->down && !w_type->left)
		info->map_coords[i] = '9';
	else if (w_type->top && w_type->right && w_type->down && !w_type->left)
		info->map_coords[i] = 'a';
	else if (w_type->top && w_type->right && !w_type->down && w_type->left)
		info->map_coords[i] = 'b';
	else if (w_type->top && w_type->right && !w_type->down && !w_type->left)
		info->map_coords[i] = 'c';
	else if (w_type->top && !w_type->right && !w_type->down && !w_type->left)
		info->map_coords[i] = 'd';
	else if (!w_type->top && w_type->right && !w_type->down && !w_type->left)
		info->map_coords[i] = 'e';
	else if (!w_type->top && !w_type->right && !w_type->down && w_type->left)
		info->map_coords[i] = 'f';
	else
		info->map_coords[i] = 'x';
}

static void	add_to_str(t_all *info, int i, t_direction *w_type, t_pos *map)
{
	int	x_size;
	int	y_size;

	x_size = (map->x + 1 +(info->map_info.pad_x / 2)) * 32;
	y_size = (map->y + 3 +(info->map_info.pad_y / 2)) * 32;
	if (!w_type->top && !w_type->right && !w_type->down && !w_type->left)
		info->map_coords[i] = '1';
	else if (!w_type->top && !w_type->right && w_type->down && w_type->left)
		info->map_coords[i] = '2';
	else if (!w_type->top && !w_type->right && w_type->down && !w_type->left)
		info->map_coords[i] = '3';
	else if (w_type->top && !w_type->right && !w_type->down && w_type->left)
		info->map_coords[i] = '4';
	else if (!w_type->top && w_type->right && w_type->down && w_type->left)
		info->map_coords[i] = '5';
	else if (!w_type->top && w_type->right && w_type->down && !w_type->left)
		info->map_coords[i] = '6';
	else if (!w_type->top && w_type->right && !w_type->down && w_type->left)
		info->map_coords[i] = '7';
	else
		add_to_str2(info, i, w_type, map);
}

void	init_map_coordinations(t_all *info)
{
	t_direction	w_type;
	int			num;
	int			count_poses;
	t_pos		*map;
	int			y;

	num = (info->map_info.height + 1) * (info->map_info.width + 1);
	map = info->map_list;
	info->map_coords = malloc(num + 1);
	if (!info->map_coords)
		print_free_exit(info, "Error\n Malloc have failed.", 2);
	info->map_coords[num] = '\0';
	while (map)
	{
		if (map->y > 0)
			y = map->y;
		else
			y = 0;
		count_poses = (((info->map_info.width + 1) * y) + map->x);
		find_wall_type(&w_type, info, map->x, map->y);
		add_to_str(info, count_poses, &w_type, map);
		map = map->next;
	}
}
