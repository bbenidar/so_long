/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_and_free_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:06:48 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/25 18:10:04 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_free_bktr(t_map *bb)
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

void	ft_free(t_map *bb)
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

int	ft_close(t_map *bb)
{
	ft_free(bb);
	exit(1);
	return (0);
}

int	ft_win(t_map *bb)
{
	ft_free(bb);
	ft_printf("\033[0;32m            _       \n");
	ft_printf("__      _  (_)  _ __  \n");
	ft_printf("\\ \\ /\\ / / | | | '_  \\\n");
	ft_printf(" \\ V  V /  | | | | | |\n");
	ft_printf("  \\_/\\_/   |_| |_| |_|\n");
	ft_printf("                  \n");
	exit(0);
	return (0);
}

void	ft_check(t_map *bb, void *ptr)
{
	if (!ptr)
	{
		ft_printf("\033[0;31m|==| ERROR mlx errorrrr |==|");
		free(ptr);
		ft_free(bb);
		exit(1);
	}
	if (bb->width == 0 || bb->height == 0)
	{
		ft_printf("\033[0;31m|==| ERROR mlx errorrrr |==|");
		exit(1);
	}
}
