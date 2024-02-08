/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemies_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:08:53 by ealislam          #+#    #+#             */
/*   Updated: 2024/02/07 08:58:49 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	get_length(char *path1, char *path2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (path1[i])
		i++;
	while (path2[j])
		j++;
	return (i + j);
}

static char	*merge_paths(t_all *info, char *path1, char *path2)
{
	char	*path3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path3 = malloc(get_length(path1, path2) + 1);
	if (!path3)
		print_free_exit(info, "Error\n Malloc failed.\n", 2);
	while (path1[i])
	{
		path3[i] = path1[i];
		i++;
	}
	while (path2[j])
	{
		path3[i + j] = path2[j];
		j++;
	}
	path3[i + j] = '\0';
	return (path3);
}

static char	*get_path(t_all *info, t_coordinate *enemie)
{
	char	*path1;
	char	*path2;
	char	*path3;

	path1 = NULL;
	path2 = NULL;
	path3 = NULL;
	if (enemie->type == 1)
		path1 = "./xpm/e1_";
	else if (enemie->type == 2)
		path1 = "./xpm/e2_";
	else if (enemie->type == 3)
		path1 = "./xpm/e3_";
	else if (enemie->type == 4)
		path1 = "./xpm/e4_";
	if (enemie->sprite == 1)
		path2 = "top.xpm";
	else if (enemie->sprite == 2)
		path2 = "right.xpm";
	else if (enemie->sprite == 3)
		path2 = "down.xpm";
	else if (enemie->sprite == 4)
		path2 = "left.xpm";
	return (merge_paths(info, path1, path2));
}

static int	check_ghost(int p_timer)
{
	if (p_timer > 25000)
		return (1);
	if ((p_timer < 25000 && p_timer > 22000) || \
	(p_timer < 20000 && p_timer > 17000) || \
	(p_timer < 15000 && p_timer > 12000) || \
	(p_timer < 10000 && p_timer > 7000) || \
	(p_timer < 5000 && p_timer > 2000))
		return (1);
	return (0);
}

void	display_enemies(t_all *info)
{
	t_coordinate	*enemie;
	int				x_pad;
	int				y_pad;
	char			*path;

	enemie = info->all_syncs.enemies;
	while (enemie)
	{
		x_pad = (1 + (info->map_info.pad_x / 2)) * 32;
		y_pad = (3 + (info->map_info.pad_y / 2)) * 32;
		if (enemie->mode == NORMAL || !check_ghost(info->powerfull_timer))
		{
			path = get_path(info, enemie);
			display_sprite(info, path, x_pad + enemie->x * 32, \
				y_pad + enemie->y * 32);
			if (path)
				free(path);
		}
		else
			display_sprite(info, "./xpm/ghost.xpm", x_pad + enemie->x * 32, \
				y_pad + enemie->y * 32);
		enemie = enemie->next;
	}
}
