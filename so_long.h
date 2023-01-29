/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:23:23 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/28 20:47:31 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct b_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	int		i;
	int		j;
	int		collectible;
	int		escape;
	int		player;
	char	**str;
	char	*tab;
	int		width;
	int		height;
	void	*pl;
	void	*wl;
	int		x;
	int		y;
	void	*backgr;
	void	*door;
	void	*collect;
	char	**strback;
	int		move;
}			t_map;

//--------------------------FONCTION PROTOTYPE--------------------------//
//---------------UTIL FILE---------------------------//
size_t		ft_strlen(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strdup(char *s1);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char *left_str, char *buff);
char		*get_next_line(int fd);
char		*ft_read(char *str, int fd);
char		*ft_line(char *str);
char		*ft_strchr(char *s, int c);
//---------------SRC fiLE-----------------------------//
void		ft_check_map(t_map *bb);
void		ft_check_wall_sidebar(t_map *bb);
int			ft_check_wall(t_map *bb);
int			ft_close(t_map *bb);
int			ft_maplen(char **str);
char		**ft_read_map_backtr(t_map *bb, char *av);
int			ft_check_rctgl(t_map *bb);
void		ft_move_left(t_map *bb);
int			ft_check_collect(t_map *bb);
void		ft_draw_map(t_map *bb);
void		ft_check(t_map *bb, void *ptr);
void		ft_put_draw(t_map *bb);
int			ft_move(int keycode, t_map *bb);
void		ft_move_right(t_map *bb);
int			ft_win(t_map *bb);
void		ft_back_tracking(t_map *bb);
int			ft_map_colum_bcktr(t_map *bb);
int			ft_map_colum(t_map *bb, char **av);
int			ft_check_bcktr(char c, char **strB, int i, int j);
void		ft_free_bktr(t_map *bb);
void		copystr(t_map *bb);
void		ft_move_up(t_map *bb);
void		ft_move_down(t_map *bb);
void		ft_free(t_map *bb);

#endif