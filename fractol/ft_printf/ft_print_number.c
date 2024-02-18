/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:44:48 by fishaq            #+#    #+#             */
/*   Updated: 2023/09/17 17:08:02 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	print_number(int n)
{
	int	count;

	count = size(n);
	if (n == -2147483648)
	{
		print_char('-');
		print_char('2');
		print_number(147483648);
	}
	else if (n < 0)
	{
		print_char('-');
		n *= -1;
		print_number(n);
	}
	else if (n >= 10)
	{
		print_number(n / 10);
		print_number(n % 10);
	}
	else
	{
		print_char(n + '0');
	}
	return (count);
}

int	len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	print_unsigned(unsigned int n)
{
	int	count;

	count = len(n);
	if (n >= 10)
	{
		print_number(n / 10);
		print_number(n % 10);
	}
	else
	{
		print_char(n + '0');
	}
	return (count);
}
