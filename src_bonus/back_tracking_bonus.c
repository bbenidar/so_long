/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:12:04 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/23 15:13:43 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	copystr(t_map *bb)
{
	int	i;
	int	j;

	i = 0;
	while (bb->str[i])
		i++;
	bb->strback = calloc(sizeof(char *), i + 1);
	if (!bb->strback)
	{
		ft_free_bktr(bb);
		ft_free(bb);
		exit(1);
	}
	j = 0;
	while (bb->str[j])
	{
		bb->strback[j] = ft_strdup(bb->str[j]);
		j++;
	}
	bb->strback[j] = 0;
}

int	ft_check_bcktr(char c, char **strB, int i, int j)
{
	if (strB[i][j] == 'P')
		return (1);
	if (strB[i][j] == '1' || (c != 'E' && strB[i][j] == 'E'))
		return (0);
	strB[i][j] = '1';
	if (ft_check_bcktr(c, strB, i, j + 1))
		return (1);
	if (ft_check_bcktr(c, strB, i + 1, j))
		return (1);
	if (ft_check_bcktr(c, strB, i, j - 1))
		return (1);
	if (ft_check_bcktr(c, strB, i - 1, j))
		return (1);
	return (0);
}

void	free_map(t_map *bb)
{
	int	i;

	i = 0;
	while (bb->strback[i])
	{
		free(bb->strback[i]);
		i++;
	}
	free(bb->strback);
}

void	ft_back_tracking(t_map *bb)
{
	copystr(bb);
	bb->i = 0;
	bb->j = 0;
	while (bb->strback[bb->i])
	{
		bb->j = 0;
		while (bb->strback[bb->i][bb->j])
		{
			if (bb->strback[bb->i][bb->j] == 'E'
				|| bb->strback[bb->i][bb->j] == 'C')
			{
				if (!ft_check_bcktr(bb->strback[bb->i][bb->j],
					bb->strback, bb->i, bb->j))
				{
					free_map(bb);
					ft_printf("\033[0;31mERROR collectible or exit is stuck\n");
					exit(1);
				}
				free_map(bb);
				copystr(bb);
			}
			bb->j++;
		}
		bb->i++;
	}
}
