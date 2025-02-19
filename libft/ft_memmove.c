/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:39:36 by meandrad          #+#    #+#             */
/*   Updated: 2024/10/23 22:14:02 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp_dest;
	const unsigned char	*tmp_src;
	size_t				i;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (tmp_dest > tmp_src)
	{
		while (n--)
			tmp_dest[n] = tmp_src[n];
	}
	else
	{
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}
