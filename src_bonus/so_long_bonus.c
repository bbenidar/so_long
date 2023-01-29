/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:47:16 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/26 21:07:02 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_map_colum(t_map *bb, char **av)
{
	int	i;

	i = 0;
	bb->fd = open(av[1], O_RDONLY);
	if (bb->fd < 0)
	{
		ft_printf("\033[0;31mERROR <file doasn't work>");
		exit(1);
	}
	bb->tab = get_next_line(bb->fd);
	while (bb->tab)
	{
		free(bb->tab);
		bb->tab = get_next_line(bb->fd);
		i++;
	}
	return (i);
}

void	ft_read_map(t_map *bb, char **av)
{
	bb->i = ft_map_colum(bb, av);
	if (bb->i * 64 > 1500)
	{
		ft_printf("ERROR MAP SO LONG\n");
		exit(1);
	}
	bb->str = (char **)malloc((bb->i + 1) * sizeof(char *));
	if (!bb->str)
	{
		free(bb->str);
		exit(1);
	}
	close(bb->fd);
	bb->j = 0;
	bb->fd = open(av[1], O_RDONLY);
	if (bb->fd < 0)
	{
		ft_printf("\033[0;31mERROR <file doasn't work>");
		exit(1);
	}
	while (bb->j < bb->i)
		bb->str[bb->j++] = get_next_line(bb->fd);
	bb->str[bb->j] = 0;
}

int	main(int ac, char **av)
{
	t_map	bb;

	bb.i = 0;
	bb.move = 0;
	if (ac != 2)
	{
		ft_printf("\033[0;31mERROR(pleas insert map *.ber !)\n");
		exit(1);
	}
	ft_check_ext(av);
	ft_read_map(&bb, av);
	ft_check_map(&bb);
	ft_check_wall(&bb);
	ft_check_wall_sidebar(&bb);
	ft_check_rctgl(&bb);
	ft_back_tracking(&bb);
	ft_draw_map(&bb);
	mlx_hook(bb.win_ptr, 17, 0, ft_close, &bb);
	mlx_hook(bb.win_ptr, 2, 0, ft_move, &bb);
	bb.count = 0;
	mlx_loop_hook(bb.mlx_ptr, ft_enemy, &bb);
	mlx_loop(bb.mlx_ptr);
	return (0);
}
