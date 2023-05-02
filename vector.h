#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
#include<iostream>
#include<limits>

using std::cout;
using std::endl;
using std::iterator;
using std::max;

template <class T>
class vector{
    private:
    int sz;
    T *elem;

    public:
    vector(): sz(0){};
    vector(int s, T val) : sz(s), elem(new T[s]) { std::fill_n(elem, s, val); }
    vector(const vector& b);
    vector(std::initializer_list<T> list):sz(list.size()),elem(new T[list.size()]){int i=0;for(auto &list_elem :list){elem[i]=list_elem;i++;};}
    // setteriai

    // getteriai
    void reserve(int &n){T *temp=new T[n];for(int i=0;i<sz;i++){temp[i]=elem[i];}delete[]elem;elem=temp;}
    void reserve(int &&n){T *temp=new T[n];for(int i=0;i<sz;i++){temp[i]=elem[i];}delete[]elem;elem=temp;}
    T max_size() const{return std::numeric_limits<T>::max();}
    inline bool empty() const{if(sz==0)return true;else return false;}
    T* operator*(){return elem;}
    T& operator[](int i){
        if (i < 0 || sz <= i) throw std::out_of_range {"Vector::operator[]"};
        return elem[i];
    }
    inline T at(int i){
        if (i < 0 || sz <= i) throw std::out_of_range {"Vector::operator[]"};
        return elem[i];
    }
    void swap(vector<T> &b);
    // void assign(int &i,T &value);
    // void assign(vector<T>::iterator &start,vector<T>::iterator &end);
    // void assign (std::initializer_list<T> &it);
    void push_back(T &a);
    void push_back(T &&a);
    T& front(){return elem[0];}
    T& back(){return elem[sz-1];}
    T* data(){if(sz==0) return nullptr;else return elem;};
    vector<T>& operator=(vector<T> &b);
    inline void clear(){delete []elem;sz=0;}
    inline int size() const { return sz; }


    
};

template<class T> void vector<T>::swap(vector<T> &b){
    int temp=b.sz;
    T *tempelem=b.elem;
    b.sz=sz;
    b.elem=elem;
    sz=temp;
    elem=tempelem;
}

template<class T> vector<T>::vector(const vector<T>& b) // copy konstruktorius
: sz{b.sz}, // inicializuojame sz
elem{new T[b.sz]} // išskiriame atmintį elem
{
for (int i=0; i!=sz; ++i) // nukopijuojame elementus
elem[i] = b.elem[i];
}

template<class T> vector<T>& vector<T>::operator=(vector<T> &b){
    if (&b == this) return *this;
    T* p = new T[b.sz];
    for (int i=0; i!=b.sz; ++i) // nukopijuojame v elementus
    p[i] = b.elem[i];
    delete[] elem; // atlaisviname seną atmintį!
    elem = p; // elem point'ina į naują atmintį
    sz = b.sz; // atnaujiname size
    return *this;
}

template <class T> void vector<T>::push_back(T &a){
    if(sz==0){
        sz++;
        elem=new T[sz];
        elem[sz-1]=a;
    }
    else{
        sz++;
        T * temp=new T[sz];
        for(int i=0;i<(sz-1);i++){
            temp[i]=elem[i];
        }
        temp[sz-1]=a;
        delete []elem;
        elem=temp;
    }
    
}
template <class T> void vector<T>::push_back(T &&a){
    if(sz==0){
        sz++;
        elem=new T[sz];
        elem[sz-1]=a;
    }
    else{
        sz++;
        T * temp=new T[sz];
        for(int i=0;i<(sz-1);i++){
            temp[i]=elem[i];
        }
        temp[sz-1]=a;
        delete []elem;
        elem=temp;
    }
}


#endif