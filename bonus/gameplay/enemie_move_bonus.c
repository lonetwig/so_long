/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemie_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:29:15 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:17:00 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	change_if_wall(t_coordinate *enemie, t_nearby *nearby)
{
	if (enemie->move.top && nearby->top.is_wall)
	{
		enemie->move.top = 0;
		enemie->move.right = 1;
		change_if_wall(enemie, nearby);
	}
	if (enemie->move.right && nearby->right.is_wall)
	{
		enemie->move.right = 0;
		enemie->move.down = 1;
		change_if_wall(enemie, nearby);
	}
	if (enemie->move.down && nearby->down.is_wall)
	{
		enemie->move.down = 0;
		enemie->move.left = 1;
		change_if_wall(enemie, nearby);
	}
	if (enemie->move.left && nearby->left.is_wall)
	{
		enemie->move.left = 0;
		enemie->move.top = 1;
		change_if_wall(enemie, nearby);
	}
}

static unsigned int	get_random_n(t_all *info)
{
	char			*str;
	unsigned int	n;

	str = malloc(1);
	if (!str)
		print_free_exit(info, "Error\n Malloc failed.\n", 2);
	n = (int)str;
	free(str);
	return (n);
}

static void	random_move(t_all *info, t_coordinate *e, t_nearby *near, int i)
{
	unsigned int	n;

	n = get_random_n(info) * i % 15;
	if (n <= 3 && !near->top.is_wall && !e->move.down)
	{
		e->move = (t_direction){0};
		e->move.top = 1;
	}
	else if (n <= 7 && !near->right.is_wall && !e->move.left)
	{
		e->move = (t_direction){0};
		e->move.right = 1;
	}
	else if (n <= 11 && !near->down.is_wall && !e->move.top)
	{
		e->move = (t_direction){0};
		e->move.down = 1;
	}
	else if (n <= 15 && !near->left.is_wall && !e->move.right)
	{
		e->move = (t_direction){0};
		e->move.left = 1;
	}
}

int	enemie_next_move(t_all *info, t_coordinate *enemie, int *i)
{
	t_nearby	nearby;

	get_nearby(info, enemie->x, enemie->y, &nearby);
	if (nearby.top.is_wall && nearby.right.is_wall && nearby.down.is_wall \
	&& nearby.left.is_wall)
		return (1);
	random_move(info, enemie, &nearby, *i);
	change_if_wall(enemie, &nearby);
	if (enemie->move.top && enemie->y != 0)
		(enemie->y)--;
	else if (enemie->move.right && enemie->x != info->map_info.width)
		(enemie->x)++;
	else if (enemie->move.down && enemie->y != info->map_info.height)
		(enemie->y)++;
	else if (enemie->move.left && enemie->x != 0)
		(enemie->x)--;
	return (0);
}
