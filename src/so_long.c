/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:23:10 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/20 15:37:05 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_colum(l_map *bb, char **av)
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

void	ft_read_map(l_map *bb, char **av)
{
	bb->i = ft_map_colum(bb, av);
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
	bb->str[bb->j] = NULL;
}

int	main(int ac, char **av)
{
	l_map	bb;

	bb.i = 0;
	bb.move = 0;
	if (ac != 2)
	{
		ft_printf("\033[0;31mERROR(pleas insert map *.ber !)\n");
		exit(1);
	}
	if (ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".ber", 4))
	{
		ft_printf("\033[0;31mERROR <Invalid entry (.ber!!)>", 1);
		exit(1);
	}
	ft_read_map(&bb, av);
	ft_back_tracking(&bb);
	ft_check_map(&bb);
	ft_check_wall(&bb);
	ft_check_wall_sidebar(&bb);
	ft_check_rctgl(&bb);
	ft_draw_map(&bb);
	mlx_hook(bb.win_ptr, 17, 0, ft_close, &bb);
	mlx_hook(bb.win_ptr, 2, 0, ft_move, &bb);
	mlx_loop(bb.mlx_ptr);
	return (0);
}
