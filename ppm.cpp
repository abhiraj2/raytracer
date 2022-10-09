#include<iostream>
#include<fstream> 
#include<vector>

class pixel{
    public:
        int x=0, y=0, z=0;
};


using namespace std;

int main(){
    fstream ppm;
    ppm.open("img.ppm", ios::out);
    if(!ppm){
        cout << "Nah\n";
    }
    else{
        ppm << "P3\n";
        ppm << "3 2\n";
        ppm << "255\n";
        vector<vector<pixel>> pixels(2, vector<pixel>(3));
        pixels[0][0].x = 255;
        pixels[0][1].y = 255;
        pixels[0][2].z = 255;
        pixels[1][0].x = pixels[1][0].y = 255;
        pixels[1][1].x = pixels[1][1].z = 255;
        pixels[1][2].y = pixels[1][2].z = 255;
        for(auto i:pixels){
            for(auto j:i){
                ppm << j.x << "\t" << j.y << "\t" << j.z << "\n";  
            }
            ppm << "\n";
        }
        ppm.close();
    }
    return 0;
}