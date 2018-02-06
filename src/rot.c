/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:55:37 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/05 20:51:19 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	rot_suite(t_xyz *fdf)
{
	int r;
	int c;

	r = -1;
	while (++r < fdf->row)
	{
		c = -1;
		while (++c < fdf->col)
		{
			rot_y(fdf, fdf->rot_y, r, c);
			rot_z(fdf, fdf->rot_z, r, c);
			rot_x(fdf, fdf->rot_x, r, c);
		}
	}
}
