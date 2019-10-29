/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burningship.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/29 10:35:48 by ihering-       #+#    #+#                */
/*   Updated: 2019/08/01 14:04:50 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_burningship(t_fractol *f)
{
	f->min_re = -3;
	f->max_re = 2;
	f->min_im = -3;
	f->max_im = 2;
	f->zoom = 280;
	f->max_int = 50;
	f->color = 1;
	f->width = 0;
	f->height = 0;
	burningship(f);
}

int		int_burningship(t_fractol *f, int i)
{
	double	zr;
	double	zi;
	double	temp;
	double	zrsqr;
	double	zisqr;

	zr = 0;
	zi = 0;
	zrsqr = zr * zr;
	zisqr = zi * zi;
	while (zisqr + zrsqr < 4.0 && i < f->max_int)
	{
		temp = zr;
		zr = fabs(zrsqr) - zisqr + f->c_re;
		zi = 2 * fabs(zi) * fabs(temp) + f->c_im;
		zrsqr = zr * zr;
		zisqr = zi * zi;
		i++;
	}
	return (i);
}

void	burningship(t_fractol *f)
{
	int h;
	int w;
	int	n;
	int	c;
	int	i;

	i = 0;
	h = -1;
	w = -1;
	while (w < S_WIDTH)
	{
		while (h < S_HEIGHT)
		{
			f->c_re = (w + f->width) / f->zoom + f->min_re;
			f->c_im = (h + f->height) / f->zoom + f->min_im;
			n = int_burningship(f, i);
			c = colors(n, f);
			put_pixel(w, h, c, f);
			h++;
		}
		w++;
		h = -1;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
