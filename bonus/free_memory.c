/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:25:36 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/03 18:01:02 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imap(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->len_height)
	{
		free(vars->path.imap[i]);
		i++;
	}
	free(vars->path.imap);
}

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->len_height)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

void	free_exit(t_vars *vars)
{
	free_imap(vars);
	free_map(vars);
	mlx_destroy_image(vars->mlx, vars->m.b);
	mlx_destroy_image(vars->mlx, vars->m.c);
	mlx_destroy_image(vars->mlx, vars->m.e);
	mlx_destroy_image(vars->mlx, vars->m.exiter_img);
	mlx_destroy_image(vars->mlx, vars->m.player_left_img);
	mlx_destroy_image(vars->mlx, vars->m.player_right_img);
	mlx_destroy_image(vars->mlx, vars->m.player_img);
	mlx_destroy_image(vars->mlx, vars->m.player_back_img);
	mlx_destroy_image(vars->mlx, vars->m.enemy_img);
	mlx_destroy_image(vars->mlx, vars->m.w);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->s.cs);
}

void	free_wrong(t_vars *vars)
{
	free_map(vars);
	free_imap(vars);
}

void	free_mapfree(t_vars *vars)
{
	free(vars->path.imap);
}
