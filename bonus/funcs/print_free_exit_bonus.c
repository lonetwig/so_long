/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_free_exit_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:46:03 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/28 18:13:31 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_free_exit(t_all *info, char *str, int fd)
{
	write(fd, str, get_length(str));
	free_all(info, info->all_sprites);
	if (fd == 1)
		exit(0);
	exit(1);
}
