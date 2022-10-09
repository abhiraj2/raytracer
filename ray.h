#pragma once

#include "vec3.h"


class RAY{
    public:
        RAY(){}
        RAY(const VEC3& a, const VEC3& b){
            A = a;
            B = b;
        }
        VEC3 origin() const;
        VEC3 direction() const;
        VEC3 point_at_t(float t) const;
        VEC3 A,B;
};

std::ostream& operator<<(std::ostream& out, RAY& r);