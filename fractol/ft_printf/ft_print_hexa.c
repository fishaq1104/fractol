/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:48:04 by fishaq            #+#    #+#             */
/*   Updated: 2023/09/15 19:59:02 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexasmall(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	ft_hexasmall((unsigned int)nb);
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

void	ft_hexasmall(unsigned int n)
{
	if (n >= 16)
	{
		ft_hexasmall(n / 16);
		ft_hexasmall(n % 16);
	}
	else
	{
		if (n < 10)
		{
			print_char(n % 10 + '0');
		}
		else
		{
			print_char(n - 10 + 'a');
		}
	}
}

void	ft_hexacap(unsigned int n)
{
	if (n >= 16)
	{
		ft_hexacap(n / 16);
		ft_hexacap(n % 16);
	}
	else
	{
		if (n < 10)
		{
			print_char(n % 10 + '0');
		}
		else
		{
			print_char(n - 10 + 'A');
		}
	}
}

int	print_hexacap(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	ft_hexacap((unsigned int)nb);
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}
