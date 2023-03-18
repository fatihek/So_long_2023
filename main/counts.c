/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:21 by fkalaman          #+#    #+#             */
/*   Updated: 2023/03/18 16:45:49 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counts(t_vars *vars)
{
	vars->cants.coin_count = 0;
	vars->cants.player_count = 0;
	vars->cants.exit_count = 0;
	vars->cants.enemy_count = 0;
	vars->collected_coin = 0;
	vars->path.spaces = 0;
	vars->collected_coin = 0;
	vars->move_count = 0;
	vars->s.aspeed = 0;
	vars->path.imap = vars->map;
	c_coin(vars, 0, 0);
	c_player(vars, 0, 0);
	c_exit(vars, 0, 0);
	return (0);
}

void	c_coin(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'C')
				vars->cants.coin_count++;
			if (vars->map[i][j] == '0')
				vars->path.spaces++;
			j++;
		}
		i++;
	}
}

void	c_player(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'P')
				vars->cants.player_count++;
			j++;
		}
		i++;
	}
	if (vars->cants.player_count != 1)
	{
		ft_printf("There should only be one player!");
		exit(0);
	}
}

void	c_exit(t_vars *vars, int i, int j)
{
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == 'E')
				vars->cants.exit_count++;
			j++;
		}
		i++;
	}
	if (vars->cants.exit_count != 1)
	{
		ft_printf("There should only be one exit door!");
		exit(0);
	}
}
