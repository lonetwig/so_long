/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:09 by ealislam          #+#    #+#             */
/*   Updated: 2024/02/05 14:59:50 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	loop(void *param)
{
	t_all	*info;
	int		multi;

	info = (t_all *)param;
	multi = ((info->map_info.width + info->map_info.height) / 2) / 10;
	if (multi < 2)
		multi = 1;
	(info->time) += multi;
	if (info->all_syncs.player.mode == WIN)
		win(info);
	else if (info->all_syncs.player.mode == NORMAL)
		normal(info, multi);
	return (0);
}
