/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:59:42 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/27 21:12:08 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	cannibalize(t_xyz *fdf, int fd)
{
	char	**tmp;
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (get_next_line(fd, &str))
	{
		tmp = ft_strsplit(str, ' ');
		while (++i < fdf->row)
		{
			fdf->bumps[i] = ft_memalloc(sizeof(int) * fdf->col);
			while (++j < fdf->col)
				fdf->bumps[i][j] = ft_atoi(tmp[j]);
			j = -1;
			break ;
		}
		free(tmp);
	}
	close(fd);
}

void	validate(t_xyz *fdf, int fd)
{
	char	*str;
	char	**grid;
	int		i;

	while (get_next_line(fd, &str))
	{
		i = -1;
		grid = ft_strsplit(str, ' ');
		while (grid[++i])
			;
		if (fdf->row == 0)
		{
			fdf->col = i;
			fdf->row = 1;
		}
		else
		{
			fdf->col == i ? 0 : error("Invalid file\n");
			++fdf->row;
		}
		free(grid);
	}
	fdf->bumps = ft_memalloc(sizeof(int *) * fdf->row);
	close(fd);
}

void	parse_suite(t_xyz *fdf, char *av)
{
	int		fd;

	(fd = open(av, O_RDONLY)) < 0 ? error("Unable to open file\n") : 0;
	validate(fdf, fd);
	fd = open(av, O_RDONLY);
	cannibalize(fdf, fd);
}