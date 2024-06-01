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

#include <stdlib.h> //for <atoi> ***need change function atoi to ft_atoi in libft***

#include <limits.h>
#include <ctype.h> //for <isspace, isdigit> ***need change function isspace to ft_isspace in libft***
/*
 * argc, argvを受け取る
 * 1. argvが数値かどうか
 * 2. 数値に変換した際にintの範囲を超えてないか
 * 3. 数値の重複がないか 2重ループでチェック
 *
 *
*/
// inputしていきたい。to_stackとしたいけど、一旦配列か何かに納めてprintf出力して目に見える形に。
// argc - １って書きたくないので、ゆくゆくはsizeとして与えたい

int is_integer(char *str);
int is_exist(int num, int *numbers, int end);

int	*input_to(int argc, char **argv)
{
	int *numbers;

	numbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (NULL == numbers)
		return (NULL);
	int i = 1;
	while (i < argc)
	{
		if(is_integer(argv[i]))
		{
			int n = atoi(argv[i]);
			if (is_exist(n, numbers, i - 1))
				return (NULL);
			numbers[i - 1] = n;
		}
		else
			return (NULL);
		i++;
	}
	return (numbers);
}

int is_integer(char *str)
{
	int sign;
	long long num;
	
	num = 0;
	sign = 1;
	if (!str)
		return (0);
	while (isspace(*str))
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
		if (0 == isdigit(*str))
			return (0);
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
		str++;	
	}
	return (1);
}

int is_exist(int num, int *numbers, int end)
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

