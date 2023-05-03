#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
#include<iostream>
#include<limits>
#include<typeinfo>
#include<string>
// #include<memory>
// #include<algorithm>
// #include"reverse_iterator.h"

using std::cout;
using std::endl;
using std::max;

template <class T>
class vector{
    private:
    int sz;//size
    int cap;//capacity
    T *elem;
    T* it; //iteratorius
    // ReverseIterator rit;
    
    public:
    // typedef T* iterator;
    // typedef const T* const_iterator;
    //constructors-----------------------------------------------------------
    vector(): sz(0),cap(0),elem(nullptr){};
    vector(int s, T val) : sz(s), elem(new T[s]),cap(s) { std::fill_n(elem, s, val); }
    vector(const vector& b);
    vector(std::initializer_list<T> list):sz(list.size()),elem(new T[list.size()]){int i=0;for(auto &list_elem :list){elem[i]=list_elem;i++;};}
    //-----------------------------------------------------------------------
    void reserve(int &n);
    void reserve(int &&n){int a=n;reserve(a);}
    void shrink_to_fit();
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
    void resize(int &i);
    void resize(int &&i){int l=i;resize(l);}
    void push_back(T &a);
    void push_back(T &&a){T temp=a;push_back(temp);}
    inline void pop_back(){elem[sz-1]=T{};sz--;}
    T& front(){return elem[0];}
    T& back(){return elem[sz-1];}
    T* data(){if(sz==0) return nullptr;else return elem;};
    vector<T>& operator=(vector<T> &b);
    inline void clear(){delete []elem;sz=0;}
    inline int capacity() const { return cap; }
    inline int size() const{return sz;}
    inline int capacity() { return cap; }
    inline int size() {return sz;}
    inline bool empty(){if(sz==0)return true;else return false;}
    inline T* begin(){return elem;}
    inline T* end(){return elem+sz;}
    inline const T* cbegin(){return elem;}
    inline const T* cend(){return elem+sz;}
    ~vector(){delete[]elem;cap=0;sz=0;}
    //reverse iterator-----------------------------------------------------
    class reverse_iterator
{
public:
    reverse_iterator(int* ptr) : m_ptr(ptr) {}
    
    reverse_iterator& operator++() // prefix increment operator
    {
        --m_ptr;
        return *this;
    }
    
    reverse_iterator operator++(int) // postfix increment operator
    {
        reverse_iterator temp(*this);
        --m_ptr;
        return temp;
    }
    void operator=(T* other){
        m_ptr=other;
    }
    
    int& operator*() const // dereference operator
    {
        return *m_ptr;
    }
    
    bool operator==(const reverse_iterator& other) const // equality operator
    {
        return m_ptr == other.m_ptr;
    }
    
    bool operator!=(const reverse_iterator& other) const // inequality operator
    {
        return !(*this == other);
    }
    
    
    T* m_ptr;
    };
    //-------------------------------------------------------------------------
    //iterator ----------------------------------------------------------------
    class iterator{
        public:
        iterator(T* ptr) : m_ptr(ptr) {}
        T* m_ptr;
        iterator& operator++() // prefix increment operator
    {
        ++m_ptr;
        return *this;
    }
    
    iterator operator++(int) // postfix increment operator
    {
        iterator temp(*this);
        ++m_ptr;
        return temp;
    }
    void operator=(T* other){
        m_ptr=other;
    }
    
    int& operator*() const // dereference operator
    {
        return *m_ptr;
    }
    
    bool operator==(const iterator& other) const // equality operator
    {
        return m_ptr == other.m_ptr;
    }
    
    bool operator!=(const iterator& other) const // inequality operator
    {
        return !(*this == other);
    }
    };
    //------------------------------------------------------------------------

    
};

template<class T> void vector<T>::swap(vector<T> &b){
    int tempsz=b.sz;
    int tempcap=b.cap;
    T *tempelem=b.elem;
    b.sz=sz;
    b.elem=elem;
    b.cap=cap;
    sz=tempsz;
    elem=tempelem;
    cap=tempcap;
}

template<class T> vector<T>::vector(const vector<T>& b) // copy konstruktorius
: sz{b.sz},cap{b.cap}, // inicializuojame sz
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
    cap=b.cap;
    return *this;
}

template <class T> void vector<T>::push_back(T &a){
    if(sz==cap){
        // cout<<"B\n";
        int newcap=cap == 0 ? 1 : cap * 2;
        // cout<<newcap<<endl;
        T* temp=new T[newcap];
        for(int i=0;i<sz;i++){
            temp[i]=elem[i];
        }
        delete[]elem;
        elem=temp;
        cap=newcap;
    }
    elem[sz]=a;
    sz++; 
}

template<class T> void vector<T>::resize(int &i){
    // int temp_sz=sz;
    // sz=i;
    // T *temp=new T[i];
    // if(temp_sz!=0){
    //     for(int i=0;i<temp_sz;i++){
    //     temp[i]=elem[i];
    // }
    // }
    // delete[]elem;
    // if(typeid(i)==typeid(int)||typeid(i)==typeid(double)||typeid(i)==typeid(float))for(int i=temp_sz;i<sz;i++)temp[i]=0;
    // elem=temp;
    if(i<=sz){
        sz=i;
        return;
    }
    if(i>cap){
        cap=i;
        T* temp=new T[i];
        for (int j=0;j<sz;j++){
            temp[j]=elem[j];
        }
        std::fill(temp+sz,temp+cap,T{});
        delete[] elem;
        elem=temp;
    }
    else{
        std::fill(elem+sz,elem+i,T{});
    }
    sz=i;
}

template<class T>void vector<T>::reserve(int &n){
    if(n>cap){
        T* temp=new T[n];
        for(int i=0;i<sz;i++)temp[i]=elem[i];
        delete[]elem;
        elem=temp;
        cap=n;
    }
}

template<class T>void vector<T>::shrink_to_fit(){
    cap=sz;
    T* temp=new T[sz];
    for(int i=0;i<sz;i++){
        temp[i]=elem[i];
    }
    delete[]elem;
    elem=temp;
}



#endif