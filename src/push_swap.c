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

int *input_to(int argc, char **argv);

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        printf("please input value\n");
        return (0);
    }
    int *numlist = input_to(argc, argv);
    if (!numlist)
    {
        printf("null\n");
        return (0);
    }
    for (int i = 0; i < argc - 1; i++)
    {
        printf("%d: %d\n", i, numlist[i]);
    }
    free(numlist);
    return (0);
}
