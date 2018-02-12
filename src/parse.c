/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:59:42 by jmeier            #+#    #+#             */
/*   Updated: 2018/02/11 16:55:37 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		garbage_check(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_isalpha(str[i]))
			return (1);
	}
	return (0);
}

void	dimension_the_dice(t_jig *twist, int r, int c, char *tmp)
{
	char	**s;

	twist->x = r;
	twist->y = c;
	if (ft_strchr(tmp, ','))
	{
		s = ft_strsplit(tmp, ',');
		garbage_check(s[0]) == 0 ? 0 : error("Invalid characters\n");
		twist->z = ft_atoi(s[0]);
		twist->iro = ft_atoi_base(s[1], 16);
		free_array(s);
		twist->crossz = twist->z;
	}
	else
	{
		garbage_check(tmp) == 0 ? 0 : error("Invalid characters\n");
		twist->z = ft_atoi(tmp);
		if (twist->z == 0)
			twist->iro = 0xFFFFFF;
		else
			twist->iro = twist->z > 0 ? 0x66023c : 0x02662c;
		twist->crossz = twist->z;
	}
}

void	cannibalize(t_xyz *fdf, int fd)
{
	char	**tmp;
	char	*str;
	int		i;
	int		j;

	i = -1;
	while (get_next_line(fd, &str))
	{
		tmp = ft_strsplit(str, ' ');
		free(str);
		while (++i < fdf->row)
		{
			j = -1;
			fdf->twist[i] = ft_memalloc(sizeof(t_jig) * fdf->col);
			while (++j < fdf->col)
				dimension_the_dice(&fdf->twist[i][j], i, j, tmp[j]);
			free_array(tmp);
			break ;
		}
	}
	close(fd);
}

void	validate(t_xyz *fdf, int fd)
{
	char	*str;
	int		i;
	int		k;

	while (get_next_line(fd, &str))
	{
		i = -1;
		k = 0;
		while (str[++i])
			if (ft_isspace(str[i]))
				++k;
		if (fdf->row == 0)
		{
			fdf->col = k;
			fdf->row = 1;
		}
		else
		{
			fdf->col == k ? 0 : error("Invalid file\n");
			++fdf->row;
		}
		free(str);
	}
	fdf->twist = ft_memalloc(sizeof(t_jig *) * fdf->row);
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
