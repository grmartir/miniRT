# include "minirt.h"

void    ray_tracing(void *mlx, void *window, t_scene *scene)
{
    int     mlx_x = 0;
    int     mlx_y = 0; //for mlx_pixel_put
    float   x_angle;
    float   y_angle;
    int     color;
    float   x_ray;
    float   y_ray;
    t_vector    *ray;
    t_vplane    *vplane;

    vplane = get_view_plane(scene->width, scene->height, scene->cams->fav);
    mlx_y = 0;
    y_angle = (scene->height / 2);
    while (y_angle >= (scene-> height /2) * (-1))
    {
        y_ray = y_angle  * vplane->y_pixel;
        x_angle = (scene->width / 2) * (-1);
        mlx_x = 0;
        while (x_angle <= scene->width / 2)
        {
            x_ray = x_angle * vplane->x_pixel;
            ray = new_vector(x_ray, y_ray, -1);
            vec_normalsize(ray);
            if (sphere_intersect(scene->cams, ray, scene->sphere))
                color = 0xfffacd;
            else   
                color = 0;
            mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
            free(ray);
            x_angle++;
            mlx_x++;
        }
        y_angle--;
        mlx_y++;
        printf("mlx_x = %d mlx_y = %d\n", mlx_x, mlx_y);
    }
}

t_vplane    *get_view_plane(float width, float height, float fav)
{
    t_vplane    *vplane;
    float       aspect_ratio;

    fav = 1;
    vplane = malloc(sizeof(t_vplane));
    if (!vplane)
        error_exit(-1);
    aspect_ratio = width / height;
    vplane->width = 1;
    vplane->height = vplane->width / aspect_ratio;
    vplane->x_pixel = vplane->width / width;
    vplane->y_pixel = vplane->height / height;
    return (vplane);
}
