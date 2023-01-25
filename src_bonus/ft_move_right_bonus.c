/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:00:13 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/25 18:04:37 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_lose(t_map *bb)
{
	ft_free(bb);
	ft_printf("\033[0;35m===|| GAME OVER ||===\n");
	exit(0);
	return (0);
}

void	ft_move3(t_map *bb, int i, int j)
{
	if (bb->str[i][j + 1] == 'E')
	{
		if (ft_check_collect(bb) == 0)
		{
			bb->str[i][j + 1] = 'P';
			bb->str[i][j] = '0';
			++bb->move;
			ft_win(bb);
		}
	}
	else if (bb->str[i][j + 1] == 'M')
	{
		bb->str[i][j] = '0';
		++bb->move;
		ft_lose(bb);
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
				++bb->move;
				break ;
			}
			else if (bb->str[i][j + 1] == 'C')
			{
				bb->str[i][j + 1] = 'P';
				bb->str[i][j] = '0';
				++bb->move;
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
