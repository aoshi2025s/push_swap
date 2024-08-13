/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:56:26 by yoaoki            #+#    #+#             */
/*   Updated: 2024/08/13 14:23:51 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_pb(t_stacks *stack)
{
	int	i;

	if (stack->size_a == 0)
	{
		ft_printf("pb command error\n");
		return ;
	}
	stack->size_b++;
	stack->size_a--;
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < stack->size_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	ft_printf("pb\n");
}

void	ft_pa(t_stacks *stack)
{
	int	i;

	if (stack->size_b == 0)
	{
		ft_printf("pa command error\n");
		return ;
	}
	stack->size_a++;
	stack->size_b--;
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < stack->size_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	ft_printf("pa\n");
}
