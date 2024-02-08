/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:36:59 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:15:33 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	move_enemie_to_exit(t_all *info, t_coordinate *enemie)
{
	t_pos	*map;

	map = info->map_list;
	while (map)
	{
		if (map->type == 'E')
		{
			enemie->x = map->x;
			enemie->y = map->y;
			enemie->mode = NORMAL;
			info->status.coins += 10;
			return ;
		}
		map = map->next;
	}
}

static void	enemie_player_collision(t_all *info)
{
	t_coordinate	*enemie;
	t_coordinate	*player;

	enemie = info->all_syncs.enemies;
	player = &info->all_syncs.player;
	while (enemie)
	{
		if (enemie->x == player->x && enemie->y == player->y)
		{
			if (enemie->mode == NORMAL)
			{
				player->mode = DEAD;
			}
			if (enemie->mode == GHOST)
				move_enemie_to_exit(info, enemie);
		}
		enemie = enemie->next;
	}
}

void	check_death(t_all *info)
{
	enemie_player_collision(info);
}
