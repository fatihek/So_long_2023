/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:55 by fkalaman          #+#    #+#             */
/*   Updated: 2023/03/18 17:41:36 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 12)
	{
		move_up(vars);
		exit_door(vars);
	}
	if (keycode == 2)
	{
		move_right(vars);
		exit_door(vars);
	}
	if (keycode == 6)
	{
		move_down(vars);
		exit_door(vars);
	}
	if (keycode == 1)
	{
		move_left(vars);
		exit_door(vars);
	}
	vars->mover = ft_itoa(vars->move_count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->m.w, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 50, 50, 0xFFFFFF, vars->mover);
}
