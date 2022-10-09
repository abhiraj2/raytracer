#ifndef _RAY
    #include "ray.h" //includes vec3 and iostream as well
#endif

VEC3 RAY::origin() const {
    return A;
}

VEC3 RAY::direction()const{
    return B;
}

VEC3 RAY::point_at_t(float t)const{
    return (A+B*t);
}

std::ostream& operator<<(std::ostream& out, RAY& v){
    out << v.A << " ; " << v.B;
    return out;
}




// int main(){
//     VEC3 a = VEC3(1.0f,2.0f,3.0f);
//     VEC3 b = VEC3(5.0f, 3.0f, 1.0f);
//     RAY r = RAY(a, b);
//     std::cout << r << std::endl;
//     std::cout << r.origin() << std::endl;
//     std::cout << r.direction() << std::endl;
//     return 0;
// }
