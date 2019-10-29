/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/28 13:07:14 by ihering-       #+#    #+#                */
/*   Updated: 2019/08/01 15:24:49 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoomin(int w, int h, t_fractol *f)
{
	f->min_re = (w / f->zoom + f->min_re) - (w / (f->zoom * 1.2));
	f->min_im = (h / f->zoom + f->min_im) - (h / (f->zoom * 1.2));
	f->zoom *= 1.2;
	f->max_int++;
}

void	zoomout(int w, int h, t_fractol *f)
{
	f->min_re = (w / f->zoom + f->min_re) - (w / (f->zoom / 1.2));
	f->min_im = (h / f->zoom + f->min_im) - (h / (f->zoom / 1.2));
	f->zoom /= 1.2;
	f->max_int--;
}

int		mouse_move(int w, int h, t_fractol *f)
{
	if (f->lock == 0)
	{
		f->mouse_w = (double)w;
		f->mouse_h = (double)h;
	}
	return (1);
}

int		ft_mouse(int key, int w, int h, t_fractol *f)
{
	if (key == ZOOMIN)
		zoomin(w, h, f);
	else if (key == ZOOMOUT)
		zoomout(w, h, f);
	if (key == LEFT_BUTTON && f->fractol == 1 && f->lock == 0)
		f->lock += 1;
	else if (key == LEFT_BUTTON && f->fractol == 1 && f->lock == 1)
		f->lock -= 1;
	if (f->fractol == 0)
		mandelbrot(f);
	else if (f->fractol == 1)
		julia(f);
	else if (f->fractol == 2)
		burningship(f);
	writemenu(f);
	return (0);
}
