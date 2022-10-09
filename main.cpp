#include "hitable.h"
#include "camera.h"
#include <fstream>
#include <cstdlib>
using namespace std;

VEC3 color(const RAY& r, hitable* world){
    hitpoint rec;

    if(world->hit_check(r, 0.0f, 9999999.0f, rec)){
        return 0.5*VEC3(rec.N.x+1, rec.N.y+1, rec.N.z+1);
    }
    else{
        VEC3 dir = r.direction();
        dir.normalize();
        float t = 0.5*(dir.y + 1);
        return VEC3(0.5f, 0.7f, 1.0f)*t + VEC3(1.0f, 1.0f, 1.0f)*(1.0f-t);
    }

}

int main(){

    fstream ppm;
    ppm.open("img.ppm", ios::out);
    
    int row  = 200;
    int col = 300;
    int samp = 300; //number of samples
    float max = 255.0f;

    ppm << "P3\n" << col << " " << row << std::endl << "255\n"; 

    VEC3 colo;

    hitable *lis[2];
    lis[0] = new sphere(VEC3(0, 0, -1), 0.5f);
    lis[1] = new sphere(VEC3(0, -100.5, -1), 100);
    hitable *world_obj = new hitable_list(lis, 2);
    CAMERA cam;
    for(int i=row-1; i>=0; i--){
        for(int j=0; j<col; j++){
            colo = VEC3(0,0,0);
            for(int s=0; s<samp; s++){
                float u = float(j+(float(rand())/float(RAND_MAX)))/col;
                float v = float(i+(float(rand())/float(RAND_MAX)))/row;
                RAY r = cam.get_ray(u,v);
                colo += color(r, world_obj);
            }
            colo /= samp;
            colo*=255.99f;
            ppm << colo << "\n";
        }
    }
   return 0;   
}