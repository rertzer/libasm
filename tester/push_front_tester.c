/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front_tester.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:59:48 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 14:25:15 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	push_front_tester(t_list **ref_list, t_list **asm_list)
{
	char	lollipop_1[] = "Sweeter than candy on a stick";
	char	lollipop_2[] = "Huckleberry, cherry or lime";
	char	lollipop_3[] = "If you had a choice he'be your pick";
	char	lollipop_4[] = "But lollipop is mine";
	char	lollipop_5[] = "Lollipop, lollipop";

	errno = 0;
	piscine_list_push_front(ref_list, lollipop_1);
	ft_list_push_front(asm_list, lollipop_1);
	piscine_list_push_front(ref_list, lollipop_2);
	ft_list_push_front(asm_list, lollipop_2);
	piscine_list_push_front(ref_list, lollipop_3);
	ft_list_push_front(asm_list, lollipop_3);
	piscine_list_push_front(ref_list, lollipop_4);
	ft_list_push_front(asm_list, lollipop_4);
	piscine_list_push_front(ref_list, lollipop_5);
	ft_list_push_front(asm_list, lollipop_5);

	printf("errno value: %d\n", errno);

	t_list	*ref_elem = *ref_list;
	t_list	*asm_elem = *asm_list;
	
	while(ref_elem && asm_elem)
	{
		str_compare(ref_elem->data, asm_elem->data);
		ref_elem = ref_elem->next;
		asm_elem = asm_elem->next;
	}
}
