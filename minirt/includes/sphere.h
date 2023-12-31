#ifndef SPHERE_H
# define SPHERE_H

// # include "minirt.h"

typedef struct s_sphere
{
    t_vector    *center;
    float       radius;
}               t_sphere;

t_sphere *new_sphere(t_vector *center, float radius);

#endif