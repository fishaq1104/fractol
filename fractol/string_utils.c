/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:00:56 by fishaq            #+#    #+#             */
/*   Updated: 2024/02/20 19:29:09 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s2_s;
	unsigned char	*s1_s;

	s2_s = (unsigned char *)s2;
	s1_s = (unsigned char *)s1;
	if (n == 0)
		return (0);
	i = 0;
	while (s1_s[i] == s2_s[i] && s1_s[i] != '\0')
	{
		i++;
	}
	return (s1_s[i] - s2_s[i]);
}

double	atobbl(char *s)
{
	long	int_pt;
	double	fract_pt;
	double	pow;
	int		sign;

	int_pt = 0;
	fract_pt = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		int_pt = (int_pt * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fract_pt = fract_pt + (*s++ - 48) * pow;
	}
	return ((int_pt + fract_pt) * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
