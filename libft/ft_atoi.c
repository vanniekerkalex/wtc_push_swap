/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:09:54 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/31 13:21:03 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int sign;
	int sum;

	sign = 1;
	sum = 0;
	while (ft_isspace((char)(*str)))
		str++;
	if ((char)*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if ((char)*str == '+')
		str++;
	while (ft_isdigit((char)*str))
	{
		if (((sum * 10) + (*str - '0')) > 2147483647)
			return (0);
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	if (*str && !ft_isdigit((char)*str))
		return (0);
	return (sum * sign);
}
