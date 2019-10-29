/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 11:11:23 by ihering-       #+#    #+#                */
/*   Updated: 2019/08/01 15:28:01 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_fracs(t_fractol *f)
{
	if (f->fractol == 0)
		init_mandelbrot(f);
	if (f->fractol == 1)
		julia(f);
	else if (f->fractol == 2)
		init_burningship(f);
	writemenu(f);
	return (0);
}

void	images_julia(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx, S_WIDTH, S_HEIGHT);
	f->data = mlx_get_data_addr(f->img, &f->bpp, &f->line, &f->endian);
	mlx_key_hook(f->win, ft_keys, f);
	mlx_mouse_hook(f->win, ft_mouse, f);
	mlx_hook(f->win, 6, 0, mouse_move, f);
	mlx_loop_hook(f->mlx, init_fracs, f);
	mlx_loop(f->mlx);
}

void	images_frac(t_fractol *f)
{
	f->img = mlx_new_image(f->mlx, S_WIDTH, S_HEIGHT);
	f->data = mlx_get_data_addr(f->img, &f->bpp, &f->line, &f->endian);
	mlx_key_hook(f->win, ft_keys, f);
	mlx_mouse_hook(f->win, ft_mouse, f);
	init_fracs(f);
	mlx_loop(f->mlx);
}

int		ft_check(char *argv, t_fractol *f)
{
	if (ft_strcmp(argv, "Mandelbrot") == 0)
		f->fractol = 0;
	else if (ft_strcmp(argv, "Julia") == 0)
		f->fractol = 1;
	else if (ft_strcmp(argv, "BurningShip") == 0)
		f->fractol = 2;
	else
		ft_error("usage : fractol [fractals]bb \nfractals: \n--> Mandelbrot \
		\n--> Julia \n--> BurningShip");
	return (1);
}

int		main(int argc, char **argv)
{
	t_fractol	*f;

	if (argc != 2)
		ft_error("usage : fractol [fractals] \nfractals: \n--> Mandelbrot \
		\n--> Julia \n--> BurningShip");
	if (!(f = (t_fractol*)malloc(sizeof(t_fractol))))
		return (0);
	if (ft_check(argv[1], f) == 0)
		return (0);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, S_WIDTH, S_HEIGHT, "Fractol");
	if (f->fractol == 0 || f->fractol == 2)
		images_frac(f);
	else if (f->fractol == 1)
	{
		init_julia(f);
		images_julia(f);
	}
	free(f);
	return (0);
}
