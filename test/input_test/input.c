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

int is_integer(char *str);
int is_exist_num(int num, int *numbers, int end);

int	*input_to_stack(int size, char **strings)
{
	int *numbers;

	numbers = (int *)malloc(sizeof(int) * (size));
	if (NULL == numbers)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		if(is_integer(strings[i + 1]))
		{
			int n = ft_atoi(strings[i + 1]);
			if (is_exist_num(n, numbers, i))
				return (NULL);
			numbers[i] = n;
		}
		else
			return (NULL);
		i++;
	}
	return (numbers);
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

// maybe static add
int is_exist_num(int num, int *numbers, int end)
{
	int start;

	start = 0;
	while (start < end)
	{
		if (numbers[start] == num)
			return (1);
		start++;
	}
	return (0);
}