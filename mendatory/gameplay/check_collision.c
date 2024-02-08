/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:47:04 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/29 09:43:30 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_wall( int key, t_nearby *nearby)
{
	if ((key == 13 || key == 126) && nearby->top.is_wall)
		return (1);
	if ((key == 2 || key == 124) && nearby->right.is_wall)
		return (1);
	if ((key == 1 || key == 125) && nearby->down.is_wall)
		return (1);
	if ((key == 0 || key == 123) && nearby->left.is_wall)
		return (1);
	return (0);
}

int	check_coin(int key, t_nearby *nearby)
{
	if ((key == 13 || key == 126) && nearby->top.is_coin)
		return (1);
	if ((key == 2 || key == 124) && nearby->right.is_coin)
		return (1);
	if ((key == 1 || key == 125) && nearby->down.is_coin)
		return (1);
	if ((key == 0 || key == 123) && nearby->left.is_coin)
		return (1);
	return (0);
}

int	check_exit(int key, t_nearby *nearby)
{
	if ((key == 13 || key == 126) && nearby->top.is_exit)
		return (1);
	if ((key == 2 || key == 124) && nearby->right.is_exit)
		return (1);
	if ((key == 1 || key == 125) && nearby->down.is_exit)
		return (1);
	if ((key == 0 || key == 123) && nearby->left.is_exit)
		return (1);
	return (0);
}
