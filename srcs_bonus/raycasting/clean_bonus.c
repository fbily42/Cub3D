/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:08:11 by sbeylot           #+#    #+#             */
/*   Updated: 2023/01/26 10:58:58 by sbeylot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	map = NULL;
}

void	free_map_int(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < cub->info.map_row)
		free(cub->map[i++]);
	free(cub->map);
}

void	clean_rays(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < WINDOW_WIDTH / STRIP)
		free(cub->tab_ray[i++]);
	free(cub->tab_ray);
}

void	clean_texture(t_cub3d *cub)
{
	if (cub->texture[0].img.img)
		mlx_destroy_image(cub->mlx_ptr, cub->texture[0].img.img);
	if (cub->texture[1].img.img)
		mlx_destroy_image(cub->mlx_ptr, cub->texture[1].img.img);
	if (cub->texture[2].img.img)
		mlx_destroy_image(cub->mlx_ptr, cub->texture[2].img.img);
	if (cub->texture[3].img.img)
		mlx_destroy_image(cub->mlx_ptr, cub->texture[3].img.img);
	free(cub->texture);
	clean_door_texture(cub);
}

void	clean_mlx(t_cub3d *cub)
{
	if (cub->tab_ray != NULL)
		clean_rays(cub);
	if (cub->texture != NULL)
		clean_texture(cub);
	if (cub->player != NULL)
	{
		if (cub->player->img.img)
			mlx_destroy_image(cub->mlx_ptr, cub->player->img.img);
		free(cub->player);
	}
	if (cub->map != NULL)
		free_map_int(cub);
	if (cub->img.img != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->img.img);
	if (cub->mmap.img != NULL)
		mlx_destroy_image(cub->mlx_ptr, cub->mmap.img);
	if (cub->win_ptr != NULL)
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	if (cub->mlx_ptr != NULL)
		mlx_destroy_display(cub->mlx_ptr);
	free(cub->mlx_ptr);
	clean_parsing(cub->parser);
	free_map(cub->parser->map.map);
}
