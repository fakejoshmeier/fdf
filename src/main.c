/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:55:21 by jmeier            #+#    #+#             */
/*   Updated: 2018/01/11 00:59:46 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	error(char *str)
{
	ft_putstr("Error: ")
	ft_putstr(str);
	exit(0);
}

int		main(int ac, char *av[])
{
	t_xyz	*fdf;
	int		fd;

	ac == 2 ? 0 : error("Usage ./fdf [TEST.fdf]\n");
	ft_strstr(av[1], ".fdf") ? 0 : error("Invalid filetype\n");
	fdf = ft_memalloc(sizeof(t_xyz *));
	parse_suite(fdf, av[1]);

	return (0);
}
