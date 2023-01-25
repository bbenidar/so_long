/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:37:29 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/25 18:48:59 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_enemy2(t_map *bb, int i, int j)
{
	if ((rand() % 4 == 2) && (bb->str[i - 1][j] == '0' || bb->str[i
			- 1][j] == 'P'))
	{
		if (bb->str[i - 1][j] == 'P')
			ft_lose(bb);
		bb->str[i - 1][j] = 'M';
		bb->str[i][j] = '0';
		ft_put_draw(bb);
	}
	else if ((rand() % 4 == 2) && (bb->str[i + 1][j] == '0'
		|| bb->str[i + 1][j] == 'P'))
	{
		if (bb->str[i + 1][j] == 'P')
			ft_lose(bb);
		bb->str[i + 1][j] = 'M';
		bb->str[i][j] = '0';
		ft_put_draw(bb);
	}
}

void	move_enemy1(t_map *bb, int i, int j)
{
	if ((rand() % 4 == 0) && (bb->str[i][j + 1] == '0'
		|| bb->str[i][j + 1] == 'P'))
	{
		if (bb->str[i][j + 1] == 'P')
			ft_lose(bb);
		bb->str[i][j + 1] = 'M';
		bb->str[i][j] = '0';
		ft_put_draw(bb);
	}
	else if ((rand() % 4 == 1) && (bb->str[i][j - 1] == '0'
		|| bb->str[i][j - 1] == 'P'))
	{
		if (bb->str[i][j - 1] == 'P')
			ft_lose(bb);
		bb->str[i][j - 1] = 'M';
		bb->str[i][j] = '0';
		ft_put_draw(bb);
	}
	else
		move_enemy2(bb, i, j);
}

void	move_enemy(t_map *bb)
{
	int				i;
	static size_t	j;

	i = -1;
	while (bb->str[++i])
	{
		if (bb->str[i][j] == 'M')
		{
			move_enemy1(bb, i, j);
		}
	}
	j++;
	if (j == ft_strlen(bb->str[1]))
		j = 0;
}

int	ft_enemy(t_map *bb)
{
	if (bb->count > 0 && bb->count < 26)
		mlx_destroy_image(bb->mlx_ptr, bb->enemy);
	if (bb->count <= 5)
		bb->enemy = mlx_xpm_file_to_image(bb->mlx_ptr,
				"./xpm/enemy.xpm", &bb->width, &bb->height);
	else if (bb->count <= 10)
		bb->enemy = mlx_xpm_file_to_image(bb->mlx_ptr,
				"./xpm/enemy2.xpm", &bb->width, &bb->height);
	else if (bb->count <= 15)
		bb->enemy = mlx_xpm_file_to_image(bb->mlx_ptr,
				"./xpm/enemy3.xpm", &bb->width, &bb->height);
	else if (bb->count <= 20)
		bb->enemy = mlx_xpm_file_to_image(bb->mlx_ptr,
				"./xpm/enemy4.xpm", &bb->width, &bb->height);
	else if (bb->count <= 25)
		bb->enemy = mlx_xpm_file_to_image(bb->mlx_ptr,
				"./xpm/enemy5.xpm", &bb->width, &bb->height);
	else if (bb->count > 26)
		bb->count = 0;
	ft_check(bb, bb->enemy);
	move_enemy(bb);
	bb->count++;
	ft_put_draw(bb);
	print_move(bb);
	return (0);
}

void	ft_check_ext(char **av)
{
	if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".ber", 4))
	{
		ft_printf("\033[0;31mERROR <Invalid entry (.ber!!)>", 1);
		exit(1);
	}
}
