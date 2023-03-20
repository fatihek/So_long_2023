/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:14:45 by fkalaman          #+#    #+#             */
/*   Updated: 2023/03/20 10:12:00 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.map_name = argv[1];
	map_read(&vars);
	counts(&vars);
	upload(&vars);
	map_control(&vars);
	player_locate(&vars);
	map_read_bonus(&vars);
	upload_sprites(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.len_width * IMG_SIZE,
			vars.len_height * IMG_SIZE, "So_Long");
	mlx_hook (vars.win, 17, 0, press_close_key, &vars);
	img_load(&vars);
	put_image(&vars, 0, 0);
	mlx_loop_hook(vars.mlx, anim, &vars);
	mlx_hook(vars.win, 2, 0, player_move, &vars);
	map_control_dsl(&vars);
	mlx_loop(vars.mlx);
}

int	press_close_key(t_vars *vars)
{
	ft_printf("\n\033[0;35mGame over! Buck needed money!\033[0m\n");
	exit(1);
}

void	error_messages(int i, t_vars *vars)
{
	if (i == 1)
	{
		free_wrong(vars);
		exit(ft_printf("\033[0;31mError\nWrong Map!\n"));
	}
	else if (i == 2)
	{
		exit(ft_printf("\033[0;31mError\nWrong Map!(Components)\n"));
	}
	else if (i == 3)
	{
		free_wrong(vars);
		exit(ft_printf("\033[0;31mError\nWrong Map!(Open Map)\n"));
	}
	else if (i == 4)
	{
		free_wrong(vars);
		ft_printf("\033[0;31mError\nWrong Map!(Collectible Count)\n");
		exit(1);
	}
}
