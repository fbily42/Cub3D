/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:25:23 by fbily             #+#    #+#             */
/*   Updated: 2023/01/23 18:12:30 by fbily            ###   ########.fr       */
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
	if (read_textures(parser) == false)
		return (false);
	if (test_textures(parser) == false)
		return (false);
	stock_colors(parser);
	if (check_map(parser) == false)
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

bool	read_textures(t_parser *parser)
{
	int	i;

	i = 0;
	while (parser->tex_lines[i])
	{
		if (parser->tex_lines[i][0] == 'N' || parser->tex_lines[i][0] == 'S'
			|| parser->tex_lines[i][0] == 'W' || parser->tex_lines[i][0] == 'E')
		{
			if (handle_textures(parser, i) == false)
				return (false);
		}
		else if (parser->tex_lines[i][0] == 'F'
			|| parser->tex_lines[i][0] == 'C')
		{
			if (get_colors(parser, i) == false)
				return (false);
		}
		else
		{
			ft_printf_fd(2, "Error\nProblem with texture's description.\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	test_textures(t_parser *parser)
{
	int	i;

	i = 0;
	if (check_textures(parser) == false)
		return (ft_printf_fd(2, "Error\nMissing texture.\n"), false);
	while (i <= EA)
	{
		parser->textures[i].img = mlx_xpm_file_to_image(parser->mlx,
				parser->textures[i].path, &parser->textures[i].width,
				&parser->textures[i].height);
		if (parser->textures[i].img == NULL)
		{
			ft_printf_fd(STDERR_FILENO, "Error\nMlx error with xpm files.\n");
			return (false);
		}
		i++;
	}
	while (i <= C)
	{
		if (convert_colors(parser, i) == false)
			return (false);
		i++;
	}
	return (true);
}

void	stock_colors(t_parser *parser)
{
	int	i;

	i = F;
	while (i <= C)
	{
		parser->textures[i].hexa_color |= parser->textures[i].colors[0] << 16;
		parser->textures[i].hexa_color |= parser->textures[i].colors[1] << 8;
		parser->textures[i].hexa_color |= parser->textures[i].colors[2];
		i++;
	}
}
