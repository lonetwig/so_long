/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:29:10 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/29 09:36:51 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	find_player(t_pos **map_list)
{
	t_pos	*tmp;

	tmp = *map_list;
	while (tmp)
	{
		if (tmp->type == 'P')
		{
			*map_list = tmp;
			return ;
		}
		tmp = tmp->next;
	}
}

static t_pos	*get_node(t_pos *map_list, int x, int y)
{
	while (map_list)
	{
		if (map_list->x == x && map_list->y == y)
		{
			if (map_list->is_valid || map_list->type == '1')
				return (NULL);
			map_list->is_valid = 1;
			return (map_list);
		}
		map_list = map_list->next;
	}
	return (NULL);
}

static void	validate_pos(t_pos *head, t_pos *node, t_map_info *info)
{
	if (!node || node->x == info->width || node->y == info->height || \
	node->x == 0 || node->y == 0)
		return ;
	if (node->y != 0 && node->type != 1)
		validate_pos(head, get_node(head, node->x, node->y - 1), info);
	if (node->x != info->width && node->type != 1)
		validate_pos(head, get_node(head, node->x + 1, node->y), info);
	if (node->y != info->height && node->type != 1)
		validate_pos(head, get_node(head, node->x, node->y + 1), info);
	if (node->x != 0 && node->type != 1)
		validate_pos(head, get_node(head, node->x - 1, node->y), info);
}

static void	check_if_valid(t_all *info, t_pos *map)
{
	t_pos	*head;

	head = map;
	while (map)
	{
		if ((map->type == 'P' || map->type == 'C' || map->type == 'E') && \
		map->is_valid == 0)
			print_free_exit(info, "Error\n Map is invalid.\n", 2);
		map = map->next;
	}
}

void	check_path(t_all *info)
{
	t_pos	*player_node;

	player_node = info->map_list;
	find_player(&player_node);
	validate_pos(info->map_list, player_node, &info->map_info);
	check_if_valid(info, info->map_list);
}
