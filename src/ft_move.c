/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:33:00 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/20 14:53:16 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_check_collect(l_map *bb)
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
                bb->collectible++;
            bb->i++;
        }
        bb->j--; 
    } 
    return (bb->collectible);        
}

void ft_move_left(l_map *bb)
{
    int i;
    int j;

    i = -1;
    while(bb->str[++i])
    {
        j = 0;
        while(bb->str[i][j])
        {
            if (bb->str[i][j] == 'P')
            {
                if (bb->str[i][j - 1] == '0')
                {
                    bb->str[i][j - 1] = 'P';
                    bb->str[i][j] = '0';
                    ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                    break;
                }
                else if (bb->str[i][j - 1] == 'C')
                {
                    bb->str[i][j - 1] = 'P';
                    bb->str[i][j] = '0';
                    ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                }
                else if (bb->str[i][j - 1] == 'E')
                {
                    if (ft_check_collect(bb) == 0)
                    {
                        bb->str[i][j - 1] = 'P';
                        bb->str[i][j] = '0';
                        ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                        ft_win(bb);
                    }
                }

            }
            j++;
        }
    }
}

void ft_move_right(l_map *bb)
{
    int i;
    int j;

    i = -1;
    while(bb->str[++i])
    {
        j = 0;
        while(bb->str[i][j])
        {
            if (bb->str[i][j] == 'P')
            {
                if (bb->str[i][j + 1] == '0')
                {
                    bb->str[i][j + 1] = 'P';
                    bb->str[i][j] = '0';
                    ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                    break;
                }
                else if (bb->str[i][j + 1] == 'C')
                {
                    bb->str[i][j + 1] = 'P';
                    bb->str[i][j] = '0';
                    ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                }
                else if (bb->str[i][j + 1] == 'E')
                {
                    if (ft_check_collect(bb) == 0)
                    {
                        bb->str[i][j + 1] = 'P';
                        bb->str[i][j] = '0';
                        ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                        ft_win(bb);
                    }
                }

            }
            j++;
        }
    }
}

void ft_move_down(l_map *bb)
{
    int i;
    int j;

    i = ft_maplen(bb->str) - 1;
    while(i >= 0)
    {
        j = 0;
        while(bb->str[i][j])
        {
            if (bb->str[i][j] == 'P')
            {
                if (bb->str[i + 1][j] == '0')
                {
                    bb->str[i + 1][j] = 'P';
                    bb->str[i][j] = '0';
                    ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                }
                else if (bb->str[i + 1][j] == 'C')
                {
                    bb->str[i + 1][j] = 'P';
                    bb->str[i][j] = '0';
                    ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                }
                else if (bb->str[i + 1][j] == 'E')
                {
                    if (ft_check_collect(bb) == 0)
                    {
                        bb->str[i + 1][j] = 'P';
                        bb->str[i][j] = '0';
                        ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                        ft_win(bb);
                    }
                }

            }
            j++;
        }
        i--;
    }
}

void ft_move_up(l_map *bb)
{
    int i;
    int j;

    i = -1;
    while(bb->str[++i])
    {
        j = 0;
        while(bb->str[i][j])
        {
            if (bb->str[i][j] == 'P')
            {
                if (bb->str[i - 1][j] == '0')
                {
                    bb->str[i - 1][j] = 'P';
                    bb->str[i][j] = '0';
                    ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                    break;
                }
                else if (bb->str[i - 1][j] == 'C')
                {
                    bb->str[i - 1][j] = 'P';
                    bb->str[i][j] = '0';
                    ft_printf("\033[0;33mMOVES : %d\n", ++bb->move);
                }
                else if (bb->str[i - 1][j] == 'E')
                {
                    if (ft_check_collect(bb) == 0)
                    {
                        bb->str[i - 1][j] = 'P';
                        bb->str[i][j] = '0';
                        ft_win(bb);
                    }
                }

            }
            j++;
        }
    }
}

int ft_move(int keycode, l_map *bb)
{
    if(keycode == 53)
    {
        ft_printf("%d\n", keycode);
        ft_close(bb);  
    }
    if(keycode == 13 || keycode == 126)
        ft_move_up(bb); 
    if(keycode == 1 || keycode == 125)
        ft_move_down(bb);
    if(keycode == 2 || keycode == 124)
        ft_move_right(bb);
    if(keycode == 0 || keycode == 123)
        ft_move_left(bb); 
    ft_put_draw(bb);
    return (0);
}