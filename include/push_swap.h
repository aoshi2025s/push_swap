/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:23:32 by yoaoki            #+#    #+#             */
/*   Updated: 2024/08/12 13:41:58 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stacks {
	int *a;
	int *b;
	int size_a;
	int size_b;
} t_stacks;

// for stack_utils
void init_stacks(t_stacks *stack, size_t size);
void input_to_stack_a(t_stacks *stack, char **strings);

void display_stacks(t_stacks *stack);

// for stack manipulate
void ft_sa(t_stacks *stack);
void ft_sb(t_stacks *stack);
void ft_ss(t_stacks *stack);

void ft_pb(t_stacks *stack);
void ft_pa(t_stacks *stack);

void ft_ra(t_stacks *stack);
void ft_rb(t_stacks *stack);
void ft_rr(t_stacks *stack);

void ft_rra(t_stacks *stack);
void ft_rrb(t_stacks *stack);
void ft_rrr(t_stacks *stack);

#endif
