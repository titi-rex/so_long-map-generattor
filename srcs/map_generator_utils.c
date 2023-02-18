/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:45:31 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/18 23:27:03 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map_gen.h"

void	ft_putstr_exit(char *strerr, int exit_code)
{
	if (strerr)
		ft_putendl_fd(strerr, 2);
	exit(exit_code);
}

int	ft_man(void)
{
	ft_putendl_fd("Map generator need two or three argument : ", 1);
	ft_putendl_fd("Argument are : map's name, height and width", 1);
	ft_putendl_fd("You can give only height for a square map", 1);
	ft_putendl_fd("Size argument shall be less than INT_MAX and ", 1);
	ft_putendl_fd("height > 2, widht  > 4 (or opposite) ", 1);
	ft_putendl_fd("and >3 for square", 1);
	return (1);
}

void	ft_check_arg(int n, char **arg)
{
	if (n == 4)
	{
		if (ft_atoi(arg[3]) > 2 && ft_atoi(arg[2]) > 4)
			return ;
		if (ft_atoi(arg[3]) > 4 && ft_atoi(arg[2]) > 2)
			return ;
		if (ft_atoi(arg[3]) > 3 && ft_atoi(arg[2]) > 3)
			return ;
	}
	if (ft_atoi(arg[2]) > 3)
		return ;
	ft_putendl_fd("Argument shall be between (3&5) or 4 and INT_MAX", 1);
	exit(1);
}

int	ft_is_name_ber(char *pathname)
{
	int	i;

	i = 0;
	while (pathname[i])
	{
		if (!ft_strncmp(&pathname[i], ".ber", 5))
			return (0);
		i++;
	}
	return (1);
}
