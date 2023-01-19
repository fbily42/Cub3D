/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:25:23 by fbily             #+#    #+#             */
/*   Updated: 2023/01/19 19:29:00 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parsing(t_parser *parser)
{
	if (check_file(parser) == false)
		return (false);
	if (get_file(parser) == false)
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

int	count_lignes(char *file_path)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error\n", 7);
		perror("open ");
		return (-1);
	}
	while (42)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	close(fd);
	free(line);
	return (count);
}

bool	get_file(t_parser *parser)
{
	int	i;
	int	fd;

	i = 0;
	parser->lines_count = count_lignes(parser->path_file);
	if (parser->lines_count == -1)
		return (false);
	parser->file = malloc(sizeof(char *) * (parser->lines_count + 1));
	if (!parser->file)
		return (ft_printf_fd(STDERR_FILENO, "Error\nMalloc failed.\n"), false);
	fd = open(parser->path_file, O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error\n", 7);
		perror("open ");
		return (false);
	}
	while (42)
	{
		parser->file[i] = get_next_line(fd);
		if (parser->file[i] == NULL)
			break ;
		i++;
	}
	return (close(fd), true);
}
