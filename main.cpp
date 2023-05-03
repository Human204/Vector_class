#include "vector.h"
int main(){
vector<std::string> a;
int x=1,y=2;
a.push_back("ab");
a.push_back("bc");
a.push_back("cd");
for(auto &i : a){
  cout<<i<<endl;
}
vector<double> b;
// cout<<b.capacity()<<endl;

// cout<<b.max_size()<<endl;
// b.reserve(5);
// cout<<*a<<endl;
// cout<<a.data()<<endl;
cout<<a.cbegin()<<" "<<a.end()<<endl;
vector<std::string>::iterator it(a.begin());

  return 0;
}