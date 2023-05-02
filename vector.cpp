#include "vector.h"

template<class T> void vector<T>::swap(vector<T> &b){
    int temp=b.sz;
    T *tempelem=b.elem;
    b.sz=sz;
    b.elem=elem;
    sz=temp;
    elem=tempelem;
}
template void vector<int>::swap(vector<int> &b);
template void vector<double>::swap(vector<double> &b);
template void vector<float>::swap(vector<float> &b);