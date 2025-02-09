/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:25:28 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/09 18:48:18 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_pos(t_list *stack)
{
	t_list	*curr;
	int		max_idx;
	int		pos;
	int		i;

	curr = stack;
	max_idx = curr->index;
	pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->index > max_idx)
		{
			max_idx = curr->index;
			pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (pos);
}

static void	push_to_b(t_list **stack_a, t_list **stak_b)
{
	int	min;
	int	max;
	int	size;

	size = ft_lstsize(*stack_a);
	min = 0;
	max = 0.05 * size + 10;
	while (*stack_a)
	{
		if ((*stack_a)->index >= min && (*stack_a)->index <= max)
		{
			pb(stack_a, stak_b);
			min++;
			max++;
		}
		else if ((*stack_a)->index < min)
		{
			pb(stack_a, stak_b);
			rb(stak_b);
			min++;
			max++;
		}
		else
			ra(stack_a);
	}
}

static void	push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	size;

	while (*stack_b)
	{
		size = ft_lstsize(*stack_b) - 1;
		pos = get_max_pos(*stack_b);
		if ((*stack_b)->index == size)
			pa(stack_a, stack_b);
		else if (pos < size / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		push_to_b(stack_a, stack_b);
		push_back_to_a(stack_a, stack_b);
	}
}
