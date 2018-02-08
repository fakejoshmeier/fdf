/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:55:21 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/07 16:44:06 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	error(char *str)
{
	ft_putstr("Error: ");
	ft_putstr(str);
	exit(0);
}

int		main(int ac, char *av[])
{
	t_xyz	*fdf;
	t_vis	zen;

	ac == 2 ? 0 : error("Usage ./fdf [TEST.fdf]\n");
	ft_strstr(av[1], ".fdf") ? 0 : error("Invalid filetype\n");
	fdf = ft_memalloc(sizeof(t_xyz *));
	parse_suite(fdf, av[1]);
//	first_things_first(fdf, &zen);
	rot_suite(fdf);
	zen.mlx = mlx_init();
	zen.win = mlx_new_window(zen.mlx, zen.img_dim, zen.img_dim, av[1]);
	zen.img_dim > 0 ? 0 : error("Window Size Untenable\n");
	rot_suite(fdf);
	
	zen.img = mlx_new_image(zen.mlx, zen.img_dim, zen.img_dim);


	zen.canvas = (int*)mlx_get_data_addr(zen.img, &zen.bits, &zen.s_line,
		&zen.endian);
//	zen.canvas[x + (y * s_line / 4)] = zen.color;
	mlx_put_image_to_window(zen.mlx, zen.win, zen.img, 500, 500);
	mlx_destroy_image(zen.mlx, zen.img);
	return (0);
}
