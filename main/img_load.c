/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:16 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/02 12:21:09 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_load(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->width * IMG_SIZE;
	y = vars->len_height * IMG_SIZE;
	vars->m.b = mlx_xpm_file_to_image(vars->mlx, "./images/bg.xpm",
			&x, &y);
	vars->m.w = mlx_xpm_file_to_image(vars->mlx,
			"./images/wall.xpm", &x, &y);
	vars->m.player_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/player.xpm", &x, &y);
	vars->m.player_back_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/player_back.xpm", &x, &y);
	vars->m.player_left_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/player_left.xpm", &x, &y);
	vars->m.player_right_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/player_right.xpm", &x, &y);
	vars->m.c = mlx_xpm_file_to_image(vars->mlx,
			"./images/coin.xpm", &x, &y);
	vars->m.e = mlx_xpm_file_to_image(vars->mlx,
			"./images/exit.xpm", &x, &y);
	vars->m.exiter_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/exiter.xpm", &x, &y);
	vars->m.enemy_img = mlx_xpm_file_to_image(vars->mlx,
			"./images/enemy.xpm", &x, &y);
}

void	upload(t_vars *vars)
{
	vars->width = horizontal_len(vars);
	vars->len_height = vertical_len(vars->map_name);
}
