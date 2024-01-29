/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:39:13 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 11:03:51 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include <stdlib.h>
#include <errno.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

//libasm functions
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char * s2);
ssize_t	ft_write(int fd, const char *buf, size_t count);
ssize_t	ft_read(int fd, const void *buf, size_t count);
char	*ft_strdup(const char *src);
//bonus functions
int		ft_atoi_base(char *str, char *base);

#endif
