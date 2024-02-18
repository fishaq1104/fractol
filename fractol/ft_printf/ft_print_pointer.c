/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:48:00 by fishaq            #+#    #+#             */
/*   Updated: 2023/09/15 19:59:33 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long long int n)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	ft_pointer((unsigned long long int)n);
	if (n == 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_pointer(unsigned long long int nb)
{
	if (nb >= 16)
	{
		ft_pointer(nb / 16);
		ft_pointer(nb % 16);
	}
	else
	{
		if (nb < 10)
		{
			print_char(nb + '0');
		}
		else
		{
			print_char((nb - 10) + 'a');
		}
	}
}
