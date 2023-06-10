/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 02:29:12 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/10 21:47:28 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/cub3d.h"

int is_wall (char *line)
{
    int i;

    i = 0;
    if (empty_line(line))
        return (0);
    while (line[i])
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '1' && line[i] != '\n' && line[i] != '\0')
            return (0);
        i++;
    }
    return (1);
}

int surrounded_map(t_data *data)
{
    int x;
    int y;

    y = 1;
    while (data->map[y + 1])
    {
        if ((data->map[y][ft_strlen(data->map[y]) - 1] != '1' \
            && data->map[y][ft_strlen(data->map[y]) - 1] != ' ') \
            ||( data->map[y][0] != '1' && data->map[y][0] != ' '))
                return (-1);
        y++;
    }
    y = 1;
    while (data->map[y + 1])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '0' || data->map[y][x] == 'E' || data->map[y][x] == 'S' || data->map[y][x] == 'N' || data->map[y][x] == 'W')
            {
                // printf("line {%d}\n Up : %c\n down : %c\n left : %c\n Right : %c\n", y, data->map[y - 1][x], data->map[y + 1][x], data->map[y][x - 1], data->map[y][x + 1]);
                if (!data->map[y - 1][x] || data->map[y - 1][x] == ' ' || data->map[y - 1][x] == '\t' \
                    || !data->map[y - 1][x] || data->map[y + 1][x] == ' ' || data->map[y + 1][x] == '\t' \
                    || !data->map[y - 1][x] || data->map[y][x + 1] == ' ' || data->map[y][x + 1] == '\t' \
                    || !data->map[y - 1][x] || data->map[y][x - 1] == ' ' || data->map[y][x - 1] == '\t')
                    return (-1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

void    cut_last_lines(t_data *data)
{
    int     i;

    i = ft_2dstrlen(data->map) - 1;
    while (empty_line(data->map[i]))
    {
        free(data->map[i]);
        data->map[i] = NULL;
        i--;
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
void    analyze_map(t_data *data)
{
    int i;

    cut_last_lines(data);
    i = 0;
    while (data->map[i])
    {
        if (empty_line(data->map[i]))
            exit_error(data, 1, "Cub3d: Empty line inside the map!");
        i++;
    }
    if (!is_wall(data->map[ft_2dstrlen(data->map) - 1]) || surrounded_map(data) == -1)
        exit_error(data, 1, "Cub3d: Map must be souronded by Walls");
}