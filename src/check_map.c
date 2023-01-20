/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:27:31 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/08 11:50:47 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_check_rctgl(l_map *bb)
{
    size_t len;
    int i;

    i = 0;
    len = ft_strlen(bb->str[1]);
    while(bb->str[i])
    {
        if (len != ft_strlen(bb->str[i]))
        {
            ft_printf("\033[0;31mERROR (the map is not a rectangle)");
			exit(1);
        }
        else
            i++;
    }
    return len;
}
int ft_maplen(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void ft_check_map(l_map *bb)
{
    bb->collectible = 0;
    bb->player = 0;
    bb->escape = 0;
    bb->j = ft_maplen(bb->str) - 1;
    while(bb->j > 0)
    {
        bb->i = 0;
        while(bb->str[bb->j][bb->i])
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
            else if (bb->str[bb->j][bb->i] == '1' || bb->str[bb->j][bb->i] == '0')
                bb->i++;
            else
            { 
                ft_printf("ERROR IN MAP\n");
                ft_close(bb);
            }
        }
        bb->j--;
    }
    if(bb->player != 1 || bb->escape < 1 || bb->collectible < 1)
    {
        ft_printf("ERROR IN MAP\n");
        ft_close(bb);
    }
}

int ft_check_wall(l_map *bb)
{
    int i;

    i = 0;
    bb->j = ft_maplen(bb->str) - 1;
    while(bb->str[0][i] && bb->str[bb->j][i])
    {
        if(bb->str[0][i] == '1' && bb->str[bb->j][i] == '1')
            i++;
        else
        {
            ft_printf("\033[0;31mERROR (the map wall need fix)");
            exit(1);
        }
    }
    return (0);
}
void ft_check_wall_sidebar(l_map *bb)
{
	int	j;
	int	k;

	k = ft_maplen(bb->str) - 1;
	j = ft_strlen(bb->str[k]) - 1;
	while (k >= 0 )
	{
		if (!(bb->str[k][0] == '1' && bb->str[k][j] == '1'))
		{
			ft_printf("\033[0;31mERROR (the map sidebar wall need fix)");
			exit(1);
		}
		k--;
	}
} 

