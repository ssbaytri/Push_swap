/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:21:37 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/06 21:43:13 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	valid_instruction(char *instruction)
{
	return (ft_strncmp(instruction, "sa\n", 3) == 0 || ft_strncmp(instruction,
			"sb\n", 3) == 0 || ft_strncmp(instruction, "ss\n", 3) == 0
		|| ft_strncmp(instruction, "pa\n", 3) == 0 || ft_strncmp(instruction,
			"pb\n", 3) == 0 || ft_strncmp(instruction, "ra\n", 3) == 0
		|| ft_strncmp(instruction, "rb\n", 3) == 0 || ft_strncmp(instruction,
			"rr\n", 3) == 0 || ft_strncmp(instruction, "rra\n", 4) == 0
		|| ft_strncmp(instruction, "rrb\n", 4) == 0 || ft_strncmp(instruction,
			"rrr\n", 4) == 0);
}

void	apply_instructions(char *instruction, t_list **stack_a,
		t_list **stack_b)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(instruction, "rra\n", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(instruction, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(instruction, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
}

void	check_sorted(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
