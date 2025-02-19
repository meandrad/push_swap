/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macmac <macmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:13:12 by meandrad          #+#    #+#             */
/*   Updated: 2024/10/31 13:20:48 by macmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			i;

	tmp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == (unsigned char)c)
			return ((void *) &tmp_s[i]);
		i++;
	}
	return (NULL);
}
