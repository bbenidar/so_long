/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:09:50 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/25 18:09:51 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_check_rctgl(t_map *bb)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(bb->str[1]);
	while (bb->str[i])
	{
		if (len != ft_strlen(bb->str[i]))
		{
			ft_printf("\033[0;31mERROR (the map is not a rectangle)");
			ft_close(bb);
		}
		else
			i++;
	}
	return (len);
}

int	ft_maplen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_check_map2(t_map *bb)
{
	if (bb->str[bb->j][bb->i] == 'C')
	{
		bb->collectible++;
		bb->i++;
	}
	else if (bb->str[bb->j][bb->i] == 'E')
	{
		bb->escape++;
		bb->i++;
	}
	else if (bb->str[bb->j][bb->i] == 'P')
	{
		bb->player++;
		bb->i++;
	}
	else if (bb->str[bb->j][bb->i] == '1' || bb->str[bb->j][bb->i] == '0'
			|| bb->str[bb->j][bb->i] == 'M')
		bb->i++;
	else
	{
		ft_printf("ERROR IN MAP\n");
		ft_close(bb);
	}
}

void	ft_check_map(t_map *bb)
{
	bb->collectible = 0;
	bb->player = 0;
	bb->escape = 0;
	bb->j = ft_maplen(bb->str) - 1;
	while (bb->j > 0)
	{
		bb->i = 0;
		while (bb->str[bb->j][bb->i])
			ft_check_map2(bb);
		bb->j--;
	}
	if (bb->player != 1 || bb->escape < 1 || bb->collectible < 1)
	{
		ft_printf("ERROR IN MAP\n");
		ft_close(bb);
	}
}

void	ft_check_wall_sidebar(t_map *bb)
{
	int	j;
	int	k;

	k = ft_maplen(bb->str) - 1;
	j = ft_strlen(bb->str[k]) - 1;
	while (k >= 0)
	{
		if (!(bb->str[k][0] == '1' && bb->str[k][j] == '1'))
		{
			ft_printf("\033[0;31mERROR (the map sidebar wall need fix)");
			ft_close(bb);
		}
		k--;
	}
}
