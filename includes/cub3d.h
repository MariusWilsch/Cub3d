/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:57:53 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/04 00:56:30 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdlib.h>
#include"../get_next_line/get_next_line.h"
#include"../libft/libft.h"

#define SO "SO"
#define WE "WE"
#define NO "NO"
#define EA "EA"

#define C 'C'
#define F 'F'

#define WL '1'
#define EM '0'

typedef struct  s_map
{
    char    *line;
    int     type;
    int     index;
    struct  s_map *next;
    struct  s_map *prev;
}               t_map;


typedef struct  s_data
{
    t_map   *lmap;
    char    **map;
}               t_data;

bool    parser(char **av, t_data *data);
void    add_node(t_data *data, int *index_ptr, t_map **ptr);
char    **str_to_2d(t_data *data, char *line);
int     fl_line (char *line);
int     check_line(char *line, t_data *data, t_map *ptr);
int     check_map(char *line);

int direction_identifier(char *line);
int find_comma(char *line);
int get_color(char *line);
int floor_ceiling_handler(char *line);
int direction_handler(char *line);
void map_handler(t_data *data, int map_fd);
bool handle_file(int map_fd, t_data *data);

//////////////////////// Tools ////////////////////////////////
void    exit_error(t_data *data, int fr, char *err);
int     is_whitespace(char c);
int     white_check(char *str);
int     all_isdigit(char *str);
int     ft_2dstrlen(char **str2d);
void    free_map_list(t_data *data);
void    display_list(t_map *list);
void    display_table(char **table);

#endif