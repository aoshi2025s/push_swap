/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:41:30 by yoaoki            #+#    #+#             */
/*   Updated: 2024/08/13 13:26:46 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *stack)
{
	int	temp;

	if (stack->size_a < 2)
	{
		printf("sa command error\n");
		return ;
	}
	temp = stack->a[1];
	stack->a[1] = stack->a[0];
	stack->a[0] = temp;
	printf("sa\n");
}

void	ft_sb(t_stacks *stack)
{
	int	temp;

	if (stack->size_b < 2)
	{
		printf("sb command error\n");
		return ;
	}
	temp = stack->b[1];
	stack->b[1] = stack->b[0];
	stack->b[0] = temp;
	printf("sb\n");
}

void	ft_ss(t_stacks *stack)
{
	ft_sa(stack);
	ft_sb(stack);
}
