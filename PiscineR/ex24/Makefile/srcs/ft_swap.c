/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:23:53 by rbouquet          #+#    #+#             */
/*   Updated: 2024/05/17 12:25:31 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int	*ptr1;
	int	*ptr2;
	
	a = 15;
	b = 50;
	ptr1 = &a;
	ptr2 = &b;
	printf("a = %d et b = %d\n", a , b);
	ft_swap(ptr1, ptr2);
	printf("a = %d et b = %d", a , b);
}*/