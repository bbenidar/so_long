/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:15:56 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/20 15:36:32 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_draw_img(l_map *bb)
{
	if (bb->str[bb->i][bb->j] == 'E')
	{
		mlx_put_image_to_window(bb->mlx_ptr,
			bb->win_ptr, bb->backgr, bb->x, bb->y);
		mlx_put_image_to_window(bb->mlx_ptr,
			bb->win_ptr, bb->door, bb->x, bb->y);
	}
	else if (bb->str[bb->i][bb->j] == 'C')
	{
		mlx_put_image_to_window(bb->mlx_ptr,
			bb->win_ptr, bb->backgr, bb->x, bb->y);
		mlx_put_image_to_window(bb->mlx_ptr,
			bb->win_ptr, bb->collect, bb->x, bb->y);
	}
	else if (bb->str[bb->i][bb->j] == '0')
		mlx_put_image_to_window(bb->mlx_ptr,
			bb->win_ptr, bb->backgr, bb->x, bb->y);
}

void	ft_draw_image(l_map *bb)
{
	if (bb->str[bb->i][bb->j] == 'P')
	{
		mlx_put_image_to_window(bb->mlx_ptr,
			bb->win_ptr, bb->backgr, bb->x, bb->y);
		mlx_put_image_to_window(bb->mlx_ptr,
			bb->win_ptr, bb->pl, bb->x, bb->y);
	}
	else if (bb->str[bb->i][bb->j] == '1')
	{
		mlx_put_image_to_window(bb->mlx_ptr,
			bb->win_ptr, bb->backgr, bb->x, bb->y);
		mlx_put_image_to_window(bb->mlx_ptr,
			bb->win_ptr, bb->wl, bb->x, bb->y);
	}
	else
		ft_draw_img(bb);
}

void	ft_put_draw(l_map *bb)
{
	bb->i = 0;
	bb->j = 0;
	bb->y = 0;
	mlx_clear_window(bb->mlx_ptr, bb->win_ptr);
	while (bb->str[bb->i])
	{
		bb->x = 0;
		while (bb->str[bb->i][bb->j])
		{
			ft_draw_image(bb);
			bb->j++;
			bb->x += 64;
		}
		bb->i++;
		bb->j = 0;
		bb->y += 64;
	}
}

void	ft_draw(l_map *bb)
{
	bb->win_ptr = mlx_new_window(bb->mlx_ptr,
			ft_check_rctgl(bb) * 64, ft_maplen(bb->str) * 64, "SO_LONG");
	bb->pl = mlx_xpm_file_to_image(bb->mlx_ptr,
			"./xpm/player.xpm", &(bb->width), &(bb->height));
	ft_check(bb);
	bb->wl = mlx_xpm_file_to_image(bb->mlx_ptr,
			"./xpm/walls.xpm", &(bb->width), &(bb->height));
	ft_check(bb);
	bb->backgr = mlx_xpm_file_to_image(bb->mlx_ptr,
			"./xpm/background.xpm", &(bb->width), &(bb->height));
	ft_check(bb);
	bb->door = mlx_xpm_file_to_image(bb->mlx_ptr,
			"./xpm/exit_final.xpm", &(bb->width), &(bb->height));
	ft_check(bb);
	bb->collect = mlx_xpm_file_to_image(bb->mlx_ptr,
			"./xpm/coin.xpm", &(bb->width), &(bb->height));
	ft_check(bb);
}

void	ft_draw_map(l_map *bb)
{
	bb->mlx_ptr = mlx_init();
	if (!(bb->mlx_ptr))
	{
		ft_printf("\033[0;31m|==| ERROR mlx error |==|");
		exit(1);
	}
	ft_draw(bb);
	ft_put_draw(bb);
}
