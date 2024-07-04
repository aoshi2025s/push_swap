/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoaoki <yoaoki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:52:30 by yoaoki            #+#    #+#             */
/*   Updated: 2024/06/02 03:59:11 by yoaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "ft_printf.h"
#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        ft_printf("please input value\n");
        return (0);
    }

    int size = argc;

    t_stack *st = create_new_stack(size);
    ft_printf("stack->size: %d\n", st->size);
    if (st) {
        ft_printf("stack created ok\n");
    }

    if (input_to_stack(size - 1, argv, st) == 0) {
        st_delete_all(st);
        ft_printf("Error\n");
        return (0);
    }

    ft_printf("stack input ok\n");
    st_display_all(st);
    st_delete_all(st);

    return (0);
}
