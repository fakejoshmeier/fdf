/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:59:42 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/11 01:02:38 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	cannibalize(t_xyz *fdf, int fd)
{
	char	**tmp;
	char	*str;

	while (get_next_line(&str, fd))
	{
		
	}
}
void	validate(t_xyz *fdf, int fd)
{
	char	*str;

	while (get_next_line(&str, fd))
	{
		if (fdf->prog == 0)
		{
			fdf->width = ft_strlen(str);
			fdf->prog = 1;
		}
		else
		{
			fdf->width == ft_strlen(str) ? 0 : error("Invalid file\n");
			fdf->++prog;
		}
	}
	fdf->length = fdf->prog;
	fdf->prog = 0;
	close(fd);
}

void	parse_suite(t_xyz *fdf, char *av)
{
	int		fd;
	char	*str;

	(fd = read(av, O_RDONLY)) < 0 ? error("Unable to open file\n") : 0;
	validate(fdf, fd);
	fd = read(av, O_RDONLY);
	cannibalize(fdf, fd);
}
