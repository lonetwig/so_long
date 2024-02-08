/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:11:41 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:08:20 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static char	*get_path(int n, t_all *info)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(12);
	if (!str)
		print_free_exit(info, "Error\n Malloc failed.\n", 2);
	str[0] = '.';
	str[1] = '/';
	str[2] = 'x';
	str[3] = 'p';
	str[4] = 'm';
	str[5] = '/';
	str[6] = n + '0';
	str[7] = '.';
	str[8] = 'x';
	str[9] = 'p';
	str[10] = 'm';
	str[11] = '\0';
	return (str);
}

static int	display_status2(t_all *info, int *stat, int x_size)
{
	char	*str;

	str = get_path((*stat) % 10, info);
	display_sprite(info, str, x_size, 64);
	if (str)
		free(str);
	*stat = (*stat) / 10;
	if (*stat == 0)
		return (0);
	return (1);
}

static int	stat_size(int stat)
{
	int	i;

	i = 0;
	if (stat == 0)
		return (1);
	while (stat > 0)
	{
		i++;
		stat = stat / 10;
	}
	return (i);
}

static void	display_status(t_all *info)
{
	t_map_info	*m_info;
	int			coins;
	int			steps;
	int			x_size;
	int			x;

	coins = info->status.coins;
	steps = info->status.steps;
	m_info = &info->map_info;
	x = stat_size(coins) - 1;
	while (coins >= 0)
	{
		x_size = (m_info->width + m_info->pad_x + stat_size(coins) - x) * 32;
		if (!display_status2(info, &coins, x_size))
			break ;
	}
	x = stat_size(steps);
	while (steps >= 0)
	{
		x_size = ((stat_size(steps) - x) * 32) + 230;
		if (!display_status2(info, &steps, x_size))
			break ;
	}
}

void	display_hud(t_all *info)
{
	t_map_info	*m_info;
	int			x_size;

	m_info = &info->map_info;
	display_sprite(info, "./xpm/steps.xpm", 32, 64);
	x_size = ((m_info->width + m_info->pad_x) * 32) - 165;
	display_sprite(info, "./xpm/coins.xpm", x_size, 64);
	x_size = (((m_info->width + m_info->pad_x) * 32) / 2) - 30;
	display_sprite(info, "./xpm/name.xpm", x_size, 24);
	display_status(info);
}
