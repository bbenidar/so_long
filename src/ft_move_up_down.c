/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:10:00 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/21 18:43:46 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_down2(t_map *bb, int i, int j)
{
	if (bb->str[i + 1][j] == '0')
	{
		bb->str[i + 1][j] = 'P';
		bb->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
	}
	else if (bb->str[i + 1][j] == 'C')
	{
		bb->str[i + 1][j] = 'P';
		bb->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
	}
	else if (bb->str[i + 1][j] == 'E')
	{
		if (ft_check_collect(bb) == 0)
		{
			bb->str[i + 1][j] = 'P';
			bb->str[i][j] = '0';
			ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
			ft_win(bb);
		}
	}
}

void	ft_move_down(t_map *bb)
{
	int	i;
	int	j;

	i = ft_maplen(bb->str) - 1;
	while (i >= 0)
	{
		j = 0;
		while (bb->str[i][j])
		{
			if (bb->str[i][j] == 'P')
			{
				ft_move_down2(bb, i, j);
			}
			j++;
		}
		i--;
	}
}

void	ft_move_up2(t_map *bb, int i, int j)
{
	if (bb->str[i - 1][j] == 'C')
	{
		bb->str[i - 1][j] = 'P';
		bb->str[i][j] = '0';
		ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
	}
	else if (bb->str[i - 1][j] == 'E')
	{
		if (ft_check_collect(bb) == 0)
		{
			bb->str[i - 1][j] = 'P';
			bb->str[i][j] = '0';
			ft_win(bb);
		}
	}
}

void	ft_move_up(t_map *bb)
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
				if (bb->str[i - 1][j] == '0')
				{
					bb->str[i - 1][j] = 'P';
					bb->str[i][j] = '0';
					ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
					break ;
				}
				else
					ft_move_up2(bb, i, j);
			}
			j++;
		}
	}
}
