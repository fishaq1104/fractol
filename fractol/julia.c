/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:59:58 by fishaq            #+#    #+#             */
/*   Updated: 2024/02/20 22:13:07 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <ctype.h>
#include <string.h>

int	is_valid_julia_parameter(const char *param)
{
	int	decimal_point_count;
	int	length;
	int	valid;
	int	i;

	decimal_point_count = 0;
	length = (int)strlen(param);
	valid = 1;
	i = 0;
	while (i < length)
	{
		if (param[i] == '.')
		{
			decimal_point_count++;
		}
		else if (!isdigit(param[i]) && (param[i] != '-' || i != 0))
		{
			valid = 0;
			break ;
		}
		i++;
	}
	if (decimal_point_count > 1)
		valid = 0;
	return (valid);
}
