/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_if_tester.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:57:26 by rertzer           #+#    #+#             */
/*   Updated: 2024/02/03 12:38:53 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	remove_if_tester(t_list **ref_list, t_list **asm_list, char *data)
{
	printf("\033[0;35m       ---------------------------------------------\033[0m\n");
	printf("\033[0;36mtesting ft_list_remove_if, removing %s\033[0m\n", data);
	printf("\033[0;36mbefore\033[0m\n");

	t_list	*ref_elem = *ref_list;
	t_list	*asm_elem = *asm_list;

	while (ref_elem && asm_elem)
	{
		str_compare(ref_elem->data, asm_elem->data);
		ref_elem = ref_elem->next;
		asm_elem = asm_elem->next;
	}

	piscine_list_remove_if(ref_list, data, &strcmp, &piscine_free_data);
	ft_list_remove_if(asm_list, data, &strcmp, &piscine_free_data);


	printf("\033[0;36mafter\033[0m\n");

	ref_elem = *ref_list;
	asm_elem = *asm_list;

	while (ref_elem || asm_elem)
	{
		str_compare(ref_elem->data, asm_elem->data);
		ref_elem = ref_elem->next;
		asm_elem = asm_elem->next;
	}
}
