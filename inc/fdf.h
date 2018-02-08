/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:54:50 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/08 01:16:24 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <ft_printf.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_jig
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
	int				**bumps;
	t_jig			**twist;
	double			rot_y;
	double			rot_z;
	double			rot_x;
	double			scale;
	double			x_it;
	double			y_it;
}					t_xyz;

typedef struct		s_vis
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*canvas;
	int				bits;
	int				endian;
	int				s_line;
	int				color;
	int				size;
}					t_vis;

void			error(char *str);

void			parse_suite(t_xyz *fdf, char *av);
void			validate(t_xyz *fdf, int fd);
void			cannibalize(t_xyz *fdf, int fd);
void			twister(t_xyz *fdf);

void			rot_suite(t_xyz *fdf);
void			x_rot(t_xyz *fdf, double rad, int r, int c);
void			y_rot(t_xyz *fdf, double rad, int r, int c);
void			z_rot(t_xyz *fdf, double rad, int r, int c);

void			scale(t_xyz *fdf, t_vis *zen);
#endif
