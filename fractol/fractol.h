/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:14:55 by fishaq            #+#    #+#             */
/*   Updated: 2024/02/20 22:06:36 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define MAGENTA 0xFF00FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define DEEPINK 0xFF1493
# define BLUSH 0xDE5D83

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
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
	double	x;
	double	y;
}			t_complex;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		fractal_init(t_fractal *fractal);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		fractal_render(t_fractal *fractal);
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
double		atobbl(char *s);
int			julia_track(int x, int y, t_fractal *fractal);
void		ft_putstr_fd(char *s, int fd);
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
int			is_valid_julia_parameter(const char *param);
int			check_julia_parameters(t_fractal *fractal, char **av);

#endif