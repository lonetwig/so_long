/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:25:49 by ealislam          #+#    #+#             */
/*   Updated: 2024/02/07 08:41:51 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	normal(t_all *info, int multi)
{
	if (info->time >= 1000 && info->time < 1000 + multi)
	{
		info->all_syncs.player.sprite = 1;
		display_player(info);
	}
	else if (info->time >= 2000 && info->time < 2000 + multi)
	{
		info->all_syncs.player.sprite = 2;
		get_key(info->last_command, info);
		enemies(info);
		display_all(info);
	}
	else if (info->time >= 3000 && info->time < 3000 + multi)
	{
		info->all_syncs.player.sprite = 3;
		display_player(info);
	}
	else if (info->time >= 4000 && info->time < 4000 + multi)
	{
		info->all_syncs.player.sprite = 2;
		get_key(info->last_command, info);
		enemies(info);
		display_all(info);
		info->time = 0;
	}
}

void	display_death(t_all *info, char *str)
{
	int	x;
	int	y;
	int	x_pad;
	int	y_pad;

	x = info->all_syncs.player.x;
	y = info->all_syncs.player.y;
	x_pad = (1 + (info->map_info.pad_x / 2)) * 32;
	y_pad = (3 + (info->map_info.pad_y / 2)) * 32;
	free_sprites(info, info->all_sprites);
	mlx_clear_window(info->mlx, info->win);
	display_map(info, 1);
	display_hud(info);
	display_sprite(info, str, x_pad + x * 32, y_pad + y * 32);
}

void	dead(t_all *info)
{
	if (info->time == 1000)
		display_death(info, "./xpm/p_death1.xpm");
	else if (info->time == 10000)
		display_death(info, "./xpm/p_death2.xpm");
	else if (info->time == 11000)
		display_death(info, "./xpm/p_death3.xpm");
	else if (info->time == 12000)
		display_death(info, "./xpm/p_death4.xpm");
	else if (info->time == 13000)
		display_death(info, "./xpm/p_death5.xpm");
	else if (info->time == 15000)
		print_free_exit(info, "You lost.\n", 1);
}

void	powerfull(t_all *info)
{
	t_coordinate	*enemie;

	(info->powerfull_timer)--;
	if (info->powerfull_timer <= 0)
	{
		info->all_syncs.player.mode = NORMAL;
		enemie = info->all_syncs.enemies;
		while (enemie)
		{
			enemie->mode = NORMAL;
			enemie = enemie->next;
		}
	}
}

void	win(t_all *info)
{
	if (info->time == 1)
	{
		free_sprites(info, info->all_sprites);
		mlx_clear_window(info->mlx, info->win);
	}
	if (info->time == 2000)
		display_sprite(info, "./xpm/win.xpm", ((info->map_info.width + \
		info->map_info.pad_x) / 2) * 32 - 60, ((info->map_info.height + \
		info->map_info.pad_y) / 2) * 32 + 50);
	if (info->time == 20000)
		print_free_exit(info, "Congratulations!\n", 1);
}
