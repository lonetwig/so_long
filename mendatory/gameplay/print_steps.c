/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:23:52 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/29 09:47:12 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	print_steps2(int n)
{
	char	c;

	if (n == 0)
		return ;
	c = '0' + (n % 10);
	print_steps2(n / 10);
	write(1, &c, 1);
}

void	print_steps(t_all *info)
{
	int	n;

	n = info->status.steps;
	write(1, "Steps : ", 7);
	print_steps2(n);
	write(1, "\n", 1);
}
