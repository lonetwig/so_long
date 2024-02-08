/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:13:10 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/29 10:41:35 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	initialize_all_null(t_all *info)
{
	info->mlx = NULL;
	info->win = NULL;
	info->map_list = NULL;
	info->all_sprites = NULL;
	info->map_coords = NULL;
}

void	initialize_info(t_all *info, char *path)
{
	int	x_size;
	int	y_size;

	initialize_all_null(info);
	map(info, path);
	if (info->map_info.height > 35 || info->map_info.width > 60)
		print_free_exit(info, "Error\n map is too large.\n", 2);
	x_size = (info->map_info.width + info->map_info.pad_x + 1) * 32;
	y_size = (info->map_info.height + info->map_info.pad_y + 1) * 32;
	get_player_pos(info);
	info->time = 0;
	info->powerfull_timer = 0;
	info->status = (t_status){0};
	init_map_coordinations(info);
	info->all_sprites = NULL;
	info->last_command = 2;
	info->mlx = mlx_init();
	if (!info->mlx)
		print_free_exit(info, "Error\n mlx failed.\n", 2);
	info->win = mlx_new_window(info->mlx, x_size, y_size, "PACMAN");
	if (!info->win)
		print_free_exit(info, "Error\n mlx window failed.\n", 2);
}
