/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:00:20 by cspreafi          #+#    #+#             */
/*   Updated: 2024/05/06 11:00:26 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check_fractal_name(t_list *ptr, char **argv, int argc)
{
	if (!ft_strncmp("mandelbrot", argv[1], 10))
		ptr->fractal_name = 1;
	else if (!ft_strncmp("julia", argv[1], 5))
	{
		ptr->fractal_name = 2;
		validating_julia_parameters(argc, argv, ptr);
	}
	else if (!ft_strncmp("burningship", argv[1], 11))
		ptr->fractal_name = 3;
	else
		return (0);
	ft_settings(ptr);
	return (1);
}

void	validating_julia_parameters(int argc, char *argv[], t_list *ptr)
{
	if (argc == 4 && ft_check(argv) == 1)
	{
		ptr->c_real = ft_atod(argv[2]);
		ptr->c_im = ft_atod(argv[3]);
	}
	else
	{
		write(1, "Please enter suitable coordinates such as:\n", 44);
		write(1, "\t0.701 -0.382\n\t-0.726 0.189\n\t0.000 -0.800\n", 43);
		exit(0);
	}
}

void	ft_settings(t_list *ptr)
{
	ptr->iteration = 0;
	ptr->x_min = -2.0;
	ptr->x_max = 2.0;
	ptr->y_min = -2.0;
	ptr->y_max = 2.0;
	ptr->img_x = ptr->window_width;
	ptr->img_y = ptr->window_height;
	ptr->zoom_x = 150;
	ptr->zoom_y = 150;
	ptr->z_real = 0;
	ptr->z_im = 0;
	ptr->max_iteration = 200;
	ptr->color = 0xFA0CF0C;
	if (ptr->fractal_name == 1 || ptr->fractal_name == 3)
	{
		ptr->c_real = ptr->x / ptr->zoom_x + ptr->x_min;
		ptr->c_im = ptr->y / ptr->zoom_y + ptr->y_max;
	}
}

void	ft_init(t_list *ptr)
{
	ptr->iteration = 0;
	if (ptr->fractal_name == 1 || ptr->fractal_name == 3)
	{
		ptr->c_real = ptr->x / ptr->zoom_x + ptr->x_min;
		ptr->c_im = ptr->y / ptr->zoom_y + ptr->y_min;
		ptr->z_real = 0;
		ptr->z_im = 0;
	}
	else
	{
		ptr->z_real = ptr->x / ptr->zoom_x + ptr->x_min;
		ptr->z_im = ptr->y / ptr->zoom_y + ptr->y_min;
	}
}

int	ft_init_hooks_and_loop(t_list *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (!(ptr->mlx_ptr))
		perror("");
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr,
			ptr->window_width, ptr->window_height, "fract-ol ;p");
	if (!(ptr->mlx_win))
		perror("");
	ft_put_image_to_window(ptr);
	mlx_hook(ptr->mlx_win, 17, 0, destroy_fractol, ptr);
	mlx_hook(ptr->mlx_win, 2, 1L << 0, key_hook, ptr);
	mlx_mouse_hook(ptr->mlx_win, zoom_hook, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}
