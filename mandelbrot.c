/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 11:28:55 by ihering-       #+#    #+#                */
/*   Updated: 2019/08/01 14:04:36 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractol *f)
{
	f->min_re = -2.1;
	f->max_re = 1.2;
	f->min_im = -1.3;
	f->max_im = 1.2;
	f->zoom = 400;
	f->max_int = 40;
	f->color = 1;
	f->width = 0;
	f->height = 0;
	mandelbrot(f);
}

int		int_mandelbrot(t_fractol *f)
{
	int		i;
	double	zr;
	double	zi;
	double	zrsqr;
	double	zisqr;

	i = 0;
	zr = 0;
	zi = 0;
	zrsqr = zr * zr;
	zisqr = zi * zi;
	while (zisqr + zrsqr < 4.0 && i < f->max_int)
	{
		zi = zr * zi;
		zi += zi;
		zi += f->c_im;
		zr = zrsqr - zisqr + f->c_re;
		zrsqr = zr * zr;
		zisqr = zi * zi;
		i++;
	}
	return (i);
}

void	mandelbrot(t_fractol *f)
{
	int h;
	int w;
	int	n;
	int	c;

	h = -1;
	w = -1;
	while (w < S_WIDTH)
	{
		while (h < S_HEIGHT)
		{
			f->c_re = (w + f->width) / f->zoom + f->min_re;
			f->c_im = (h + f->height) / f->zoom + f->min_im;
			n = int_mandelbrot(f);
			c = colors(n, f);
			put_pixel(w, h, c, f);
			h++;
		}
		w++;
		h = -1;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
