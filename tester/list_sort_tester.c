/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:58:40 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 16:03:37 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	list_sort_tester(t_list **ref_list, t_list **asm_list)
{
	t_list	*ref_elem = *ref_list;
	t_list	*asm_elem = *asm_list;

	piscine_list_sort(ref_list, &strcmp);
	ft_list_sort(asm_list, &strcmp);
	
	while(ref_elem && asm_elem)
	{
		str_compare(ref_elem->data, asm_elem->data);
		ref_elem = ref_elem->next;
		asm_elem = asm_elem->next;
	}

}
