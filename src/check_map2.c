/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:33:21 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/22 19:56:45 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_wall(t_map *bb)
{
	int	i;

	i = 0;
	bb->j = ft_maplen(bb->str) - 1;
	while (bb->str[0][i] && bb->str[bb->j][i])
	{
		if (bb->str[0][i] == '1' && bb->str[bb->j][i] == '1')
			i++;
		else
		{
			ft_printf("\033[0;31mERROR (the map wall need fix)");
			ft_close(bb);
		}
	}
	return (0);
}
