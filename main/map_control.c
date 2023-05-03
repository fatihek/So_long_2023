/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:10 by fkalaman          #+#    #+#             */
/*   Updated: 2023/05/02 12:21:50 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_control(t_vars *vars)
{
	int		i;
	int		fd;
	char	*ptr;

	i = 0;
	fd = open(vars->map_name, O_RDONLY);
	while (i < vars->len_height - 1)
	{
		ptr = get_next_line(fd);
		if (vars->map[0][i] != '1' || vars->map[vars->len_height
			- 1][i] != '1')
		{
			ft_printf("Up or down edges not surrounded by walls");
			free(ptr);
			exit(1);
		}
		else if (vars->map[i][0] != '1' || vars->map[i][vars->width - 1] != '1')
		{
			ft_printf("Right or left edges are not surrounded by walls");
			free(ptr);
			exit(1);
		}
		i++;
		free(ptr);
	}
}
