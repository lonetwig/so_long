/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:01 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/29 09:43:15 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	change_command(int key, void *param)
{
	t_all	*info;

	info = (t_all *)param;
	if (key == 13 || key == 126 || key == 2 || key == 124 \
	|| key == 1 || key == 125 || key == 0 || key == 123)
		info->last_command = key;
	if (key == 53)
		print_free_exit(info, "Bye!\n", 1);
	return (0);
}
