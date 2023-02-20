/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:18:51 by tlegrand          #+#    #+#             */
/*   Updated: 2023/02/20 12:39:12 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_GEN_H
# define MAP_GEN_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*	distribution of element in map	*/
# ifndef DISTRIBUTION
#  define DISTRIBUTION "E00000001CCCP"
# endif

int		ft_man(void);
void	ft_putstr_exit(char *strerr, int exit_code);
void	ft_check_arg(int n, char **arg);
int		ft_is_name_ber(char *pathname);

int		ft_atoi(const char *str);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putendl_fd(char *s, int fd);

#endif