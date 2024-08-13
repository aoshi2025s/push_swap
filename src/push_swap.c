/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:36:34 by yoaoki            #+#    #+#             */
/*   Updated: 2024/08/13 13:36:37 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stacks(t_stacks *stack)
{
	printf("===========stack_a===========\n");
	for (int i = 0; i < stack->size_a - 1; i++)
	{
		printf("%d ", stack->a[i]);
	}
	printf("%d\n", stack->a[stack->size_a - 1]);
	printf("===========stack_b===========\n");
	for (int i = 0; i < stack->size_b - 1; i++)
	{
		printf("%d ", stack->b[i]);
	}
	printf("%d\n", stack->b[stack->size_b - 1]);
}

int	main(int argc, char **argv)
{
	t_stacks	*stack;

	if (argc < 2)
	{
		printf("Error\n");
		exit(1);
	}
	/* これがいるのかは不明
	if (argc == 2)
	{
		// ft_split(argv[2]);
		return (0);
	}
	*/
	stack = malloc(sizeof(t_stacks));
	if (!stack)
		exit(1);
	init_stacks(stack, argc - 1);
	input_to_stack_a(stack, argv);
	display_stacks(stack);
	free(stack->a);
	free(stack->b);
	free(stack);
}
