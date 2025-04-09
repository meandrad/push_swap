/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meandrad <meandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:18:03 by meandrad          #+#    #+#             */
/*   Updated: 2025/04/08 21:48:41 by meandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *s)
{
	long	result;
	int		i;
	int		flag;

	result = 0;
	flag = 1;
	i = 0;
	while (ft_isspace(s[i]) == 1)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			flag = -1;
		i++;
	}
	while (ft_isdigit(s[i]) == 1)
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * flag);
}
