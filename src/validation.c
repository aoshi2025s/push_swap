/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:40:43 by yoaoki            #+#    #+#             */
/*   Updated: 2024/08/13 13:32:52 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * 数字であるかどうかをチェック
 * intの範囲でオーバーフローしないかどうかチェック
 */
bool	is_int32(char *str)
{
	int	result;
	int	symbol;

	result = 0;
	symbol = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			symbol = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		if ((symbol * result > (INT_MAX - (*str - '0')) / 10) || symbol
			* result < (INT_MIN + (*str - '0')) / 10)
			return (false);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (true);
}

/*
 * 重複した数字がないかどうかをチェック
 */
bool	is_duplicate(t_stacks *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a - 1)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->a[i] == stack->a[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
