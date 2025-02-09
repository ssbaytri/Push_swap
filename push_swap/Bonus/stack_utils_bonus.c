/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:37:45 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/06 18:54:45 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	assign_indexes(t_list *stack)
{
	t_list	*curr;
	t_list	*comp;
	int		idx;

	curr = stack;
	while (curr)
	{
		idx = 0;
		comp = stack;
		while (comp)
		{
			if (curr->content > comp->content)
				idx++;
			comp = comp->next;
		}
		curr->index = idx;
		curr = curr->next;
	}
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_list	*init_stack(int *nums, int size)
{
	t_list	*stack;
	t_list	*tmp;
	int		i;

	i = 0;
	stack = ft_lstnew(nums[i]);
	i++;
	while (i < size)
	{
		tmp = ft_lstnew(nums[i]);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	return (stack);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
