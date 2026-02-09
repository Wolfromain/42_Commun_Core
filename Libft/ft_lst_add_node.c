/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:47:09 by rbouquet          #+#    #+#             */
/*   Updated: 2024/07/02 15:48:14 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_node(t_stack_node **lst, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (lst == NULL)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return ;
	new_node -> next = NULL;
	new_node -> nbr = n;
	if (!(*lst))
	{
		*lst = new_node;
		new_node -> prev = NULL;
	}
	else
	{
		last_node = ft_lstlast(*lst);
		last_node -> next = new_node;
		new_node -> prev = last_node;
	}
}