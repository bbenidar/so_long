/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:58:01 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/20 16:04:18 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copystr(l_map *bb)
{
	int	i;
	int	j;

	i = 0;
	while (bb->str[i])
		i++;
	bb->strBacktr = calloc(sizeof(char *), i + 1);
	if (!bb->strBacktr)
	{
		free(bb->strBacktr);
		exit(1);
	}
	j = 0;
	while (bb->str[j])
	{
		bb->strBacktr[j] = ft_strdup(bb->str[j]);
		j++;
	}
	bb->strBacktr[j] = 0;
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

void	free_map(l_map *bb)
{
	int	i;

	i = 0;
	while (bb->strBacktr[i])
	{
		free(bb->strBacktr[i]);
		i++;
	}
	free(bb->strBacktr);
}

void	ft_back_tracking(l_map *bb)
{
	copystr(bb);
	bb->i = 0;
	bb->j = 0;
	while (bb->strBacktr[bb->i])
	{
		bb->j = 0;
		while (bb->strBacktr[bb->i][bb->j])
		{
			if (bb->strBacktr[bb->i][bb->j] == 'E'
				|| bb->strBacktr[bb->i][bb->j] == 'C')
			{
				if (!ft_check_bcktr(bb->strBacktr[bb->i][bb->j],
					bb->strBacktr, bb->i, bb->j))
				{
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
