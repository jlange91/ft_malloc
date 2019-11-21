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

typedef struct	s_aloc
{
	void 					*begin;
	void 					*end;

	struct s_aloc	*next;
}								t_aloc;

static pthread_mutex_t g_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

void  *malloc(size_t size);
// void free(void *ptr);
// void *realloc(void *ptr, size_t size);

#endif
