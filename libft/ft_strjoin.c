/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macmac <macmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:11:15 by meandrad          #+#    #+#             */
/*   Updated: 2024/10/31 13:19:35 by macmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	concat = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	ft_memcpy(concat, s1, len1);
	ft_memcpy(concat + len1, s2, len2);
	concat[len1 + len2] = '\0';
	return (concat);
}
