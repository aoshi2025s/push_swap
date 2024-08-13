/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:29:05 by yoaoki            #+#    #+#             */
/*   Updated: 2024/08/13 14:26:50 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	init_stacks(t_stacks *stack, size_t size)
{
	stack->size_a = size;
	stack->size_b = 0;
	stack->a = (int *)malloc(sizeof(int) * stack->size_a);
	stack->b = (int *)malloc(sizeof(int) * stack->size_a);
	if (!stack->a || !stack->b)
	{
		ft_printf("memory allocate error\n");
		exit(1);
	}
}

void	input_to_stack_a(t_stacks *stack, char **strings)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
	{
		if (!is_int32(strings[i + 1]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		stack->a[i] = ft_atoi(strings[i + 1]);
		i++;
	}
	if (is_duplicate(stack))
	{
		ft_printf("Error\n");
		exit(1);
		return ;
	}
}
