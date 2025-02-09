/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:04:18 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/06 21:43:28 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static void	handle_errors(t_list *stack_a, t_list *stack_b, int *nums,
		char *line)
{
	write(2, "Error\n", 6);
	free(nums);
	free(line);
	free_stack(stack_a);
	free_stack(stack_b);
}

static int	process_instructions(t_list **stack_a, t_list **stack_b, int *nums)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!valid_instruction(line))
		{
			handle_errors(*stack_a, *stack_b, nums, line);
			return (0);
		}
		apply_instructions(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

static void	push_swap(t_list **stack_a, t_list **stack_b, int *nums)
{
	if (!process_instructions(stack_a, stack_b, nums))
		return ;
	check_sorted(*stack_a, *stack_b);
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
	assign_indexes(stack_a);
	push_swap(&stack_a, &stack_b, nums);
	return (0);
}
