/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 08:05:11 by jmilesi           #+#    #+#             */
/*   Updated: 2023/12/08 08:30:59 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*data;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}t_img;

typedef struct s_list
{
	void	*mlx_win;
	void	*mlx_ptr;
	int		window_width;
	int		window_height;
	int		color;
	int		fractal_name;
	int		x;
	double	x_min;
	double	x_max;
	int		y;
	double	y_min;
	double	y_max;
	double	zoom_x;
	double	zoom_y;
	int		img_x;
	int		img_y;
	double	z_real;
	double	z_im;
	double	abs_z_real;
    double	abs_z_im;
	double	c_real;
	double	c_im;
	double	iteration;
	double	temp;
	float	display_shift;
	int		max_iteration;
	t_img	*img;
}				t_list;

int				main(int argc, char **argv);
int				ft_check_fractal_name(t_list *ptr, char **argv, int argc);

void			ft_init_each_fractal_settings(t_list *ptr);
void			ft_launch_each_fractal(t_list *ptr);

int				ft_init_mlx(t_list *ptr);
void			ft_draw_pixels(int x, int y, int color, t_list *ptr);
int				ft_put_image_to_window(t_list *ptr);

void			destroy_fractol(t_list *ptr);


void			ft_settings(t_list *ptr);
void			ft_init(t_list *ptr);
void			ft_calculate_and_launch(t_list *ptr);



void			validating_julia_parameters(int argc, char *argv[],
					t_list *ptr);

int				key_hook(int keysym, t_list *ptr);

int				zoom_hook(int keysym, int x, int y, t_list *ptr);

int				ft_init_hooks_and_loop(t_list *ptr);

int				ft_isdigit(int c);
double			ft_atod(char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
