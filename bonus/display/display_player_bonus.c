/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:25:56 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:08:43 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	get_str_len(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	while (str1[i])
		i++;
	j = 0;
	while (str2[j])
		j++;
	return (i + j);
}

static void	append_strs(char *str, char *str2, char *str3)
{
	while (*str2)
	{
		*str = *str2;
		str++;
		str2++;
	}
	while (*str3)
	{
		*str = *str3;
		str++;
		str3++;
	}
	*str = '\0';
}

static char	*get_path(t_all *info)
{
	char	*str;
	char	*str2;
	char	*str3;

	str2 = NULL;
	str3 = NULL;
	if (info->all_syncs.player.move.top)
		str2 = "./xpm/p_top";
	else if (info->all_syncs.player.move.right)
		str2 = "./xpm/p_right";
	else if (info->all_syncs.player.move.down)
		str2 = "./xpm/p_down";
	else if (info->all_syncs.player.move.left)
		str2 = "./xpm/p_left";
	if (info->all_syncs.player.sprite == 1)
		str3 = "1.xpm";
	else if (info->all_syncs.player.sprite == 2 || \
		info->all_syncs.player.sprite == 4)
		str3 = "2.xpm";
	else if (info->all_syncs.player.sprite == 3)
		str3 = "3.xpm";
	str = malloc(get_str_len(str2, str3) + 1);
	if (!str)
		print_free_exit(info, "Error\n Malloc failed.\n", 2);
	return (append_strs(str, str2, str3), str);
}

void	display_player(t_all *info)
{
	int		x;
	int		y;
	int		x_pad;
	int		y_pad;
	char	*path;

	x = info->all_syncs.player.x;
	y = info->all_syncs.player.y;
	x_pad = (1 + (info->map_info.pad_x / 2)) * 32;
	y_pad = (3 + (info->map_info.pad_y / 2)) * 32;
	path = get_path(info);
	display_sprite(info, path, x_pad + x * 32, y_pad + y * 32);
	if (path)
		free(path);
}
