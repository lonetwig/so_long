/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:35:08 by ealislam          #+#    #+#             */
/*   Updated: 2024/02/06 11:23:48 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	powerfull_mode(t_all *info)
{
	t_coordinate	*enemie;

	info->all_syncs.player.mode = POWERFUL;
	enemie = info->all_syncs.enemies;
	info->powerfull_timer = 100000;
	while (enemie)
	{
		enemie->mode = GHOST;
		enemie = enemie->next;
	}
}

static void	get_coin(t_all *info, int x, int y)
{
	t_pos	*map;
	int		n;

	map = info->map_list;
	n = (int)info->mlx;
	while (map)
	{
		if (map->x == x && map->y == y)
		{
			n = (n % (map->x * map->y)) % 20;
			map->type = '0';
			if (n < 0)
				n = n * -1;
			if (n == 0)
				powerfull_mode(info);
			if (n != 0 && n <= 15)
				(info->status.coins)++;
			if (n > 15 || n == 0)
				(info->status.coins) += 5;
			(info->map_info.coin)--;
			return ;
		}
		map = map->next;
	}
}

static void	change_move(t_coordinate *player, int key)
{
	player->move = (t_direction){0};
	if (key == 13 || key == 126)
		player->move.top = 1;
	if (key == 2 || key == 124)
		player->move.right = 1;
	if (key == 1 || key == 125)
		player->move.down = 1;
	if (key == 0 || key == 123)
		player->move.left = 1;
}

static void	increment_pos(t_all *info, int *p_x, int *p_y, int key)
{
	if (key == 13 || key == 126)
		(*p_y)--;
	if (key == 2 || key == 124)
		(*p_x)++;
	if (key == 1 || key == 125)
		(*p_y)++;
	if (key == 0 || key == 123)
		(*p_x)--;
	info->status.steps++;
}

int	get_key(int key, void *param)
{
	t_nearby	nearby;
	t_all		*info;
	int			p_x;
	int			p_y;

	info = (t_all *)param;
	p_x = info->all_syncs.player.x;
	p_y = info->all_syncs.player.y;
	get_nearby(info, p_x, p_y, &nearby);
	change_move(&info->all_syncs.player, key);
	if (check_wall(key, &nearby))
		return (0);
	increment_pos(info, &p_x, &p_y, key);
	if (check_coin(key, &nearby))
		get_coin(info, p_x, p_y);
	if (check_exit(key, &nearby) && info->map_info.coin == 0)
	{
		info->all_syncs.player.mode = WIN;
		info->time = 0;
	}
	info->all_syncs.player.x = p_x;
	info->all_syncs.player.y = p_y;
	check_death(info);
	display_all(info);
	return (0);
}
