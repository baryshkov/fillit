/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:29:57 by wconnell          #+#    #+#             */
/*   Updated: 2019/02/13 14:15:37 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include "libft/libft.h"
# define TETR(x) ((t_t *)((x->content)))->coord
# define CHAR(x) ((t_t *)((x->content)))->c
# define HEIGHT(x)  ((t_t *)((x->content)))->height
# define WID(x)  ((t_t *)((x->content)))->width
# define MC(x) if (!x) ft_bust("MALLOC RETURNED NULL")

typedef struct			s_t
{
	char				c;
	int					*coord;
	int					height;
	int					width;
}						t_t;

typedef struct			s_map
{
	char				**map;
	int					size;
}						t_map;

char					**ft_solver(t_list *list, char **arr, int size);
int						ft_solvemap(t_list *list, char **arr, int size);
void					place(int x, int y, t_list *list, char **arr);
void					placedot(int x, int y, t_list *list, char **arr);
int						ft_canweplace(int x, int y, t_list *list, char **arr);
int						ft_find_min_x(int *s);
int						ft_find_min_y(int *s);
int						ft_height(int *s);
int						ft_width(int *s);
int						*ft_get_right_coordinates(int *s);
void					ft_checkformod16(char *s, int f);
t_list					*ft_create_head(t_list **lst);
void					ft_checkforvalidlength(char *s, int i);
void					ft_check_symbols(char **line);
void					ft_bust(char *str);
char					*ft_convert_to_line(const int fd);
char					**ft_create_arr(char **line);
void					ft_free_arr(char **arr);
void					ft_free_list(t_list *head);
char					**ft_create_map(int tet);
int						ft_check_tetro(char **ar);
int						ft_check_connections(char **arr);
void					ft_megastart(char **arr, t_list **head);
t_list					*ft_pushback(int *s, int j, t_list **head);
int						ft_get_map_size(int tet);
void					ft_print_map(char **arr);

#endif
