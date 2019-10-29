/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 13:53:04 by ihering-       #+#    #+#                */
/*   Updated: 2019/08/01 15:21:10 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_fractol *f)
{
	f->min_re = -2;
	f->max_re = 3.5;
	f->min_im = -1.5;
	f->max_im = 3;
	f->zoom = 250;
	f->max_int = 70;
	f->color = 1;
	f->lock = 0;
	f->width = 0;
	f->height = 0;
}

int		int_julia(t_fractol *f, int h, int w)
{
	int		i;
	double	zr;
	double	zi;
	double	zrsqr;
	double	zisqr;

	i = 0;
	zr = (w + f->width) / f->zoom + f->min_re;
	zi = (h + f->height) / f->zoom + f->min_im;
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

void	julia(t_fractol *f)
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
			f->c_re = -1 + (f->mouse_w * 0.002);
			f->c_im = -1.2 + (f->mouse_h * 0.002);
			n = int_julia(f, h, w);
			c = colors(n, f);
			put_pixel(w, h, c, f);
			h++;
		}
		w++;
		h = -1;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
