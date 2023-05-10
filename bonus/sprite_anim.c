/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:32:34 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/04 11:56:00 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_sprites(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->width * IMG_SIZE;
	y = vars->len_height * IMG_SIZE;
	vars->s.cs[0] = mlx_xpm_file_to_image(vars->mlx, "./images/c0.xpm", &x, &y);
	vars->s.cs[1] = mlx_xpm_file_to_image(vars->mlx, "./images/c1.xpm", &x, &y);
	vars->s.cs[2] = mlx_xpm_file_to_image(vars->mlx, "./images/c2.xpm", &x, &y);
	vars->s.cs[3] = mlx_xpm_file_to_image(vars->mlx, "./images/c3.xpm", &x, &y);
	vars->s.cs[4] = mlx_xpm_file_to_image(vars->mlx, "./images/c4.xpm", &x, &y);
	vars->s.cs[5] = mlx_xpm_file_to_image(vars->mlx, "./images/c5.xpm", &x, &y);
	vars->s.cs[6] = mlx_xpm_file_to_image(vars->mlx, "./images/c6.xpm", &x, &y);
}

void	sprite_a(t_vars *vars)
{
	static int	i;
	static int	j;

	if (i <= 6000)
	{
		i++;
		put_coin(vars, 0, 0, j);
		if (i % 4 == 0)
		{
			j++;
			if (j >= 7)
				j = 0;
		}
	}
	else
		i = 0;
}

int	move_counter(t_vars *vars)
{
	vars->mover = ft_itoa(vars->move_count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->m.w, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 50, 50, 0xFFFFFF, vars->mover);
	return (0);
}
