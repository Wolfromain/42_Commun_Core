/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:21:12 by rbouquet          #+#    #+#             */
/*   Updated: 2024/09/23 10:42:05 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_stack
{
	long			value;
	int				index;
	int				push_cost;
	struct s_stack	*next;
	struct s_stack	*target_node;
}				t_stack;

//CHECK_ERROR
int				check_duplicate(t_stack *stack, int nbr);
void			free_argv(char **argv);
void			free_error(t_stack **stack, char **argv, int arg_2);
void			free_stack(t_stack *stack);
int				syntaxe_error(char *nbr);

//FT_SPLIT
int				count_words(char *str, char separator);
static char		*get_next_word(char *str, char separator);
char			**ft_split(char *str, char separator);

//INIT_SORT
void			target_best_node(t_stack *stack_a, t_stack *stack_b);
void			set_cost(t_stack *stack_a, t_stack *stack_b);
void			set_index(t_stack *stack);
void			init_node(t_stack *a, t_stack *b);

//INIT_STACK_A
long			ft_atol(char *str);
void			init_stack_a(t_stack **stack_a, char **argv, int argc);

//LITTLE_SORT
int				is_sorted(t_stack *stack);
void			little_sort(t_stack **stack_a);

//PUSH_SWAP
void			rotation(t_stack **a,
					t_stack **b, t_stack *smallest_node, int reverse);
void			stop_rotation(t_stack **stack,
					t_stack *smallest_node, char name);
static void		sort(t_stack **a, t_stack **b);
void			push_swap(t_stack **a, t_stack **b);

//PUSH
static void		push(t_stack **src, t_stack **dest);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);

//REVERSE_ROTATE
static void		reverse_rotate(t_stack **stack);
void			rra(t_stack **stack_a);
void			rrb(t_stack **stack_b);
void			rrr(t_stack **stack_a, t_stack **stack_b);

//ROTATE
static void		rotate(t_stack **stack);
void			ra(t_stack **stack_a);
void			rb(t_stack **stack_b);
void			rr(t_stack **stack_a, t_stack **stack_b);

//STACK_UTILS
int				stack_len(t_stack *stack);
t_stack			*stack_min(t_stack *stack);
t_stack			*stack_max(t_stack *stack);
t_stack			*stack_last(t_stack *stack);
void			stack_add_node(t_stack **stack, int n);

//STACK_UTILS2
t_stack			*before_last_node(t_stack *stack);
void			stack_five(t_stack **a, t_stack **b);
t_stack			*find_lowest_cost(t_stack *stack);

//SWAP
static void		ft_swap(t_stack *stack);
void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);
void			ss(t_stack **stack_a, t_stack **stack_b);

#endif