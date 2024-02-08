/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:08:51 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:21:50 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	get_player_pos(t_all *info)
{
	t_pos	*map;

	map = info->map_list;
	while (map)
	{
		if (map->type == 'P')
		{
			info->all_syncs.player.x = map->x;
			info->all_syncs.player.y = map->y;
			info->all_syncs.player.mode = NORMAL;
			info->all_syncs.player.sprite = 1;
			info->all_syncs.player.move = (t_direction){0};
			info->all_syncs.player.move.right = 1;
			map->type = '0';
			return ;
		}
		map = map->next;
	}
}
