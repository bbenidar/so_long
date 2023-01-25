/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:05:52 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/25 18:06:15 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_move_left2(t_map *bb, int i, int j)
{
	if (bb->str[i][j - 1] == 'C')
	{
		bb->str[i][j - 1] = 'P';
		bb->str[i][j] = '0';
		++bb->move;
	}
	else if (bb->str[i][j - 1] == 'E')
	{
		if (ft_check_collect(bb) == 0)
		{
			bb->str[i][j - 1] = 'P';
			bb->str[i][j] = '0';
			++bb->move;
			ft_win(bb);
		}
	}
	else if (bb->str[i][j - 1] == 'M')
	{
		bb->str[i][j] = '0';
		++bb->move;
		ft_lose(bb);
	}
}

void	ft_move_left(t_map *bb)
{
	int	i;
	int	j;

	i = -1;
	while (bb->str[++i])
	{
		j = 0;
		while (bb->str[i][j])
		{
			if (bb->str[i][j] == 'P')
			{
				if (bb->str[i][j - 1] == '0')
				{
					bb->str[i][j - 1] = 'P';
					bb->str[i][j] = '0';
					++bb->move;
				}
				else
					ft_move_left2(bb, i, j);
			}
			j++;
		}
	}
}
