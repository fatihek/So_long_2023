/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:55 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/04 11:39:14 by fkalaman         ###   ########.fr       */
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
	return (1);
}
