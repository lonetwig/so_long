/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:18:02 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/29 09:41:31 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	display_all(t_all *info)
{
	free_sprites(info, info->all_sprites);
	if (info->mlx && info->win)
		mlx_clear_window(info->mlx, info->win);
	display_map(info, 0);
	display_player(info);
}
