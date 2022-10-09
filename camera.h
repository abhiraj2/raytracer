#pragma once

#include "vec3.h"
#include "ray.h"

class CAMERA{
    public:
    CAMERA(){
        low_left = VEC3(-2,-1,-1);
        origin = VEC3(0,0,0);
        horizontal_dist = VEC3(4,0,0);
        vert_dist = VEC3(0,2,0);
    }

    RAY get_ray(float u, float v){return RAY(origin, low_left + u*horizontal_dist + v*vert_dist);}

    VEC3 low_left;
    VEC3 origin;
    VEC3 horizontal_dist;
    VEC3 vert_dist;
};