/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:57:24 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/29 16:24:13 by jmeier           ###   ########.fr       */
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
	int			prog;
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
