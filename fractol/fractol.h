/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:14:55 by fishaq            #+#    #+#             */
/*   Updated: 2024/02/18 12:44:43 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include<X11/X.h>
// #include<X11/keysm.h>
# include "./mlx/mlx.h"
// #include"ft_printf/ft_printf.h"

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
// #define RED       0xFF0000
// #define GREEN     0x00FF00
// #define BLUE      0x0000FF

// #define MAGENTA  0xFF00FF  // Magenta
// #define YELLOW  0xFFFF00  // Yellow
// #define CYAN  0x00FFFF  // Cyan
// #define ORANGE  0xFFA500  // Orange
// #define PURPLE  0x800080  // Purple
# define DEEPINK 0xFF1493 // DeepPink

typedef struct s_img
{
	void *img_ptr;    // pointer to image struct
	char *pixels_ptr; // pints to the actual pixels
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;
// this is for  used like an id for fractal
typedef struct s_fractal
{
	char	*name;
	void *mlx_connection; // mlx_init()
	void *mlx_window;     // mlx_new_window
	// Image
	t_img	img;
	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

typedef struct s_complex
{
	// real
	double	x;
	// i
	double	y;
}			t_complex;

int	ft_strncmp(const char *s1, const char *s2, size_t n); // strings
void	fractal_init(t_fractal *fractal);                    // init
double		map(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
// void data_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
double		atobbl(char *s);
int			julia_track(int x, int y, t_fractal *fractal);

#endif