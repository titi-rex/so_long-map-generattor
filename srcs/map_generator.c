/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:19:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/19 00:07:13 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map_gen.h"

void	ft_ensure_token(int fd, int *exit, int *player)
{
	if (!*exit)
	{
		write(fd, "E", 1);
		*exit = 1;
	}
	else if (*player != 2)
	{
		write(fd, "P", 1);
		*player = 2;
	}
	else
		write(fd, "C", 1);
}

void	ft_random_write(int fd, int wit)
{
	unsigned char	buff;
	char			*token;
	int				fdrand;
	static int		exit;
	static int		player;

	if (wit)
		return ((void) ft_ensure_token(fd, &exit, &player));
	token = DISTRIBUTION;
	fdrand = open("/dev/urandom", O_RDONLY);
	if (fdrand == -1)
		ft_putstr_exit("Error\nCan't get random", EXIT_FAILURE);
	read(fdrand, &buff, 1);
	close(fdrand);
	write(fd, &token[buff % (sizeof(DISTRIBUTION) - 1 - player) + exit], 1);
	if (token[buff % (sizeof(DISTRIBUTION) - 1 - player) + exit] == 'E')
	{
		exit = 1;
		if (!player)
			player = 1;
	}
	if (token[buff % (sizeof(DISTRIBUTION) - 1 - player) + exit] == 'P')
		player = 2;
}

void	ft_generate(int fd, int ysize, int xsize)
{
	int	y;

	y = 0;
	while (y < ysize * xsize)
	{
		if (y < xsize || y >= (ysize * xsize) - xsize)
			write(fd, "1", 1);
		else if (y % xsize == 0 || y % xsize == xsize - 1)
			write(fd, "1", 1);
		else if (y > (ysize * xsize) - xsize - 9)
			ft_random_write(fd, 1);
		else
			ft_random_write(fd, 0);
		if (y % xsize == xsize - 1)
			write(fd, "\n", 1);
		y++;
	}
}

void	ft_create_map(char *pathname, int ysize, int xsize)
{
	int		fd;
	char	*buff;

	if (xsize == 0)
		xsize = ysize;
	if (ft_is_name_ber(pathname))
	{
		buff = ft_strjoin(pathname, ".ber");
		if (!buff)
			ft_putstr_exit("Error\nMalloc fail", EXIT_FAILURE);
		fd = open(buff, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		free(buff);
	}
	else
		fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ft_putstr_exit("Error\nCan't open file", EXIT_FAILURE);
	ft_generate(fd, ysize, xsize);
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc != 3 && argc != 4)
		return (ft_man());
	ft_check_arg(argc, argv);
	if (argc == 3)
		ft_create_map(argv[1], ft_atoi(argv[2]), 0);
	else
		ft_create_map(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
	return (0);
}
