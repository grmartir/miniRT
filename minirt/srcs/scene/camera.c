# include "minirt.h"

t_camera    *new_cam(t_vector *origin, t_vector *direction, float fav)
{
    t_camera    *cam;

    cam = malloc(sizeof(t_camera));
    if (!cam)
        error_exit(-1);
    cam->origin = origin;
    cam->direction = direction;
    cam->fav = fav;
    return (cam);
}
