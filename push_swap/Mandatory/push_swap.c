/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:04:18 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/06 18:01:56 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_input(int *nums, int ac, int size)
{
	if (ac < 2 || size == 1)
	{
		free(nums);
		return (0);
	}
	if (!nums)
	{
		write(2, "Error\n", 6);
		free(nums);
		return (0);
	}
	return (1);
}

static int	handle_sorted_stack(t_list *stack_a, int *nums)
{
	if (is_sorted(stack_a))
	{
		free(nums);
		free_stack(stack_a);
		return (1);
	}
	return (0);
}

static void	push_swap(t_list **stack_a, t_list **stack_b, int *nums)
{
	assign_indexes(*stack_a);
	sort_stack(stack_a, stack_b);
	free_stack(*stack_a);
	free_stack(*stack_b);
	free(nums);
}

int	main(int ac, char **av)
{
	int		*nums;
	int		size;
	t_list	*stack_a;
	t_list	*stack_b;

	size = 0;
	nums = parce_nums(ac, av, &size);
	if (!validate_input(nums, ac, size))
		return (1);
	stack_a = init_stack(nums, size);
	stack_b = NULL;
	if (!stack_a || handle_sorted_stack(stack_a, nums))
		return (1);
	push_swap(&stack_a, &stack_b, nums);
	return (0);
}
