/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemies_pos_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:39:06 by ealislam          #+#    #+#             */
/*   Updated: 2024/02/07 08:41:07 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	get_n(void)
{
	static int	n = 0;

	n++;
	return ((n % 4) + 1);
}

static void	get_enemie_first_move(t_coordinate *enemie, int n)
{
	if (n == 1)
		enemie->move.top = 1;
	else if (n == 2)
		enemie->move.right = 1;
	else if (n == 3)
		enemie->move.right = 1;
	else if (n == 4)
		enemie->move.right = 1;
}

static t_coordinate	*add_enemie(t_all *info, t_pos *map)
{
	t_coordinate	*enemie;

	enemie = malloc(sizeof(t_coordinate));
	if (!enemie)
		print_free_exit(info, "Error\n Malloc failed.\n", 2);
	enemie->mode = NORMAL;
	enemie->move = (t_direction){0};
	enemie->next = NULL;
	enemie->x = map->x;
	enemie->y = map->y;
	enemie->sprite = get_n();
	enemie->type = get_n();
	get_enemie_first_move(enemie, get_n());
	return (enemie);
}

void	get_enemies_pos(t_all *info)
{
	t_coordinate	*enemies;
	t_coordinate	*head;
	t_pos			*map;

	head = NULL;
	map = info->map_list;
	while (map)
	{
		if (map->type == 'F')
		{
			if (head == NULL)
			{
				enemies = add_enemie(info, map);
				head = enemies;
			}
			else
			{
				enemies->next = add_enemie(info, map);
				enemies = enemies->next;
			}
		}
		map = map->next;
	}
	info->all_syncs.enemies = head;
}
