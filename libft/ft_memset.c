/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macmac <macmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:59:55 by meandrad          #+#    #+#             */
/*   Updated: 2024/10/31 13:20:30 by macmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			i;

	tmp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp_s[i] = (unsigned char)c;
		i++;
	}
	return (tmp_s);
}
