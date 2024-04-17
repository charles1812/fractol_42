#include "../inc/fractol.h"

int	ft_put_image_to_window(t_list *ptr)
{
	if (ptr->img->mlx_img)
		mlx_destroy_image(ptr->mlx_ptr, ptr->img->mlx_img);
	ptr->img->mlx_img = mlx_new_image(ptr->mlx_ptr,
			ptr->window_width, ptr->window_height);
	if (!(ptr->img->mlx_img))
		perror("");
	ptr->img->data = mlx_get_data_addr(ptr->img->mlx_img,
			&ptr->img->bits_per_pixel, &ptr->img->line_length,
			&ptr->img->endian);
	if (!(ptr->img->data))
		perror("");
	ptr->x = 0;
	ft_calculate_and_launch(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr,
		ptr->mlx_win, ptr->img->mlx_img, 0, 0);
	return (0);
}

void	ft_calculate_and_launch(t_list *ptr)
{
	while (ptr->x < ptr->img_x)
	{
		ptr->y = 0;
		while (ptr->y < ptr->img_y)
		{
			ft_init(ptr);
			while (ptr->z_real * ptr->z_real + ptr->z_im * ptr->z_im < 4
				&& ptr->iteration < ptr->max_iteration)
			{
				ptr->temp = ptr->z_real;
				if (ptr->fractal_name == 1)
					ptr->z_real = ptr->z_real * ptr->z_real - ptr->z_im
						* ptr->z_im + ptr->c_real;
				else if (ptr->fractal_name == 2)
					ptr->z_real = ptr->z_real * ptr->z_real - ptr->z_im
						* ptr->z_im + ptr->c_real;
				else
				{
					double abs_z_real = fabs(ptr->z_real);
    				double abs_z_im = fabs(ptr->z_im);
    				ptr->z_real = (abs_z_real + abs_z_im) * (abs_z_real + abs_z_im) + ptr->c_real;
					ptr->z_im = 2 * abs_z_real * abs_z_im + ptr->c_im;
				}
				ptr->z_im = 2 * ptr->z_im * ptr->temp + ptr->c_im;
				ptr->iteration++;
			}
			ft_draw_pixels(ptr->x, ptr->y,
				ptr->iteration * ptr->color / ptr->max_iteration, ptr);
			ptr->y++;
		}
		ptr->x++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		perror("");
	ptr->img = (t_img *)malloc(sizeof(t_img));
	if (!ptr->img)
		perror("");
	ptr->window_width = 600;
	ptr->window_height = 600;
	ptr->display_shift = 0.1;
	if (argc < 2 || argc > 4 || ft_check_fractal_name(ptr, argv, argc) != 1)
	{
		write(1, "Please enter the name of the fractal you want to see:\n", 55);
		write(1, "mandelbrot\njulia 'real part' 'imaginary part'", 46);
		exit(0);
	}
	else
		ft_init_hooks_and_loop(ptr);
	return (0);
}
