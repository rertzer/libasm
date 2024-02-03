/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:58:40 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/03 11:36:33 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	list_sort_tester(t_list **ref_list, t_list **asm_list)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	t_list	*ref_elem = *ref_list;
	t_list	*asm_elem = *asm_list;
	printf("\033[0;36mbefore sort\033[0m\n");
	while(ref_elem && asm_elem)
	{
		str_compare(ref_elem->data, asm_elem->data);
		ref_elem = ref_elem->next;
		asm_elem = asm_elem->next;
	}
	
	piscine_list_sort(ref_list, &strcmp);
	ft_list_sort(asm_list, &strcmp);

	ref_elem = *ref_list;
	asm_elem = *asm_list;
	printf("\033[0;36mafter sort\033[0m\n");
	while (ref_elem)
	{
		str_compare(ref_elem->data, asm_elem->data);
		ref_elem = ref_elem->next;
		asm_elem = asm_elem->next;
	}

}
