/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:19 by fkalaman          #+#    #+#             */
/*   Updated: 2023/03/18 16:46:06 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_up(t_vars *vars)
{
	vars->map[vars->enemy_i][vars->enemy_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b, vars->enemy_x,
		vars->enemy_y);
	vars->enemy_x += IMG_SIZE;
	vars->enemy_j += 1;
	if (vars->map[vars->enemy_i][vars->enemy_j] != 'P')
	{
		vars->map[vars->enemy_i][vars->enemy_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.enemy_img,
			vars->enemy_x, vars->enemy_y);
	}
	else
		exit(0);
}

void	enemy_down(t_vars *vars)
{
	vars->map[vars->enemy_i][vars->enemy_j] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->m.b, vars->enemy_x,
		vars->enemy_y);
	vars->enemy_x -= IMG_SIZE;
	vars->enemy_j -= 1;
	if (vars->map[vars->enemy_i][vars->enemy_j] != 'P')
	{
		vars->map[vars->enemy_i][vars->enemy_j] = 'V';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->m.enemy_img,
			vars->enemy_x, vars->enemy_y);
	}
	else
		exit(0);
}

void	enemy_patrol(t_vars *vars)
{
	if (vars->map[vars->enemy_i][vars->enemy_j + 1] != '1')
	{
		while (vars->map[vars->enemy_i][vars->enemy_j + 1] != '1'
			&& vars->map[vars->enemy_i][vars->enemy_j + 1] != 'C')
		{
			enemy_up(vars);
		}
	}
	else if (vars->map[vars->enemy_i][vars->enemy_j - 1] != '1')
	{
		while (vars->map[vars->enemy_i][vars->enemy_j - 1] != '1'
			&& vars->map[vars->enemy_i][vars->enemy_j - 1] != 'C')
		{
			enemy_down(vars);
		}
	}
}

int	anim(t_vars *vars)
{
	static int	i;

	vars->enemyspeed++;
	if (vars->enemyspeed >= 6000)
	{
		enemy_patrol(vars);
		vars->enemyspeed = 0;
	}
	i++;
	if (i >= 60)
	{
		sprite_a(vars);
		i = 0;
	}
	return (1);
}
