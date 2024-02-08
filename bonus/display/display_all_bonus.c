/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:18:02 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:06:12 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	display_all(t_all *info)
{
	free_sprites(info, info->all_sprites);
	if (info->mlx && info->win)
		mlx_clear_window(info->mlx, info->win);
	display_map(info, 0);
	display_hud(info);
	display_player(info);
	display_enemies(info);
}
