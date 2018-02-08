/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:55:22 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/08 01:43:20 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw(t_xyz *fdf, int i, int j)

void	intake(t_xyz *fdf, t_vis *zen)
{
	int		r;
	int		c;
	int		i;

	r = -1;
	i = 0;
	while (r < fdf->row)
	{
		c = -1;
		while (c < fdf->col)
		{
			c + 1 < fdf->col ? draw(fdf, i, i + 1) : 0;
			r + 1 < fdf->row ? draw(fdf, i, i + fdf->col) : 0;
			++i;
		}
	}
}

void	first_draw(t_xyz *fdf, t_vis *zen)
{
	zen->img = mlx_new_image(zen->mlx, zen->size, zen->size);
	zen->canvas = (int *)mlx_get_data_addr(zen->img, &zen->bits, &zen->s_line,
		&zen->endian);
	intake(fdf, &zen);
	mlx_put_image_to_window(zen->mlx, zen->win, zen->img, 0, 0);
	mlx_destroy_image(zen->mlx, zen->img);
}
