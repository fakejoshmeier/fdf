/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:54:50 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/31 10:55:11 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <ft_printf.h>
# include <fcntl.h>

typedef struct	s_xyz
{
	int			col;
	int			row;
	int			**bumps;
    int         **twist;
    int			prog;
    int         rot_y;
    int         rot_z;
    int         rot_x;
	int			color
}				t_xyz;

typedef struct	s_vis
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*canvas;
	int			size;
}				t_vis;

void			error(char *str);
void			parse_suite(t_xyz *fdf, char *av);
void			validate(t_xyz *fdf, int fd);
void			cannibalize(t_xyz *fdf, int fd);

#endif
