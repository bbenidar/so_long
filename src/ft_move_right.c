/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:56:57 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/21 18:43:28 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move3(t_map *bb, int i, int j)
{
	if (bb->str[i][j + 1] == 'E')
	{
		if (ft_check_collect(bb) == 0)
		{
			bb->str[i][j + 1] = 'P';
			bb->str[i][j] = '0';
			ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
			ft_win(bb);
		}
	}
}

void	ft_move_right2(t_map *bb, int i, int j)
{
	while (bb->str[i][j])
	{
		if (bb->str[i][j] == 'P')
		{
			if (bb->str[i][j + 1] == '0')
			{
				bb->str[i][j + 1] = 'P';
				bb->str[i][j] = '0';
				ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
				break ;
			}
			else if (bb->str[i][j + 1] == 'C')
			{
				bb->str[i][j + 1] = 'P';
				bb->str[i][j] = '0';
				ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
				break ;
			}
			else
				ft_move3(bb, i, j);
		}
		j++;
	}
}

void	ft_move_right(t_map *bb)
{
	int	i;
	int	j;

	i = -1;
	while (bb->str[++i])
	{
		j = 0;
		ft_move_right2(bb, i, j);
	}
}
