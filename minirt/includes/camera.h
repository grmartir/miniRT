#ifndef CAMERA_H
# define CAMERA_H

// # include "minirt.h"

typedef struct s_camera
{
    t_vector    *origin;
    t_vector    *direction;
    float       fav;
}               t_camera;

t_camera    *new_cam(t_vector *origin, t_vector *direction, float fav);

#endif