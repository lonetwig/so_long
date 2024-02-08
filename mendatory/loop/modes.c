/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:25:49 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 17:21:57 by ealislam         ###   ########.fr       */
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
		display_all(info);
		info->time = 0;
	}
}

void	win(t_all *info)
{
	print_free_exit(info, "Congratulations!\n", 1);
}
