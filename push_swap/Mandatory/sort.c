/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:21:02 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/05 21:49:40 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_list *stack)
{
	t_list	*curr;
	int		min_idx;
	int		min_pos;
	int		i;

	curr = stack;
	min_idx = curr->index;
	min_pos = 0;
	i = 0;
	while (curr && ++i)
	{
		if (curr->index < min_idx)
		{
			min_idx = curr->index;
			min_pos = i - 1;
		}
		curr = curr->next;
	}
	return (min_pos);
}

static void	push_small_to_b(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	size;

	min_pos = find_min_pos(*stack_a);
	size = ft_lstsize(*stack_a);
	if (min_pos <= size / 2)
		while (min_pos--)
			ra(stack_a);
	else
		while (min_pos++ < size)
			rra(stack_a);
	pb(stack_a, stack_b);
}

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	push_small_to_b(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	push_small_to_b(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
