/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:23:23 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/19 21:34:04 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include "printf/ft_printf.h"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

typedef struct b_map
{
    void *mlx_ptr;
    void *win_ptr;
    int fd;
    int i;
    int j;
    int collectible;
    int escape;
    int player;
    char **str;
    char *tab;
    int width;
    int height;
    void *pl;
    void *wl;
    int x;
    int y;
    void *backgr;
    void *door;
    void *collect;
    char **strBacktr;
    int move;
} l_map;

//--------------------------FONCTION PROTOTYPE--------------------------//
size_t	ft_strlen(char *str);
int 	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void    ft_check_map(l_map *bb);
void    ft_check_wall_sidebar(l_map *bb);
int     ft_check_wall(l_map *bb);
int     ft_close(l_map *bb);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
int ft_maplen(char **str);
char **ft_read_map_backtr(l_map *bb ,char *av);
int      ft_check_rctgl(l_map *bb);
char	*ft_read(char *str, int fd);
char	*ft_line(char *str);
void ft_draw_map(l_map *bb);
void ft_check(l_map *bb);
void ft_put_draw(l_map *bb);
int ft_move(int keycode, l_map *bb);
int ft_win(l_map *bb);
void ft_back_tracking(l_map *bb);
int ft_map_colum_bcktr(l_map *bb);
int ft_map_colum(l_map *bb, char **av);
int ft_check_bcktr(char c,char **strB, int i, int j);
void ft_free_bktr(l_map *bb);
void copystr(l_map *bb);
char	*ft_strdup(char *s1);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
#endif