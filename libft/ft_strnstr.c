/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macmac <macmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:30:27 by meandrad          #+#    #+#             */
/*   Updated: 2024/10/31 13:18:46 by macmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j < len) && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
