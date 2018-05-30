/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 21:04:20 by xperrin           #+#    #+#             */
/*   Updated: 2018/05/30 20:47:03 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* This file isn't meant to be a part of my libft as it's just an unit test,
* don't break my balls about it, thanks.
*/

int run = 0;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "libft_test.h"

#define STR_TEST "42. I'd just like to interject for a moment. What you’re \
referring to as Linux, is in fact, GNU/Linux, or as I’ve recently taken \
to calling it, GNU plus Linux."

static	int cmp_int(const void *a, const void *b){
	int *_a = (int *)a;
	int *_b = (int *)b;

	if(*_a > *_b) return -1;
	if(*_a == *_b) return 0;
	return 1;
}

static	int		cmp_char(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);
}

static	int		cmp_str(const void* a, const void* b) {
	return(strcmp(*(char**)a, *(char**)b));
}

static	int		*init_randint_list(size_t len) {
	int		*list;
	size_t	i;


	list = ft_memalloc(sizeof(int) * len);
	for (i = 0; i < len; i++)
		list[i] = ft_rand(32);
	return(list);
}

static	int		*intdup(int *tab, size_t len) {
	int		*r;
	size_t	i;

	i = -1;
	if (!len || !(r = ft_memalloc(sizeof(int) * len)))
		return (NULL);
	while (++i < len)
		r[i] = tab[i];
	return(r);
}

static	int		test_numsort(void (*sort)(void *, size_t,  size_t,
					int (*)(const void *, const void *)))
{
	int		len = 10;
	int		*list1 = init_randint_list(len);
	int		*list2 = intdup(list1, len);
	int		i;
	int		error = 0;

	sort(list1, len, sizeof(int), cmp_int);
	qsort(list2, len, sizeof(int), cmp_int);
	for (i = 0 ; i < len; i++) {
		if (list1[i] != list2[i])
			error = 1;
	}
	if (error) {
		for (i = 0 ; i < len; i++)
			ft_printf("TESTED: %-10dOFFI:%d\n", list1[i], list2[i]);
	}
	return (error);
}

static	int		test_charsort(void (*sort)(void *, size_t,  size_t,
					int (*)(const void *, const void *))) {
	int		error = 0;
	char	str1[] = STR_TEST;
	char	*str2 = ft_strdup(str1);

	sort(str1, ft_strlen(str1), sizeof(char), cmp_char);
	qsort(str2, ft_strlen(str2), sizeof(char), cmp_char);
	if (ft_strcmp(str1, str2)) {
		ft_dprintf(2, "ERROR: sorted string mismatch:\n%s\n%s\n", str1, str2);
		error = 1;
	}
	free(str2);
	return (error);
}

static	char	**init_array(void) {
	char	**r;

	r = ft_memalloc(5 * sizeof(char*));
	r[0] = ft_strdup("Hello I'd just like to interject for a moment.f");
	r[1] = ft_strdup("Hello I'd just like to interject for a moment.4");
	r[2] = ft_strdup("Hello I'd just like to interject for a moment.2");
	r[3] = ft_strdup("Hello I'd just like to interject for a moment.a");
	r[4] = ft_strdup("Hello I'd just like to interject for a moment.b");
	return (r);
}

static	int		test_strsort(void (*sort)(void *, size_t,  size_t,
					int (*)(const void *, const void *))) {
	int		error = 0;
	int		i;
	char	**list1 = init_array();
	char	**list2 = init_array();

	sort(list1, 5, sizeof(char*), cmp_str);
	qsort(list2, 5, sizeof(char*), cmp_str);
	for (i = 0; i < 5; i++) {
		if (strcmp(list1[i], list2[i]))
			error = 1;
	}
	if (error) {
		for (i = 0 ; i < 5; i++)
			ft_printf("TESTED: %-50sOFFI:%s\n", list1[i], list2[i]);
	}
	return (error);
}

int				test_sort(void (*sort)(void *, size_t, size_t,
						int (*)(const void *, const void *))) {
	int error = 0;

	error += test_numsort(sort);
	error += test_charsort(sort);
	error += test_strsort(sort);
	if (error)
		ft_printf("%s: %d errors\n", __FILE__, error);
	return ((error) ? 1 : 0);
}
