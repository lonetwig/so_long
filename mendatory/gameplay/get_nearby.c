/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearby.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:46:31 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/29 09:49:54 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	assign_content(t_content *content, char type)
{
	*content = (t_content){0};
	if (type == 'P')
		content->is_player = 1;
	if (type == '1')
		content->is_wall = 1;
	if (type == 'C')
		content->is_coin = 1;
	if (type == 'E')
		content->is_exit = 1;
}

void	get_nearby(t_all *info, int x, int y, t_nearby *nearby)
{
	t_pos	*map;

	map = info->map_list;
	while (map)
	{
		if (map->x == x && map->y == y - 1)
			assign_content(&nearby->top, map->type);
		else if (map->x == x + 1 && map->y == y)
			assign_content(&nearby->right, map->type);
		else if (map->x == x && map->y == y + 1)
			assign_content(&nearby->down, map->type);
		else if (map->x == x - 1 && map->y == y)
			assign_content(&nearby->left, map->type);
		if (map->x == x + 1 && map->y == y + 1)
			return ;
		map = map->next;
	}
}
