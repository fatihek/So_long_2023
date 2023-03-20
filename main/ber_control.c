/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:23 by fkalaman          #+#    #+#             */
/*   Updated: 2023/03/20 10:10:34 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_name_control(char *map_name, t_vars *vars)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[--len] == 'r')
	{
		if (map_name[--len] == 'e')
		{
			if (map_name[--len] == 'b')
			{
				if (map_name[--len] == '.')
					;
				else
					error_messages(1, vars);
			}
			else
				error_messages(1, vars);
		}
		else
			error_messages(1, vars);
	}
	else
		error_messages(1, vars);
}

void	control_components(char **map, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'P' ||
				map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'V')
				;
			else
				error_messages(2, vars);
			j++;
		}
		i++;
	}
}

void	rectangular(t_vars *vars, int i, int j)
{
	int	area;
	int	count;

	area = (vars->len_height) * (vars->len_width);
	count = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != '\n')
		{
			if (vars->map[i][j] == '0' || vars->map[i][j] == '1' ||
				vars->map[i][j] == 'P' || vars->map[i][j] == 'C'
				|| vars->map[i][j] == 'E' || vars->map[i][j] == 'V')
				count++;
			else
				error_messages(2, vars);
			j++;
		}
		i++;
	}
	if (count != area)
	{
		free_wrong(vars);
		exit(ft_printf("\033[0;31mError\nWrong Map!(Rectangular)\n"));
	}
}

void	mapfree_control(t_vars *vars)
{
	int		fd;
	char	*tmp;

	fd = open(vars->map_name, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
	{
		free_mapfree(vars);
		exit(ft_printf("\033[0;31mError\nWrong Map!\n"));
	}
	free(tmp);
}

void	map_control_dsl(t_vars *vars)
{
	map_name_control(vars->map_name, vars);
	control_components(vars->map, vars);
	rectangular(vars, 0, 0);
	path_finder(vars->i, vars->j, vars);
	if (vars->path.spaces >= 0 || vars->cants.coin_count == 0)
	{
		ft_printf("\033[0;31mError\nImpossible to finish the game!\n");
		free_wrong(vars);
		exit(1);
	}
}
