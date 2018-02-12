/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:54:50 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/11 18:15:53 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <ft_printf.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct		s_jig
{
	unsigned int	iro;
	double			x;
	double			y;
	double			z;
	double			crossz;
}					t_jig;

typedef struct		s_xyz
{
	int				col;
	int				row;
	t_jig			**twist;
	double			rot_y;
	double			rot_z;
	double			rot_x;
	double			scale;
	double			x_it;
	double			y_it;
	void			*mlx;
	void			*win;
	void			*img;
	int				*canvas;
	int				bits;
	int				endian;
	int				s_line;
	int				color;
	int				size;
}					t_xyz;

typedef struct		s_bres
{
	t_jig			a;
	t_jig			b;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				i;
	int				w;
	int				h;
	double			dx1;
	double			dx2;
	double			dy1;
	double			dy2;
	int				shortest;
	int				longest;
	int				numerator;
}					t_bres;

void				error(char *str);
void				first_things_first(t_xyz *fdf);

void				parse_suite(t_xyz *fdf, char *av);
void				validate(t_xyz *fdf, int fd);
void				cannibalize(t_xyz *fdf, int fd);
void				dimension_the_dice(t_jig *twist, int r, int c, char *tmp);
int					garbage_check(char *str);

void				rot_suite(t_xyz *fdf);
void				x_rot(t_xyz *fdf, double rad, int r, int c);
void				y_rot(t_xyz *fdf, double rad, int r, int c);
void				z_rot(t_xyz *fdf, double rad, int r, int c);

void				zoom(t_xyz *fdf);
void				pan(t_xyz *fdf, double iter, char check);

void				colorize(t_xyz *fdf, t_bres breezy, int r, int c);
void				draw(t_xyz *fdf, int r, int c, char check);
void				intake(t_xyz *fdf);
void				first_draw(t_xyz *fdf);

int					zoom_hook(int keycode, t_xyz *fdf);

void				rot_zoom_draw(t_xyz *fdf, int iter, char check1, char
		check2);
void				pan_n_draw(t_xyz *fdf, int iter, char check);
void				zoom_in_n_out(t_xyz *fdf, double iter, char check);

void				free_array(char **array);
t_bres				bresenham(t_jig a, t_jig b);
void				fillin(t_bres *ret);
unsigned int		blend(unsigned int c1, unsigned int c2);
#endif
