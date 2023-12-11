# include "minirt.h"

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_W)//Action when W key pressed
		param->x++;
	else if (keycode == KEY_S) //Action when S key pressed
		param->x--;
	else if (keycode == KEY_ESC) //Quit the program when ESC key pressed
		exit(0);
	printf("x: %d\n", param->x);
	return (0);
}
t_scene			*param_init(t_param *param)
{
	t_vector    *sphere_center = new_vector(0, 0, -32);
    t_sphere    *sphere = new_sphere(sphere_center, 12/2);
    t_vector    *cam_origin = new_vector(param->x, param->y, 0);
    t_vector    *cam_direction = new_vector(param->x, param->y, -1);
    t_camera    *cam = new_cam(cam_origin, cam_direction, 70);
    t_scene     *scene = new_scene(cam, sphere);
	return (scene);
}
int main(void)
{
    void    *mlx;
    void    *window;
	t_param param;

    t_scene *scene = param_init(&param);
	mlx = mlx_init();
    
    scene->width = 800;
    scene->height = 800;
    window = mlx_new_window(mlx, scene->width, scene->height, "EXPERIMENT");
    ray_tracing(mlx, window, scene);
    //free_scene(scene);
	mlx_hook(window, X_EVENT_KEY_PRESS, 0, &key_press, &param);
    mlx_loop(mlx);
    return (0);
}






// int			main(void)
// {
// 	void		*mlx;
// 	void		*win;
// 	t_param		param;

// 	param_init(&param);
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "mlx_project");
// 	printf("-------------------------------\n");
// 	printf("'W key': Add 1 to x.\n");
// 	printf("'S key': Subtract 1 from x\n");
// 	printf("'ESC key': Exit this program\n");
// 	printf("'Other keys': print current x \n");
// 	printf("-------------------------------\n");
// 	printf("Current x = 3\n");
// 	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
// 	mlx_loop(mlx);
// }