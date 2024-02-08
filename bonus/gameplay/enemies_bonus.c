/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:28:51 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:17:16 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	enemie_sprite(t_coordinate *enemie)
{
	if (enemie->move.top)
		enemie->sprite = 1;
	else if (enemie->move.right)
		enemie->sprite = 2;
	else if (enemie->move.down)
		enemie->sprite = 3;
	else if (enemie->move.left)
		enemie->sprite = 4;
}

void	enemies(t_all *info)
{
	t_coordinate	*enemie;
	static int		ran_i = 1;

	enemie = info->all_syncs.enemies;
	while (enemie)
	{
		if (enemie_next_move(info, enemie, &ran_i))
			return ;
		enemie_sprite(enemie);
		enemie = enemie->next;
		ran_i++;
	}
}
