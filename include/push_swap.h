/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:53:42 by yoaoki            #+#    #+#             */
/*   Updated: 2024/06/01 19:54:02 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// typedef struct
// {
//     int *data; // data = malloc(sizeof(int) * size); size = argc - 1
//     int top;
// } t_stack;

typedef struct s_stack {
    size_t head;
    size_t tail;
    int *data;
    size_t size;
} t_stack;

// input
int is_integer(char *str); // maybe static and delete from here
int is_exist_num(int num, int *numbers, int end); // maybe static and delet from here
int *input_to_stack(int size, char **strings);

// stack manipulate functions
t_stack *create_new_stack(int size);
int st_is_empty(t_stack *st);
int st_is_full(t_stack *st);
void push_back(t_stack *st, int value);
int top(t_stack *st);
void pop(t_stack *st);
void st_delete_all(t_stack *st);
void st_display_all(t_stack *st);

#endif
