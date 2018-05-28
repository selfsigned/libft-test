/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 01:10:20 by xperrin           #+#    #+#             */
/*   Updated: 2018/05/28 02:17:11 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <stdlib.h>

#define M_GREEN "\033[1;32m"
#define M_YELLOW "\033[1;33m"
#define M_RED "\033[1;31m"
#define M_END "\033[0m"

/*
* This file isn't meant to be a part of my libft as it's just an unit test,
* don't break my balls about it, thanks.
*/

int		main(void) {
	int errors = 0;

	ft_printf("%s[TEST]%sSelf test\n", M_YELLOW, M_END);
	errors += test_sort(qsort);
	ft_printf("%s[TEST]%sTesting ft_bubblesort\n", M_YELLOW, M_END);
	errors += test_sort(ft_bubblesort);
	if (errors) {
		ft_printf("%s%d errors in total.%s\n", M_RED, errors, M_END);
		return 1;
	}
	ft_printf("%sNo errors found%s\n", M_GREEN, M_END);
}
