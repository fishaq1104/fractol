/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:52:06 by fishaq            #+#    #+#             */
/*   Updated: 2024/02/18 12:36:02 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// light pink: #FFD1DC
// blush: #DE5D83
// Rouge: #A94064
// Fushisia : #C152C1

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			colour;

	i = 0;
	// z.x = 0.0;
	// z.y = 0.0;
	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		// do it
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	// how many times you want to itrate
	// if hypo > 2 i assume the point has escaped
	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			colour = map(i, DEEPINK, BLACK, 0, fractal->iterations_defintion);
			my_pixel_put(x, y, &fractal->img, colour);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
	// we are in Mandelbrot
}
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
