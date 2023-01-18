/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:19:16 by fbily             #+#    #+#             */
/*   Updated: 2023/01/18 19:05:25 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include "mlx.h"
#include "stdbool.h"
#include "limits.h"
#include <stdio.h>
#include <errno.h>

enum e_ids
{
	NO,
	SO,
	WE,
	EA,
    F,
    C,
};

typedef struct s_tex
{
    bool            check;
    void	        *img;
	int		        width;
	int		        height;
    char            *path;
    unsigned char    colors[3];
}               t_tex;

typedef struct s_parser
{
    char            **file;
    char            **map;
    char            *path_file;
    int             lines_count;
    char            orientation;
    t_tex           textures[6];
    int             elements_count;
}               t_parser;

/******************************          PARSING.C           ***************************/
bool    parsing(t_parser *parser);
bool    check_file(t_parser *parser);
bool    get_file(t_parser *parser);

/* 
Contraintes :

- Rien apres la map
- "Error\n" + Message explicite

Info :
- Chaque info separee par 1 ou + '\n'
- Orde aleatoire
- Chaque info peut comporter X espace entre chaque element.
- Liste ID : NO / SO / WE / EA / F / C

F & C :
- (char *)ID + (int)tab[0] in range [0,255]

Textures :
- (char *)ID + (char *)path_to_textures

Map :
- 6 caracteres only : 0 & 1 + [N / S / E / W] (= orientation joueur)
- Entouree de murs [1]
- Gerer espace autour de la map
- 
 */

/* 

typedef struct s_tex
{
	void	*img;
	int		width;
	int		height;
}				t_tex;

tex.img = mlx_xpm_file_to_image(vars->mlx, "textures/FILE.xpm",
			&vars->tex.width, &vars->tex.height); 
            

*/