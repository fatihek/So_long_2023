/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkalaman <student.42kocaeli.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:15:10 by fkalaman          #+#    #+#             */
/*   Updated: 2023/03/18 17:41:02 by fkalaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_control(t_vars *vars)
{
	int		count;
	int		fd;
	char	*ptr;

	count = 0;
	fd = open(vars->map_name, O_RDONLY);
	while (count < vars->len_height - 1)
	{
		ptr = get_next_line(fd);
		if (vars->len_width != ft_strlen(vars->map[vars->len_height - 1]))
		{
			ft_printf("Map is not rectangular!");
			free(ptr);
			exit(1);
		}
		else if (vars->len_width != ft_strlen(vars->map[count]) - 1)
		{
			ft_printf("Map is not rectangular!");
			free(ptr);
			exit(1);
		}
		count++;
		free(ptr);
	}
}
