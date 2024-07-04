/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:00:33 by yoaoki            #+#    #+#             */
/*   Updated: 2024/07/05 07:00:44 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

t_stack *create_new_stack(int size) {
    t_stack *st = (t_stack *)malloc(sizeof(t_stack));
    if (st == NULL)
        return (NULL);
    st->data = (int *)malloc(sizeof(int) * size);
    st->head = 0;
    st->tail = 0;
    st->size = size;
    return (st);
}

int st_is_empty(t_stack *st) {
    return (st->head == st->tail);
}

int st_is_full(t_stack *st) {
    return (st->head == (st->tail + 1) % st->size);
}

void push_back(t_stack *st, int value) {
    if (st_is_full(st)) {
        printf("stack is full\n");
        return ;
    }
    st->data[st->tail % st->size] = value;
    st->tail = (st->tail + 1) % st->size;
}

int top(t_stack *st) {
    if (st_is_empty(st)) {
        printf("stack is null\n");
        return 0;
    }
    return (st->data[(st->tail - 1) % st->size]);
}

void pop(t_stack *st) {
    if (st_is_empty(st)) {
        printf("stack is null\n");
        return ;
    }
    st->tail = (st->tail - 1) % st->size;
}

// optional function
void st_delete_all(t_stack *st) {
    while (st_is_empty(st) == 0) {
        pop(st);
    }
    free(st->data);
    free(st);
}

void st_display_all(t_stack *st) {
    if (st_is_empty(st)) {
        printf("stack is empty\n");
        return;
    }
    size_t index = (st->tail - 1) % st->size;
    printf("top >>> ");
    while (index != st->head % st->size) {
        printf("|%d", st->data[index]);
        index = (index - 1) % st->size;
    }
    printf("|%d", st->data[index]);
    printf("| <<< bottom\n");
}

// TODO stackのテストを書く
