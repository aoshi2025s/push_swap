/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:21:24 by yoaoki            #+#    #+#             */
/*   Updated: 2024/08/13 14:25:41 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_rra(t_stacks *stack)
{
	int	bottom_data;
	int	i;

	if (stack->size_a < 2)
	{
		ft_printf("rra command error\n");
		return ;
	}
	bottom_data = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = bottom_data;
	ft_printf("rra\n");
}

void	ft_rrb(t_stacks *stack)
{
	int	bottom_data;
	int	i;

	if (stack->size_b < 2)
	{
		ft_printf("rrb command error\n");
		return ;
	}
	bottom_data = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = bottom_data;
	ft_printf("rrb\n");
}

void	ft_rrr(t_stacks *stack)
{
	ft_rra(stack);
	ft_rrb(stack);
}
