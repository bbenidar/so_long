/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:53:14 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/20 15:44:42 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_bktr(l_map *bb)
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

void	ft_free(l_map *bb)
{
	int	i;

	i = 0;
	while (bb->str[i])
	{
		free(bb->str[i]);
		i++;
	}
	free(bb->str);
}

int	ft_close(l_map *bb)
{
	ft_free(bb);
	exit(1);
	return (0);
}

int	ft_win(l_map *bb)
{
	ft_free(bb);
	ft_printf("\033[0;32m            _       \n");
	ft_printf("__      _  (_)  _ __  \n");
	ft_printf("\\ \\ /\\ / / | | | '_  \\\n");
	ft_printf(" \\ V  V /  | | | | | |\n");
	ft_printf("  \\_/\\_/   |_| |_| |_|\n");
	ft_printf("                  \n");
	exit(1);
	return (0);
}

void	ft_check(l_map *bb)
{
	if (bb->width == 0 || bb->height == 0)
	{
		ft_printf("\033[0;31m|==| ERROR mlx errorrrr |==|");
		exit(1);
	}
}
