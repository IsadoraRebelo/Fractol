/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 10:57:22 by ihering-       #+#    #+#                */
/*   Updated: 2019/08/01 15:03:59 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "keys.h"
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>
# include "./minilibx/mlx.h"

# define S_HEIGHT 1000
# define S_WIDTH 1400

typedef struct		s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	double		c_re;
	double		c_im;
	double		max_re;
	double		min_re;
	double		max_im;
	double		min_im;
	double		zoom;
	double		max_int;
	double		mouse_w;
	double		mouse_h;
	int			lock;
	int			color;
	int			fractol;
	int			width;
	int			height;
	int			line;
	int			bpp;
	int			endian;
}					t_fractol;

/*
** Mandelbrot Set
*/
void				init_mandelbrot(t_fractol *f);
void				mandelbrot(t_fractol *f);
/*
** Julia Set
*/
void				init_julia(t_fractol *f);
void				julia(t_fractol *f);
int					mouse_move(int w, int h, t_fractol *f);
/*
** Burning Ship Set
*/
void				init_burningship(t_fractol *f);
void				burningship(t_fractol *f);
/*
** Drawn & Colors
*/
int					colors(int n, t_fractol *f);
void				put_pixel(int w, int h, int color, t_fractol *f);
/*
** Menu & Keys
*/
void				writemenu(t_fractol *f);
int					ft_mouse(int key, int w, int h, t_fractol *f);
int					ft_keys(int key, t_fractol *f);

#endif
