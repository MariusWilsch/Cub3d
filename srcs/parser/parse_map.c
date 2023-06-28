/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 04:46:55 by ahammout          #+#    #+#             */
/*   Updated: 2023/06/27 22:41:01 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"

int	one_player(char *line, int *player)
{
	int	i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (line[i] == 'N' || line[i] == 'S' \
				|| line[i] == 'E' || line[i] == 'W')
				*player += 1;
			i++;
		}
		if (*player > 1)
			return (ft_putstr_fd("Cub3d: Multiple players", 2), -1);
	}
	return (0);
}

int	check_map(char *line)
{
	char	*comps;
	int		i;
	int		j;

	i = 0;
	if (!line)
		return (0);
	comps = ft_strdup("\nSWNE01 ");
	while (line[i])
	{
		j = 0;
		while (comps[j])
		{
			if (line[i] == comps[j])
				break ;
			j++;
		}
		if (!comps[j])
			return (ft_putstr_fd("Cub3d: Invalid comp", 2), -1);
		i++;
	}
	free(comps);
	return (0);
}

void	handle_map(t_data *data, int map_fd, char *holder)
{
	char	*line;
	int		player;
	char	*to_free;
	int		i;

	line = ft_strdup("");
	i = 0;
	player = 0;
	while (line)
	{
		free(line);
		line = get_next_line(map_fd);
		if (check_map(line) == -1 || one_player(line, &player) == -1)
			exit_error(data, 1, NULL);
		to_free = holder;
		holder = ft_strjoin(holder, line);
		if (line)
			free(to_free);
		i++;
	}
	if (player == 0)
		exit_error(data, 1, "Cub3d: The player is missing!");
	if (holder)
		data->map = ft_split(holder, '\n');
	free(holder);
	analyze_map(data);
}