/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 23:46:11 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/08 00:05:13 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	scale(t_xyz *fdf, t_vis *zen)
{
	int		r;
	int		c;
	double	xs;
	double	ys;

	r = -1;
	while (++r < fdf->row)
	{
		c = -1;
		while (++c < fdf->col)
		{
			xs = (fdf->twist[r][c].x * (zen->size / (fdf->col + 1)) / 2) *
				(fdf->scale * fdf->scale);
			ys = (fdf->twist[r][c].y * (zen->size / (fdf->row + 1)) / 2) *
				(fdf->scale * fdf->scale);
			fdf->twist[r][c].x = xs + fdf->x_it + (zen->size / 4);
			fdf->twist[r][c].y = ys + fdf->y_it + (zen->size / 4);
			fdf->twist[r][c].z *= (zen->size /100);
		}
	}
}


