/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:31:33 by jlange            #+#    #+#             */
/*   Updated: 2019/10/28 10:59:53 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include "../libft/includes/libft.h"
# include <pthread.h>

#include <stdio.h>

# include <sys/mman.h>
# define TINY 128
# define SMALL 2048
# define IS_TINY(x) (x <= TINY)
# define IS_SMALL(x) (x > TINY && x <= SMALL)
# define IS_LARGE(x) (x > SMALL)

typedef struct	s_alloc
{
	void 					*begin;
	size_t				size;
	struct s_alloc	*next;
}								t_alloc;

typedef struct	s_malloc_data
{
	int				pagesize;
	t_alloc		*mem;
}								t_malloc_data;

static pthread_mutex_t g_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;
t_malloc_data g_malloc_data;


void 		free(void *ptr);
void 		*malloc(size_t size);
void 		*realloc(void *ptr, size_t size);
void 		init_address(void);

#endif
