/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:54:06 by ealislam          #+#    #+#             */
/*   Updated: 2024/02/07 08:56:33 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_hook(void *param)
{
	t_all	*info;

	info = (t_all *)param;
	mlx_destroy_window(info->mlx, info->win);
	print_free_exit(info, "Bye!\n", 1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_all	info;

	if (argc != 2)
		print_free_exit(&info, "Error\n argument not valid.\n", 2);
	initialize_info(&info, argv[1]);
	display_all(&info);
	mlx_key_hook(info.win, change_command, &info);
	mlx_loop_hook(info.mlx, loop, &info);
	mlx_hook(info.win, 17, 0, close_hook, &info);
	mlx_loop(info.mlx);
}
