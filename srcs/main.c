/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:19:27 by fbily             #+#    #+#             */
/*   Updated: 2023/01/20 17:00:57 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing(t_parser *parser, char *argv)
{
	int	i;

	i = 0;
	parser->path_file = argv;
	parser->elements_count = 0;
	while (i <= C)
	{
		parser->textures[i].check = false;
		parser->textures[i].img = NULL;
		parser->textures[i].path = NULL;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_parser	parser;

	if (argc != 2)
	{
		ft_printf_fd(STDERR_FILENO, "%s", USAGE);
		return (false);
	}
	init_parsing(&parser, argv[1]);
	if (parsing(&parser) == false)
		return (-1);
	else
	{
		print_map(parser.tex_lines);
		print_map(parser.map);
	}
	free_map(parser.map);
	free_map(parser.tex_lines);
	return (0);
}

// Protection strdup dans divide_file ??