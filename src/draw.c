/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:55:22 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/09 01:30:39 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

unsigned int		blend(unsigned int c1, unsigned int c2)
{
	int				r;
	int				g;
	int				b;
	unsigned int	ret;

	r = (c1 / 0x10000 + c2 / 0x10000) / 2;
	g = ((c1 % 0x10000) / 0x100 + (c2 % 0x10000) / 0x100) / 2;
	b = (c1 % 0x100 + c2 % 0x100) / 2;
	ret = r << 16 | g << 8 | b;
	return (ret);
}

void				colorize(t_xyz *fdf, t_bres breezy, int r, int c)
{
	int				pos;

	pos = c + (r * fdf->s_line / 4);
	if (pos >= 0 && pos < fdf->size * fdf->size)
		if ((c >= 0 && c < fdf->col) && (r >= 0 && r < fdf->row))
			fdf->canvas[pos] = blend(breezy.a.iro, breezy.b.iro);
}

void				draw(t_xyz *fdf, int r, int c, char check)
{
	t_bres			breezy;
	int				r1;
	int				c1;

	r1 = check == 'r' ? r + 1 : r;
	c1 = check == 'c' ? c + 1 : c;
	breezy = bresenham(fdf->twist[r][c], fdf->twist[r1][c1]);
	breezy.numerator = breezy.longest >> 1;
	while (++breezy.i <= breezy.longest)
	{
//		colorize(fdf, breezy, r, c);
		mlx_pixel_put(fdf->mlx, fdf->win, breezy.x1, breezy.y1,
			blend(breezy.a.iro, breezy.b.iro));
		breezy.numerator += breezy.shortest;
		if (breezy.numerator > breezy.longest)
		{
			breezy.numerator -= breezy.longest;
			breezy.x1 += breezy.dx1;
			breezy.y1 += breezy.dy1;
		}
		else
		{
			breezy.x1 += breezy.dx2;
			breezy.y1 += breezy.dy2;
		}
	}
}

void				first_draw(t_xyz *fdf)
{
	int				r;
	int				c;

	mlx_clear_window(fdf->mlx, fdf->win);
	r = -1;
	while (++r < fdf->row)
	{
		c = -1;
		while (++c < fdf->col)
		{
			c + 1 < fdf->col ? draw(fdf, r, c, 'c') : 0;
			r + 1 < fdf->row ? draw(fdf, r, c, 'r') : 0;
		}
	}
}

//void				first_draw(t_xyz *fdf)
//{
//	fdf->img = mlx_new_image(fdf->mlx, fdf->size, fdf->size);
//	fdf->canvas = (int *)mlx_get_data_addr(fdf->img, &fdf->bits, &fdf->s_line,
//		&fdf->endian);
//	intake(fdf);
//	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
//	mlx_destroy_image(fdf->mlx, fdf->img);
//}
