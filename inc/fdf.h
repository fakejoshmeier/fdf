/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:57:24 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/27 18:39:52 by jmeier           ###   ########.fr       */
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
}				t_xyz;

void			error(char *str);
void			parse_suite(t_xyz *fdf, char *av);
void			validate(t_xyz *fdf, int fd);
void			cannibalize(t_xyz *fdf, int fd);

#endif
