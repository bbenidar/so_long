/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:09:21 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/26 21:06:05 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_check_wall(t_map *bb)
{
	int	i;

	i = 0;
	if (ft_strlen(bb->str[1]) * 64 > 2800)
	{
		ft_printf("ERROR MAP SO LONG\n");
		ft_close(bb);
	}
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
