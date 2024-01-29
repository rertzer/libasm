/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_list_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:53:25 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 15:56:17 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.h"

void	piscine_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next;

	while (begin_list)
	{
		next = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}

void	piscine_free_data(void *data)
{
	(void)data;
}

static void	piscine_list_data_swap(t_list *first, t_list *last)
{
	void	*tmp;
	tmp = first->data;
	first->data = last->data;
	last->data = tmp;
}

void	piscine_list_sort(t_list **begin_list, int (*cmp)())
{
	int	sorted;
	t_list	*elem;

	if (! *begin_list)
		return;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		elem = *begin_list;
		while (elem->next)
		{
			if (cmp(elem->data, elem->next->data) > 0)
			{
				piscine_list_data_swap(elem, elem->next);
				sorted = 0;
			}
			elem = elem->next;
		}
	}
}
