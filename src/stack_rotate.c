/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:15:04 by yoaoki            #+#    #+#             */
/*   Updated: 2024/08/12 14:25:12 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ra(t_stacks *stack)
{
	int top_data;
	int i;

	if (stack->size_a < 2)
	{
		// TODO: error handle
		printf("error\n");
		return ;
	}
	top_data = stack->a[0];
	// stack->aの要素を全部左詰にする
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = top_data;
	printf("ra\n");
}

void ft_rb(t_stacks *stack)
{
	int top_data;
	int i;

	if (stack->size_b < 2)
	{
		// TODO: error handle
		printf("error\n");
		return ;
	}
	top_data = stack->b[0];
	// stack->bの要素を全部左詰にする
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = top_data;
	printf("rb\n");
}

void ft_rr(t_stacks *stack)
{
	// これやった時にさ、printf("ra\n") printf("rb\n")が出力されるのだるい
	ft_ra(stack);
	ft_rb(stack);
}
