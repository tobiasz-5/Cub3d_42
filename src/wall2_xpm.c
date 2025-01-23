/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall2_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschetti <tschetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:45:19 by tschetti          #+#    #+#             */
/*   Updated: 2025/01/23 17:16:29 by tschetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
uso di mlx_xpm_file_to_image per caricare a schermo un xpm. 
game->mlx puntatore al server,
poi abbiamo il path del file, e infine larghezza e altezza
mlx_get_data_addr ottiene l indirizzo dei dati dell'immagine,
permettendo l'accesso a bpp, line_size e endian -> bit per pixel, 
byte per riga, ordine dei byte
*/
void	load_a_texture(t_game *game, t_tex *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		ft_putendl_fd("Error\nFailed to load texture", 2);
		exit(1);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_size, &texture->endian);
}

//carica le varie textures
void	load_textures(t_game *game)
{
	load_a_texture(game, &game->tex_no, game->map.path_no);
	load_a_texture(game, &game->tex_so, game->map.path_so);
	load_a_texture(game, &game->tex_we, game->map.path_we);
	load_a_texture(game, &game->tex_ea, game->map.path_ea);
	load_a_texture(game, &game->tex_hands, game->map.path_hands);
}
