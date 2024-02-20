/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:15:01 by fishaq            #+#    #+#             */
/*   Updated: 2024/02/20 22:09:24 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_julia_parameters(t_fractal *fractal, char **av)
{
	if (av[2] == NULL || av[3] == NULL)
	{
		ft_putstr_fd("Please provide both Julia parameters.\n", STDERR_FILENO);
		return (0);
	}
	if (!is_valid_julia_parameter(av[2]) || !is_valid_julia_parameter(av[3]))
	{
		ft_putstr_fd("Invalid Julia parameters",
			STDERR_FILENO);
		return (0);
	}
	fractal->julia_x = atof(av[2]);
	fractal->julia_y = atof(av[3]);
	if (fractal->julia_x < -2 || fractal->julia_x > 2 || fractal->julia_y < -2
		|| fractal->julia_y > 2)
	{
		ft_putstr_fd("Julia parameters should be between -2 and 2.\n",
			STDERR_FILENO);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			if (!check_julia_parameters(&fractal, av))
			{
				exit(EXIT_FAILURE);
			}
			fractal.julia_x = atobbl(av[2]);
			fractal.julia_y = atobbl(av[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd("ERROR TRY AGAIN\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
}
