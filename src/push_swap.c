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

int *input_to_stack(int size, char **strings);

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        ft_printf("please input value\n");
        return (0);
    }
    /*
    int *numlist = input_to_stack(argc - 1, argv);
    if (!numlist)
    {
        ft_printf("Error\n");
        return (0);
    }
    for (int i = 0; i < argc - 1; i++)
    {
        ft_printf("%d: %d\n", i, numlist[i]);
    }
    */

    t_stack *st = create_new_stack(argc - 1);
    if (st) {
        ft_printf("stack created ok\n");
    }
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        push_back(st, value);
    }
    st_display_all(st);
    st_delete_all(st);
    return (0);
}
