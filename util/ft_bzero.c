/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenidar <bbenidar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:38:19 by bbenidar          #+#    #+#             */
/*   Updated: 2023/01/16 14:42:05 by bbenidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
		ft_memset(s, '\0', n);
}
