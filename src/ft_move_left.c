/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:48:44 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/21 18:43:14 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_left2(t_map *bb, int i, int j)
{
	if (bb->str[i][j - 1] == '0')
	{
		bb->str[i][j - 1] = 'P';
		bb->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
	}
	else if (bb->str[i][j - 1] == 'C')
	{
		bb->str[i][j - 1] = 'P';
		bb->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
	}
	else if (bb->str[i][j - 1] == 'E')
	{
		if (ft_check_collect(bb) == 0)
		{
			bb->str[i][j - 1] = 'P';
			bb->str[i][j] = '0';
			ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
			ft_win(bb);
		}
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
				ft_move_left2(bb, i, j);
			}
			j++;
		}
	}
}
