/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 01:10:20 by xperrin           #+#    #+#             */
/*   Updated: 2018/05/28 02:59:02 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"
#include <stdlib.h>

/*
* This file isn't meant to be a part of my libft as it's just an unit test,
* don't break my balls about it, thanks.
*/

int		main(void) {
	int errors = 0;

	ft_printf("%s[LIBFT-TEST]%s[TEST]%sSelf test\n",M_GREEN, M_YELLOW, M_END);
	errors += test_sort(qsort);
	ft_printf("%s[LIBFT-TEST]%s[TEST]%sft_bubblesort\n",
			M_GREEN, M_YELLOW, M_END);
	errors += test_sort(ft_bubblesort);
	if (errors) {
		ft_printf("%s[LIBFT-TEST]%s%d errors in total.%s\n",
				M_GREEN, M_RED, errors, M_END);
		return 1;
	}
	ft_printf("%s[LIBFT-TEST]No errors found%s\n", M_GREEN, M_END);
}
