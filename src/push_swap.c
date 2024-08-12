#include "push_swap.h"

void display_stacks(t_stacks *stack)
{
	printf("===========stack_a===========\n");
	for (int i = 0; i < stack->size_a - 1; i++) {
		printf("%d ", stack->a[i]);
	}
	printf("%d\n", stack->a[stack->size_a - 1]);

	printf("===========stack_b===========\n");
	for (int i = 0; i < stack->size_b - 1; i++) {
		printf("%d ", stack->b[i]);
	}
	printf("%d\n", stack->b[stack->size_b - 1]);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("please input value\n");
		return (1);
	}
	if (argc == 2)
	{
		// ft_split(argv[2]);
		return (0);
	}
	t_stacks *stack;

	stack = malloc(sizeof(t_stacks));
	if (!stack)
		return (1);
	init_stacks(stack, argc-1);
	input_to_stack_a(stack, argv);
	
	ft_rra(stack);	
	display_stacks(stack);

	ft_ra(stack);
	display_stacks(stack);

	ft_pb(stack);
	ft_pb(stack);
	ft_pb(stack);
	display_stacks(stack);

	ft_rrb(stack);
	display_stacks(stack);

	free(stack->a);
	free(stack->b);
	free(stack);
}
