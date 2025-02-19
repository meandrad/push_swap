/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macmac <macmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:56:35 by meandrad          #+#    #+#             */
/*   Updated: 2024/10/31 13:19:06 by macmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*store;

	store = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			store = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *) &s[i]);
	return (store);
}
