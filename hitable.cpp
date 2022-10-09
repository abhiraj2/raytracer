#include "hitable.h"

int sphere::hit_check(const RAY& r, float t_min, float t_max, hitpoint& rec) const {
    VEC3 amc = r.origin()-this->center; 
    float a = dot(r.direction(), r.direction());
    float b = 2.0*dot(amc, r.direction());
    float c = dot(amc, amc)-this->radius*this->radius;
    //cout << (b*b) << std::endl;
    float t = b*b - 4*a*c;
    if(t>0)
    {
        float temp = (-b-sqrt(t))/(2*a);
        if(temp>t_min && temp<t_max){
            rec.t = temp;
            rec.P = r.point_at_t(temp);
            rec.N = rec.P - this->center;
            rec.N.normalize();
            // std::cout << radius << std::endl;
            // std::cout << rec.N/radius << std::endl;
            //std::cout << rec.N << std::endl;
            return 1;
        }
        temp = (-b+sqrt(t))/(2*a);
        if(temp>t_min && temp<t_max){
            rec.t = temp;
            rec.P = r.point_at_t(temp);
            rec.N = rec.P - this->center;
            rec.N.normalize();
            //rec.N.normalize();
            //std::cout << rec.N/radius << std::endl;
            return 1;
        }
    }
    
    return 0; 
}


int hitable_list::hit_check(const RAY& r, float t_min, float t_max, hitpoint& rec) const {
    //basically want to store the result of the closest intersection

    hitpoint temp_rec;
    float closest_rn = t_max;
    int hit = 0;
    for(int i=0; i<list_size; i++){
        if(lis[i]->hit_check(r, t_min, closest_rn, temp_rec)){
            rec = temp_rec;
            closest_rn = temp_rec.t;
            hit =1;
        }
    }
    return hit;
}

