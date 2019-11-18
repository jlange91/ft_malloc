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
# define TINY 128
# define SMALL 2048
 
typedef struct	s_aloc
{
	void 					*begin;
	void 					*end;

	struct s_aloc	*next;
}								t_aloc;

#endif
