/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:51:39 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/03 11:37:30 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	list_size_tester(t_list **ref_list)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	int p = piscine_list_size(*ref_list);
	int f = ft_list_size(*ref_list);
	li_compare(p, f);
	char	load[] = "another data in the list";
	for (int i = 0; i < 666; i++)
	{
		piscine_list_push_front(ref_list, load);
	}
	p = piscine_list_size(*ref_list);
	f = ft_list_size(*ref_list);
	li_compare(p, f);
}
