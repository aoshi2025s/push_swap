/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 22:49:15 by yoaoki            #+#    #+#             */
/*   Updated: 2024/06/02 03:58:54 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	input_to_stack(int size, char **strings, t_stack *st)
{
	int i = 0;
	while (i < size)
	{
		if(is_integer(strings[i + 1]))
		{
			int n = ft_atoi(strings[i + 1]);
			push_back(st, n);
		}
		else
			return (0);
		i++;
	}
	return (is_duplicate(st) == 0);
}
// maybe static add
int is_integer(char *str)
{
	int sign;
	long long num;
	
	num = 0;
	sign = 1;
	if (!str)
		return (0);
	while (ft_isspace(*str))
		str++;
	if ('+' == *str || '-' == *str)
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	if ('\0' == *str)
		return (0);
	while (*str)
	{
		if (0 == ft_isdigit(*str))
			return (0);
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
		str++;	
	}
	return (1);
}

int is_duplicate(t_stack *st) {
	int i;
	int j;

	i = 0;
	while (i < st->size - 1) {
		j = i + 1;
		while (j < st->size) {
			if (st->data[i] == st->data[j]) {
				ft_printf("st->data[%d] == st->data[%d]\n", i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}