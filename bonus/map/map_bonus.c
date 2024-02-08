/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:32:44 by ealislam          #+#    #+#             */
/*   Updated: 2024/02/07 08:49:42 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	add_pos(t_all *info, char type, int x, int y)
{
	t_pos	*new_pos;
	t_pos	*tmp;

	if (type == '\n' && x != 0)
		return ;
	if (type == '\n' && x == 0)
		print_free_exit(info, "Error\n Map is invalid.\n", 2);
	new_pos = malloc(sizeof(t_pos));
	if (!new_pos)
		print_free_exit(info, "Error\n Malloc failed.\n", 2);
	new_pos->x = x;
	new_pos->y = y;
	new_pos->type = type;
	new_pos->next = NULL;
	new_pos->is_valid = 0;
	if (!info->map_list)
	{
		info->map_list = new_pos;
		return ;
	}
	tmp = info->map_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_pos;
}

static void	generate_map(t_all *info, char *map_path)
{
	char	*map_line;
	int		map_fd;
	int		x;
	int		y;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
		print_free_exit(info, "Error\n Open failed. The file passed \
may not be existing.\n", 2);
	map_line = get_next_line(map_fd);
	y = 0;
	while (map_line)
	{
		x = 0;
		while (map_line[x])
		{
			add_pos(info, map_line[x], x, y);
			x++;
		}
		y++;
		free(map_line);
		map_line = get_next_line(map_fd);
	}
}

static void	add_padding(t_map_info *map_info)
{
	if (map_info->width < 14)
		map_info->pad_x = 14 - map_info->width;
	if (map_info->height < 6)
		map_info->pad_y = 6 - map_info->height;
}

void	map(t_all *info, char *map_path)
{
	t_pos	*map_list;

	map_list = NULL;
	generate_map(info, map_path);
	check_map(info);
	add_padding(&info->map_info);
}
