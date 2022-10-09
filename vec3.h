#include<iostream>
#include<cmath>

#pragma once

class VEC3{
    public:
        VEC3(){}
        VEC3(float x1, float y1, float z1){x = x1; y=y1; z=z1;}
        float x,y,z;
        
        VEC3 operator-(){return VEC3(-x, -y, -z);}
        VEC3 operator+(){return *this;}
        
        VEC3& operator+=(const VEC3& v2);
        VEC3& operator-=(const VEC3& v2);
        VEC3& operator*=(const VEC3& v2);
        VEC3& operator/=(const VEC3& v2);
        VEC3& operator+=(const float f2);
        VEC3& operator-=(const float f2);
        VEC3& operator*=(const float f2);
        VEC3& operator/=(const float f2);

        float operator[](int i){
            if(i==0) return x;
            if(i==1) return y;
            if(i==2) return z;
        }

        void normalize();
        float magnitude();
};


float dot(const VEC3& v1, const VEC3& v2);
VEC3 cross(const VEC3& v1, const VEC3& v2);

std::ostream& operator<<(std::ostream& ost, VEC3 v);

std::istream& operator>>(std::istream& ist, VEC3 v);

VEC3 operator+(const VEC3& v1, const VEC3& v2);
VEC3 operator-(const VEC3& v1, const VEC3& v2);
VEC3 operator*(const VEC3& v1, const VEC3& v2);
VEC3 operator/(const VEC3& v1, const VEC3& v2);
VEC3 operator+(const VEC3& v1, float f2);
VEC3 operator-(const VEC3& v1, float f2);
VEC3 operator*(const VEC3& v1, float f2);
VEC3 operator/(const VEC3& v1, float f2);

VEC3 operator+(float f2, const VEC3& v1);
VEC3 operator-(float f2, const VEC3& v1);
VEC3 operator*(float f2, const VEC3& v1);
VEC3 operator/(float f2, const VEC3& v1);
