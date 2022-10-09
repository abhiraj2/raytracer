#ifndef _VEC3
    #include "vec3.h" //includes vec3, CMATH and IOSTREAM
#endif

using namespace std;

std::ostream& operator<<(std::ostream& ost, VEC3 v){
    ost << v.x << " " <<  v.y << " " << v.z;
    return ost;
}


std::istream& operator>>(std::istream& ist, VEC3 v){
    ist >> v.x >>  v.y >> v.z;
    return ist;
}


VEC3& VEC3::operator+=(const VEC3& v2){
    x+=v2.x;
    y+=v2.y;
    z+=v2.z;
    return *this;
}

VEC3& VEC3::operator-=(const VEC3& v2){
    x+=v2.x;
    y+=v2.y;
    z+=v2.z;
    return *this;
}

VEC3& VEC3::operator*=(const VEC3& v2){
    x+=v2.x;
    y+=v2.y;
    z+=v2.z;
    return *this;
}

VEC3& VEC3::operator/=(const VEC3& v2){
    x+=v2.x;
    y+=v2.y;
    z+=v2.z;
    return *this;
}

VEC3& VEC3::operator+=(float f2){
    x+=f2;
    y+=f2;
    z+=f2;
    return *this;
}

VEC3& VEC3::operator-=(float f2){
    x-=f2;
    y-=f2;
    z-=f2;
    return *this;
}
VEC3& VEC3::operator*=(float f2){
    x*=f2;
    y*=f2;
    z*=f2;
    return *this;
}
VEC3& VEC3::operator/=(float f2){
    x/=f2;
    y/=f2;
    z/=f2;
    return *this;
}

float dot(const VEC3& v1, const VEC3& v2){
    float res;
    res = v1.x*v2.x+ v1.y*v2.y+ v1.z*v2.z;
    return res;
}

VEC3 cross(const VEC3& v1, const VEC3& v2){
    return VEC3(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v2.z*v1.x, v2.y*v1.x - v1.y*v2.x);
}

VEC3 operator+(const VEC3& v1, const VEC3& v2){
    return VEC3(v1.x+v2.x,v1.y+v2.y,v1.z+v2.z);
}

VEC3 operator-(const VEC3& v1, const VEC3& v2){
    return VEC3(v1.x-v2.x,v1.y-v2.y,v1.z-v2.z);
}

VEC3 operator*(const VEC3& v1, const VEC3& v2){
    return VEC3(v1.x*v2.x,v1.y*v2.y,v1.z*v2.z);
}

VEC3 operator/(const VEC3& v1, const VEC3& v2){
    return VEC3(v1.x/v2.x,v1.y/v2.y,v1.z/v2.z);
}

VEC3 operator+(const VEC3& v1, float f2){
    return VEC3(v1.x+f2, v1.y+f2, v1.z+f2);
}

VEC3 operator-(const VEC3& v1, float f2){
    return VEC3(v1.x-f2, v1.y-f2, v1.z-f2);
}
VEC3 operator*(const VEC3& v1, float f2){
    return VEC3(v1.x*f2, v1.y*f2, v1.z*f2);
}
VEC3 operator/(const VEC3& v1, float f2){
    return VEC3(v1.x/f2, v1.y/f2, v1.z/f2);
}


VEC3 operator+(float f2, const VEC3& v1){
    return VEC3(v1.x+f2,v1.y+f2,v1.z+f2);
}
VEC3 operator*(float f2, const VEC3& v1){
    return VEC3(v1.x*f2,v1.y*f2,v1.z*f2);
}

VEC3 operator-(float f2, const VEC3& v1){
    return VEC3(f2-v1.x,f2-v1.y,f2-v1.z);
}


VEC3 operator/(float f2, const VEC3& v1){
    return VEC3(f2/v1.x,f2/v1.y,f2/v1.z);
}

void VEC3::normalize(){
    *this /= sqrt(x*x+y*y+z*z);
}

float VEC3::magnitude(){
    return sqrt(x*x+y*y+z*z);
}

// int main(){
//     VEC3 v1(1.0f,1.0f,2.0f);
//     VEC3 v2(5.0f,2.0f,1.0f);
//     cout << v1 <<std::endl << v2 << std::endl;
    
//     // cout << v1+v2 << "\n" << v1*v2 << "\n" << v1*v2 << "\n" << v1-v2 << "\n" << v1/v2 << "\n";
//     // cout << v1+2.0f << "\n" << v1*2.0f << "\n" << v1*2.0f << "\n" << v1-2.0f << "\n" << v1/2.0f << "\n"; 
//     cout << -v1 << std::endl;
//     v1.normalize();
//     cout << v1 << std::endl;
//     cout << v2.magnitude() << std::endl;
//     v1+= v2;
//     cout << v1 << std::endl;

//     cout << dot(v1, v2);
// }