/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piscine_list_remove_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rertzer <rertzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:50:59 by rertzer           #+#    #+#             */
/*   Updated: 2024/01/29 12:02:48 by rertzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_tester.c"

static t_list	*piscine_list_prev(t_list *lst, t_list *target)
{
	while (lst)
	{
		if (lst->next == target)
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}

static t_list	*piscine_list_remove(t_list **begin_list, t_list *elem, void (*free_fct)(void *))
{
	t_list	*tmp;

	if (*begin_list == elem)
	{
		*begin_list = elem->next;
		tmp = elem->next;
	}
	else
	{
		tmp = piscine_list_prev(*begin_list, elem);
		tmp->next = elem->next;
		tmp = elem->next;
	}
	free_fct(elem->data);
	free(elem);
	return (tmp);
}
	

static void	piscine_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;

	current = *begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
			current = piscine_list_remove(begin_list, current, free_fct);
		else
			current = current->next;
	}
}
