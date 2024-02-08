/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:50:19 by ealislam          #+#    #+#             */
/*   Updated: 2024/02/06 10:49:33 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	get_map_props(t_map_info *map_info, char c)
{
	if (c != 'C' && c != 'P' && c != 'E' && c != '1' && c != '0')
		return (1);
	else if (c == 'C')
		(map_info->coin)++;
	else if (c == 'P')
		(map_info->player)++;
	else if (c == 'E')
		(map_info->exit)++;
	return (0);
}

static void	check_props(t_all *info)
{
	int		c;
	int		p;
	int		e;
	int		f;
	t_pos	*tmp;

	c = 0;
	p = 0;
	e = 0;
	f = 0;
	tmp = info->map_list;
	while (tmp)
	{
		if (tmp->type == 'C')
			c++;
		if (tmp->type == 'P')
			p++;
		if (tmp->type == 'E')
			e++;
		tmp = tmp->next;
	}
	if (c == 0 || p != 1 || e != 1)
		print_free_exit(info, "Error\n Map is invalid.\n", 2);
}

static void	check_dimentions(t_all *info, t_pos *map, t_map_info *map_info)
{
	while (map)
	{
		if ((map->y == 0 && map->type != '1') || \
		(map->x == 0 && map->type != '1') || \
		(map->x == map_info->width && map->type != '1') || \
		(map->y == map_info->height && map->type != '1'))
			print_free_exit(info, "Error\n Map is invalid.\n", 2);
		map = map->next;
	}
}

static void	get_map_info(t_all *info, t_map_info *map_info)
{
	t_pos	*tmp;

	tmp = info->map_list;
	*map_info = (t_map_info){0};
	while (tmp)
	{
		if (get_map_props(map_info, tmp->type))
			print_free_exit(info, "Error\n Map is invalid.\n", 2);
		if (!tmp->next)
			print_free_exit(info, "Error\n Map is invalid\n", 2);
		if (tmp->next && tmp->x >= tmp->next->x)
			break ;
		tmp = tmp->next;
		map_info->width = tmp->x;
	}
	while (tmp)
	{
		if ((tmp->x > map_info->width) || \
		(tmp->next && tmp->next->y > tmp->y && tmp->x != map_info->width) || \
		(!(tmp->next) && tmp->x != map_info->width) || \
		get_map_props(map_info, tmp->type))
			print_free_exit(info, "Error\n Map is invalid.\n", 2);
		map_info->height = tmp->y;
		tmp = tmp->next;
	}
}

void	check_map(t_all *info)
{
	if (!info->map_list)
		print_free_exit(info, "Error\n Map is invalid.\n", 2);
	get_map_info(info, &info->map_info);
	check_props(info);
	check_dimentions(info, info->map_list, &info->map_info);
	check_path(info);
}
