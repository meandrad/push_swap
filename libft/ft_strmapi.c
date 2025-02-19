/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macmac <macmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:05:50 by meandrad          #+#    #+#             */
/*   Updated: 2024/10/31 13:18:55 by macmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	str_len;
	char			*mapped_str;

	if (!s || !f)
		return (NULL);
	str_len = ft_strlen(s);
	mapped_str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!mapped_str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		mapped_str[i] = f(i, s[i]);
		i++;
	}
	mapped_str[i] = '\0';
	return (mapped_str);
}
