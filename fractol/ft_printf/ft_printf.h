/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:59:49 by fishaq            #+#    #+#             */
/*   Updated: 2023/09/22 15:47:54 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		print_char(int c);
int		print_str(const char *str);
int		print_number(int n);
int		size(int n);
int		ft_printf(const char *str, ...);
int		print_unsigned(unsigned int n);
int		len(unsigned int n);
int		print_hexasmall(unsigned int nb);
void	ft_hexasmall(unsigned int n);
int		print_hexacap(unsigned int n);
void	ft_hexacap(unsigned int n);
void	ft_pointer(unsigned long long int nb);
int		print_pointer(unsigned long long int n);

#endif