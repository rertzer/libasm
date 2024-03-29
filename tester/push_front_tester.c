/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:59:48 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/03 11:34:33 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	push_front_tester(t_list **ref_list, t_list **asm_list, char **data)
{

	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	errno = 0;
	for (int i = 0; i < 5; i++)
	{
		piscine_list_push_front(ref_list, data[i]);
		ft_list_push_front(asm_list, data[i]);
	}
	
	printf("errno value: %d\n", errno);

	t_list	*ref_elem = *ref_list;
	t_list	*asm_elem = *asm_list;
	
	while (ref_elem && asm_elem)
	{
		str_compare(ref_elem->data, asm_elem->data);
		ref_elem = ref_elem->next;
		asm_elem = asm_elem->next;
	}
}
