#include "vector.h"
int main(){
vector<int> a;
a.push_back(1);
a.push_back(2);
a.push_back(3);
cout<<a.max_size()<<endl;
vector<double> b;
cout<<b.max_size()<<endl;
b.reserve(5);
// cout<<*a<<endl;
// cout<<a.data()<<endl;

  return 0;
}