/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macmac <macmac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:44:54 by meandrad          #+#    #+#             */
/*   Updated: 2024/10/31 13:22:16 by macmac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if ((nptr[i] == '+') && (nptr[i + 1] != '-'))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	result = result * sign;
	return (result);
}
