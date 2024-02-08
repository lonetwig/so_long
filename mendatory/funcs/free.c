/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:42:46 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/29 09:45:04 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_sprites(t_all *info, t_all_sprites *sprites)
{
	t_all_sprites	*tmp;

	while (sprites)
	{
		mlx_destroy_image(info->mlx, sprites->img);
		sprites->img = NULL;
		tmp = sprites;
		sprites = sprites->next;
		free(tmp);
	}
	info->all_sprites = NULL;
}

static void	free_map(t_pos *map_list)
{
	t_pos	*tmp;

	while (map_list)
	{
		tmp = map_list;
		map_list = map_list->next;
		free(tmp);
	}
}

void	free_all(t_all *info, t_all_sprites *sprites)
{
	if (info && info->map_list)
		free_map(info->map_list);
	if (sprites)
		free_sprites(info, sprites);
	if (info->map_coords)
		free(info->map_coords);
}
