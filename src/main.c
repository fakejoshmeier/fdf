/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:55:21 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/09 01:46:06 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	first_things_first(t_xyz *fdf)
{
	fdf->rot_y = 583;
	fdf->size = 1000;
	fdf->scale = 1;
}

void	error(char *str)
{
	ft_putstr("Error: ");
	ft_putstr(str);
	exit(0);
}

int		main(int ac, char *av[])
{
	t_xyz	fdf;

	ac == 2 ? 0 : error("Usage ./fdf [TEST.fdf]\n");
	ft_strstr(av[1], ".fdf") ? 0 : error("Invalid filetype\n");
	ft_bzero(&fdf, sizeof(t_xyz));
	parse_suite(&fdf, av[1]);
	first_things_first(&fdf);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, fdf.size, fdf.size, av[1]);
//	fdf.img = mlx_new_image(fdf.mlx, fdf.size, fdf.size);
//	fdf.canvas = (int *)mlx_get_data_addr(fdf.img, &fdf.bits, &fdf.s_line,
//		&fdf.endian);
	fdf.size > 0 ? 0 : error("Window Size Untenable\n");
	rot_suite(&fdf);
	scale(&fdf);
	first_draw(&fdf);
	mlx_hook(fdf.win, 2, 0, zoom_hook, &fdf);
	mlx_loop(fdf.mlx);
}
