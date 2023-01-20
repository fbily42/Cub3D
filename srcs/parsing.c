/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:25:23 by fbily             #+#    #+#             */
/*   Updated: 2023/01/20 19:30:35 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parsing(t_parser *parser)
{
	if (check_file(parser) == false)
		return (false);
	if (get_file(parser) == false)
		return (false);
	if (divide_file(parser) == false)
		return (false);
	if (check_textures(parser) == false)
		return (false);
	return (true);
}

bool	check_file(t_parser *parser)
{
	char	*pts;
	int		fd;

	pts = ft_strrchr(parser->path_file, '.');
	if (pts == NULL || ft_strncmp(pts, ".cub", 5) != 0
		|| *pts == *parser->path_file)
	{
		ft_printf_fd(STDERR_FILENO, "Error\nMap must be a '.cub' file.\n");
		return (false);
	}
	fd = open(parser->path_file, __O_DIRECTORY);
	if (fd >= 0)
	{
		ft_printf_fd(STDERR_FILENO, "Error\nThis is a directory.\n");
		return (close(fd), false);
	}
	fd = open(parser->path_file, O_RDWR);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error\n", 7);
		perror("open ");
		return (false);
	}
	close(fd);
	return (true);
}

bool	check_textures(t_parser *parser)
{
	int	i;

	i = 0;
	while (parser->tex_lines[i])
	{
		if (parser->tex_lines[i][0] == 'N')
			get_textures(parser, NO, i);
		else if (parser->tex_lines[i][0] == 'S')
			get_textures(parser, SO, i);
		else if (parser->tex_lines[i][0] == 'W')
			get_textures(parser, WE, i);
		else if (parser->tex_lines[i][0] == 'E')
			get_textures(parser, EA, i);
		else if (parser->tex_lines[i][0] == 'F')
			get_textures(parser, F, i);
		else if (parser->tex_lines[i][0] == 'C')
			get_textures(parser, C, i);
		else
			return (false);
		i++;
	}
	return (true);
}

void	get_textures(t_parser *parser, int id, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	parser->textures[id].path = ft_strdup(parser->tex_lines[index]);
	parser->textures[id].check = true;
}
