/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:22:16 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:11:36 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	add_sprit_to_list(t_all *info, void *img)
{
	t_all_sprites	*tmp;
	t_all_sprites	*node;

	node = malloc(sizeof(t_all_sprites));
	if (!node)
		print_free_exit(info, "Error\n Malloc failed.\n", 2);
	node->img = img;
	node->next = NULL;
	tmp = info->all_sprites;
	if (!tmp)
	{
		info->all_sprites = node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	display_sprite(t_all *info, char *path, int x, int y)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(info->mlx, path, &width, &height);
	if (!img)
		print_free_exit(info, "Error\n Image allocation failed.\n", 2);
	mlx_put_image_to_window(info->mlx, info->win, img, x, y);
	add_sprit_to_list(info, img);
}
