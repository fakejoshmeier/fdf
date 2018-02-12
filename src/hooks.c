/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:47:51 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/11 18:16:24 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	rot_zoom_draw(t_xyz *fdf, int iter, char check1, char check2)
{
	if (check1 == '+' && check2 == 'x')
		fdf->rot_x += iter;
	else if (check1 == '-' && check2 == 'x')
		fdf->rot_x -= iter;
	else if (check1 == '+' && check2 == 'z')
		fdf->rot_z += iter;
	else if (check1 == '-' && check2 == 'z')
		fdf->rot_z -= iter;
	rot_suite(fdf);
	zoom(fdf);
	first_draw(fdf);
}

void	pan_n_draw(t_xyz *fdf, int iter, char check)
{
	pan(fdf, iter, check);
	first_draw(fdf);
}

void	zoom_in_n_out(t_xyz *fdf, double iter, char check)
{
	if (check == '+')
		fdf->scale += iter;
	else if (check == '-')
		fdf->scale -= iter;
	rot_suite(fdf);
	zoom(fdf);
	first_draw(fdf);
}

/*
** 24 + pressed
** 27 - pressed
** 13 W pressed
**  0 A pressed
**  1 S pressed
**  2 D pressed
** 126 up pressed
** 125 down pressed
** 124 right pressed
** 123 left pressed
*/

int		zoom_hook(int keycode, t_xyz *fdf)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 27)
		zoom_in_n_out(fdf, .01, '-');
	if (keycode == 24)
		zoom_in_n_out(fdf, .01, '+');
	if (keycode == 13)
		pan_n_draw(fdf, -10, 'y');
	if (keycode == 0)
		pan_n_draw(fdf, -10, 'x');
	if (keycode == 1)
		pan_n_draw(fdf, 10, 'y');
	if (keycode == 2)
		pan_n_draw(fdf, 10, 'x');
	if (keycode == 126)
		rot_zoom_draw(fdf, 1, '+', 'x');
	if (keycode == 125)
		rot_zoom_draw(fdf, 1, '-', 'x');
	if (keycode == 124)
		rot_zoom_draw(fdf, 1, '+', 'z');
	if (keycode == 123)
		rot_zoom_draw(fdf, 1, '-', 'z');
	return (0);
}
