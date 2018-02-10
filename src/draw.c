/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:55:22 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/10 15:19:01 by jmeier           ###   ########.fr       */
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

void	fillin(t_bres *ret)
{
	ret->dx1 = ret->w < 0 ? -1 : 1;
	ret->dy1 = ret->h < 0 ? -1 : 1;
	ret->dx2 = ret->w < 0 ? -1 : 1;
	ret->longest = ret->w > 0 ? ret->w : -1 * ret->w;
	ret->shortest = ret->h > 0 ? ret->h : -1 * ret->h;
	if (ret->longest < ret->shortest)
	{
		ret->longest = ret->h > 0 ? ret->h : -1 * ret->h;
		ret->shortest = ret->w > 0 ? ret->w : -1 * ret->w;
		ret->dy2 = ret->h < 0 ? -1 : 1;
		ret->dx2 = 0;
	}
}

t_bres	bresenham(t_jig a, t_jig b)
{
	t_bres	ret;

	ret.a = a;
	ret.b = b;
	ret.x1 = a.x;
	ret.y1 = a.y;
	ret.x2 = b.x;
	ret.y2 = b.y;
	ret.i = -1;
	ret.w = ret.x2 - ret.x1;
	ret.h = ret.y2 - ret.y1;
	ret.dx1 = 0;
	ret.dy1 = 0;
	ret.dx2 = 0;
	ret.dy2 = 0;
	fillin(&ret);
	return (ret);
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
