/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tester.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:35:15 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/04 09:55:37 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_TESTER_H
# define LIBASM_TESTER_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "../libasm.h"

#define	BIG_SIZE 12000
//tester functions
void	strlen_tester(const char *s);
int		strcpy_tester(const char *s);
void	strcmp_tester(const char *s1, const char *s2);
void	write_tester(int fd, const char *s1);
void	read_tester(int fd, char *s1, const size_t len);
int		read_file_tester(char *s1, const size_t len);
int		strdup_tester(const char *s);
void	atoi_base_tester(char *string, char *base);
void	push_front_tester(t_list **ref_list, t_list **asm_list, char **data);
void	list_size_tester(t_list **ref_list);
void	list_sort_tester(t_list **ref_list, t_list **asm_list);
void	remove_if_tester(t_list **ref_list, t_list **asm_list, char *data);
//tester helper functions
void	li_compare(long int std, long int ft);
void	sign_compare(int std, int ft);
void	str_compare(const char *std, const char *ft);
//piscine reference functions
void	piscine_list_clear(t_list *begin_list, void (*free_fct)(void *));
void	piscine_free_data(void *data);
int		piscine_atoi_base(char *str, char *base);
t_list	*piscine_create_elem(void *data);
void	piscine_list_push_front(t_list **begin_list, void *data);
int		piscine_list_size(t_list *begin_list);
void	piscine_list_sort(t_list **begin_list, int (*cmp)());
void	piscine_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));


#endif
