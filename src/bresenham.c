/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:46:49 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/08 22:25:20 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_bres	bresenham(t_jig a, t_jig b)
{
	t_bres	ret;
	double	tmp;

	tmp = 0;
	ret.a = a;
	ret.b = b;
	ret.dx = b.x - a.x > 0 ? b.x - a.x : (-1 * (b.x - a.x));
	ret.dy = b.y - a.y > 0 ? b.y - a.y : (-1 * (b.y - a.y));
	ret.sx = b.x - a.x > 0 ? 1 : -1;
	ret.sy = b.y - a.y > 0 ? 1 : -1;
	ret.swap = 0;
	if (ret.dy > ret.dx)
	{
		tmp = ret.dx;
		ret.dx = ret.dy;
		ret.dy = tmp;
		ret.swap = 1;
	}
	ret.err = 2 * (ret.dy - ret.dx);
	return (ret);
}
