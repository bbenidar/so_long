/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:33:00 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/26 14:35:37 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_collect(t_map *bb)
{
	bb->collectible = 0;
	bb->player = 0;
	bb->escape = 0;
	bb->j = ft_maplen(bb->str) - 1;
	while (bb->j > 0)
	{
		bb->i = 0;
		while (bb->str[bb->j][bb->i])
		{
			if (bb->str[bb->j][bb->i] == 'C')
				bb->collectible++;
			bb->i++;
		}
		bb->j--;
	}
	return (bb->collectible);
}

int	ft_move(int keycode, t_map *bb)
{
	if (keycode == 53)
		ft_close(bb);
	if (keycode == 13 || keycode == 126)
		ft_move_up(bb);
	if (keycode == 1 || keycode == 125)
		ft_move_down(bb);
	if (keycode == 2 || keycode == 124)
		ft_move_right(bb);
	if (keycode == 0 || keycode == 123)
		ft_move_left(bb);
	ft_put_draw(bb);
	return (0);
}
