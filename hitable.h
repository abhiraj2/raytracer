#pragma once
#include "ray.h"

struct hitpoint{
    float t;
    VEC3 P;
    VEC3 N;
};

class hitable{
    public:
        virtual int hit_check(const RAY& r, float t_min, float t_max, hitpoint& rec) const = 0;
};

class sphere: public hitable{
    public:
        sphere(){}
        sphere(const VEC3& c, float r){center = c; radius =r;}
        virtual int hit_check(const RAY& r, float t_min, float t_max, hitpoint& rec) const;
        VEC3 center;
        float radius;
};

class hitable_list: public hitable{
    public:
    hitable_list(){}
    hitable_list(hitable **l, int n){lis = l; list_size = n;}
    virtual int hit_check(const RAY& r, float t_min, float t_max, hitpoint& rec) const;
    int list_size;
    hitable** lis;
};

