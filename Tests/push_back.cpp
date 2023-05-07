#include<iostream>
#include<vector>
#include"../vector.h"
#include<chrono>
class Timer {
private:
using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;
std::chrono::time_point<hrClock> start;
public:
Timer() : start{ hrClock::now() } {}
void reset() {
start = hrClock::now();
}
double elapsed() const {
return durationDouble (hrClock::now() - start).count();
}
};
int main(){
    
    unsigned int sz[4]={100000,1000000,10000000,100000000};
    Timer t;
    for(int j=0;j<4;j++){
        cout<<sz[j]<<'\n';
        // Pradėti v1 užpildymo laiko matavimą
        // unsigned int sz = 100000000;  // 100000, 1000000, 10000000, 100000000
        std::vector<int> v1;
        for (int i = 1; i <= sz[j]; ++i){
        v1.push_back(i);
        }
        cout<<"std: "<<t.elapsed()<<endl;
        t.reset();
        // Baigti v1 užpildymo laiko matavimą

        // Pradėti v2 užpildymo laiko matavimą
        vector<int> v2;
        for (int i = 1; i <= sz[j]; ++i){
            // cout<<"b\n";
        v2.push_back(i);
        }
        cout<<"custom: "<<t.elapsed()<<endl;
        t.reset();
        // Baigti v2 užpildymo laiko matavimą
    }
}