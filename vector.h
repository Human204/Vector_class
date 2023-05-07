#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
#include<iostream>
#include<limits>
#include<typeinfo>
#include<string>
#include<compare>
// #include<memory>
#include<algorithm>

using std::cout;
using std::endl;
using std::max;

template <class T>
class vector{
    private:
    int sz;//size
    int cap;//capacity
    T *elem;
    using value_type=T;
    public:
    //member functions-----------------------------------------------------------
    //constructors
    vector(): sz(0),cap(0),elem(nullptr){};
    vector(int s, T val) : sz(s), elem(new T[s]),cap(s) { std::fill_n(elem, s, val); }
    vector(const vector& b);
    vector(vector<T>&&other);
    vector(std::initializer_list<T> list):sz(list.size()),elem(new T[list.size()]),cap(list.size()){int i=0;for(auto &list_elem :list){elem[i]=list_elem;i++;};}
    vector(T* first,T* last):sz(last-first),cap(last-first),elem(new T[cap]){for(int i=0;i<sz;i++,first++){elem[i]=*first;}}
    vector(int sz2):sz(sz2),cap(sz2),elem(new T[sz2]){}
    vector<T>& operator=(vector<T> &b);
    vector<T>& operator=(const vector<T> &other);
    vector<T>& operator=(vector<T> &&other);
    ~vector(){if(sz!=0)delete[]elem;cap=0;sz=0;}
    //--
    void assign(int count,const T& value);
    void assign(std::initializer_list<T> list);
    //-----------------------------------------------------------------------
    //element access
    T& operator[](int i){
        if (i < 0 || sz <= i) throw std::out_of_range {"Vector::operator[]"};
        return elem[i];
    }
    inline T& at(int &i){
        if (i < 0 || sz <= i) throw std::out_of_range {"Vector::operator[]"};
        return elem[i];
    }
    inline T& at(int &&i){
        int l=i;
        return at(l);
    }
    T& front(){return elem[0];}
    T& back(){return elem[sz-1];}
    T* data(){if(sz==0) return nullptr;else return elem;};
    //------------------------------------------------------------------------ 
    T* operator*(){return elem;} 
    //reverse iterator-----------------------------------------------------
    class reverse_iterator
{
public:
    reverse_iterator(T* ptr) : m_ptr(ptr) {}
    reverse_iterator():m_ptr(nullptr){}
    
    operator T*() const{
            return m_ptr;
        }
    reverse_iterator& operator++()
    {
        --m_ptr;
        return *this;
    }
    
    reverse_iterator operator++(int)
    {
        reverse_iterator temp(*this);
        --m_ptr;
        return temp;
    }
    void operator=(T* other){
        m_ptr=other;
    }
    
    T& operator*() const 
    {
        return *m_ptr;
    }
    
    bool operator==(const reverse_iterator& other) const
    {
        return m_ptr == other.m_ptr;
    }
    
    bool operator!=(const reverse_iterator& other) const
    {
        return !(*this == other);
    }
    T* operator->(){
        return m_ptr;
    }
    
    T* m_ptr;
    };
    //-------------------------------------------------------------------------
    //const_reverse_iterator----------------------------------------------------
    class const_reverse_iterator{
        public:
    const_reverse_iterator(T* ptr) : m_ptr(ptr) {}
    const_reverse_iterator():m_ptr(nullptr){}
    
    operator T*() const{
            return m_ptr;
        }
    reverse_iterator& operator++()
    {
        --m_ptr;
        return *this;
    }
    
    reverse_iterator operator++(int)
    {
        reverse_iterator temp(*this);
        --m_ptr;
        return temp;
    }
    void operator=(T* other){
        m_ptr=other;
    }
    
    const T& operator*() const 
    {
        return *m_ptr;
    }
    
    bool operator==(const reverse_iterator& other) const
    {
        return m_ptr == other.m_ptr;
    }
    
    bool operator!=(const reverse_iterator& other) const
    {
        return !(*this == other);
    }
    const T* operator->(){
        return m_ptr;
    }
    
    
    T* m_ptr;
    };
    //iterator ----------------------------------------------------------------
    class iterator{
        private:
        T* m_ptr;
        public:
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::input_iterator_tag;
        iterator(T* ptr) : m_ptr(ptr) {}
        iterator() :m_ptr(nullptr){}
        iterator(std::__cxx11::basic_string<T>::iterator it):m_ptr(&(*it)){}
        template <class U> iterator(__gnu_cxx::__normal_iterator<T,U> it):m_ptr(&(*it)){}
        operator T*() const{
            return m_ptr;
        }
        
        iterator& operator++(){
        ++m_ptr;
        return *this;
    }
    iterator operator++(int){
        iterator temp(*this);
        ++m_ptr;
        return temp;
        
    }
    iterator operator--(int){
        iterator temp(*this);
        --m_ptr;
        return temp;
    }
    iterator& operator--(){
        --m_ptr;
        return *this;
    }
    iterator operator-(int n) const {
        iterator result(*this);
        result.m_ptr -= n;
        return result;
    }
    iterator operator+(int n) const {
        iterator result(*this);
        result.m_ptr += n;
        return result;
    }
    void operator=(T* other){
        m_ptr=other;
    }
    T& operator*() const {
        return *m_ptr;
    }
    
    bool operator==(const iterator& other) const {
        return m_ptr == other.m_ptr;
    }
    
    bool operator!=(const iterator& other) const {
        return !(*this == other);
    }
    
    bool operator<(const iterator& other){
        return m_ptr<other.m_ptr;
    }
    bool operator<(T* other){
        return m_ptr<other;
    }
    bool operator>(T* other){
        return m_ptr>other;
    }
    T* operator->(){
        return m_ptr;
    }
};
    //const_iterator-----------------------------------------------------------
    class const_iterator{
        private:
        T* m_ptr;
        public:
        // T* m_ptr;
        const_iterator(T* ptr) : m_ptr(ptr) {}
        const_iterator() :m_ptr(nullptr){}
        operator T*() const{
            return m_ptr;
        }
        iterator& operator++(){
        ++m_ptr;
        return *this;
    }
    iterator operator++(int){
        iterator temp(*this);
        ++m_ptr;
        return temp;
        
    }
    iterator operator--(int){
        iterator temp(*this);
        --m_ptr;
        return temp;
    }
    iterator& operator--(){
        --m_ptr;
        return *this;
    }
    void operator=(T* other){
        m_ptr=other;
    }
    const T& operator*() const {
        return *m_ptr;
    }
    
    bool operator==(const iterator& other) const {
        return m_ptr == other.m_ptr;
    }
    
    bool operator!=(const iterator& other) const {
        return !(*this == other);
    }
    
    bool operator<(const iterator& other){
        return *this.m_ptr<other.m_ptr;
    }
    bool operator<(T* other){
        return m_ptr<other;
    }
    bool operator>(T* other){
        return m_ptr>other;
    }
    const T* operator->(){
        return m_ptr;
    }
    };

//iterators
vector<T>::iterator begin(){return iterator(elem);}
vector<T>::const_iterator cbegin(){return const_iterator(elem);}
vector<T>::iterator end(){return iterator(elem+sz);}
vector<T>::const_iterator cend(){return const_iterator(elem+sz);}
vector<T>::reverse_iterator rbegin(){return reverse_iterator(elem+sz-1);}
vector<T>::const_reverse_iterator crbegin(){return const_reverse_iterator(elem+sz-1);}
vector<T>::reverse_iterator rend() {return reverse_iterator(elem-1);}
vector<T>::const_reverse_iterator crend() {return const_reverse_iterator(elem-1);}
//---------------------------------------------------------------------
//capacity
inline bool empty(){if(sz==0)return true;else return false;}
inline bool empty() const{if(sz==0)return true;else return false;}
inline int size() {return sz;}
inline int size() const{return sz;}
T max_size() const{return std::numeric_limits<T>::max();}
void reserve(int &n);
void reserve(int &&n){int a=n;reserve(a);}
inline int capacity() { return cap; }
inline int capacity() const { return cap; }
void shrink_to_fit();
void push_back(T &a);
void push_back(T &&a){T temp=a;push_back(temp);}
inline void pop_back(){elem[sz-1]=T{};sz--;}
void resize(int &i);
void resize(int &&i){int l=i;resize(l);}
void resize(T count,T init);
void swap(vector<T> &b);
//---------------------------------------------------------------------
//modifiers
void clear(){if(sz!=0){delete[]elem,cap=0;sz=0;}}
vector<T>::iterator insert(vector<T>::iterator pos,const T& value);
vector<T>::iterator insert(vector<T>::iterator pos,const T&& value){T m=value; return insert(pos,m);}
vector<T>::iterator insert( vector<T>::iterator pos, T* first, T* last );
vector<T>::iterator insert(vector<T>::iterator pos,int &length,T &value);
vector<T>::iterator insert(vector<T>::iterator pos,int &length,T &&value){T val=value;return insert(pos,length,value);}
vector<T>::iterator insert(vector<T>::iterator pos,int &&length,T &&value){T val=value;int len=length;return insert(pos,len,value);}
vector<T>::iterator insert(vector<T>::iterator pos,std::initializer_list<T> list){T arr[list.size()];std::copy(list.begin(),list.end(),arr);return insert(pos,arr, &arr[sizeof(arr)/sizeof(arr[0])]);}
vector<T>::iterator erase(T* beginning,T* ending);
vector<T>::iterator erase(T* element);
// template<class Args> vector<T>::iterator emplace(vector<T>::iterator pos,Args&& args);
// template<class... Args> vector<T>::iterator emplace_back(Args... args);
//---------------------------------------------------------------------

vector(vector<T>::iterator first,vector<T>::iterator last):sz(last-first),cap(last-first),elem(new T[cap]){for(int i=0;i<sz;i++,first++){elem[i]=*first;}}
void assign(vector<T>::iterator first,vector<T>::iterator last);
template<class U> friend void swap(vector<U>&a,vector<U>&b);
template <typename Pred>
    friend typename vector<T>::iterator find_if(typename vector<T>::iterator first, typename vector<T>::iterator last,  Pred pred) {
        while (first != last) {
            if (pred(*first)) {
                return first;
            }
            ++first;
        }
        return last;
    }
    template <typename Pred>
friend typename vector<T>::iterator find_if(typename vector<T>::iterator first, typename vector<T>::iterator last, Pred pred, std::input_iterator_tag) {
    while (first != last) {
        if (pred(*first)) {
            return first;
        }
        ++first;
    }
    return last;
}
//---------------------------------------------------------------------------- 
};
//member functions-----------------------------------------------------------
template<class T>vector<T>::vector(vector<T>&&other){
    elem=std::move(other.data());
    sz=other.size();
    cap=other.cap;
    other.clear();
    other.shrink_to_fit();
}

template<class T>vector<T>& vector<T>::operator=(vector<T> &&other){
elem=std::move(other.data());
// elem=other.data();
sz=other.size();
cap=other.cap;
other.clear();
other.shrink_to_fit();
return *this;


}

template<class T> vector<T>& vector<T>::operator=(const vector<T> &other){
    if (this == &other) {
        return *this;
    }
    T* p=new T[other.sz];
    for(int i=0;i<other.sz;i++){
        p[i]=other.elem[i];
    }
    delete[]elem;
    elem=p;
    sz=other.sz;
    cap=other.cap;
    return *this;
}

template<class T> vector<T>& vector<T>::operator=(vector<T> &b){
    if (&b == this) return *this;
    T* p = new T[b.sz];
    for (int i=0; i<b.sz; ++i) // nukopijuojame v elementus
    p[i] = b.elem[i];
    delete[] elem; // atlaisviname seną atmintį!
    elem = p; // elem point'ina į naują atmintį
    sz = b.sz; // atnaujiname size
    cap=b.cap;
    return *this;
}
template<class T> vector<T>::vector(const vector<T>& b) // copy konstruktorius
: sz{b.sz},cap{b.cap}, // inicializuojame sz
elem{new T[b.sz]} // išskiriame atmintį elem
{
for (int i=0; i!=sz; ++i) // nukopijuojame elementus
elem[i] = b.elem[i];
}
template<class T> void vector<T>::assign(int count,const T& value){
    if(count>cap){
        cap=count;
        sz=count;
        T* temp=new T[count];
        for(int i=0;i<count;i++){
            temp[i]=value;
        }
        delete[]elem;
        elem=temp;
    }
    else{
        sz=count;
        for(int i=0;i<count;i++){
            elem[i]=value;
        }
    }
}
template<class T> void vector<T>::assign(vector<T>::iterator first,vector<T>::iterator last){
    if((last-first)>cap){
        cap=(last-first);
        sz=cap;
        T* element=first;
        T* temp=new T[sz];
        for(int i=0;i<sz;i++,element++){
            temp[i]=*element;
        }
        delete[]elem;
        elem=temp;
    }
    else{
        T* element=first;
        sz=(last-first);
        for(int i=0;i<sz;i++,element++){
            elem[i]=*element;
        }
    }
}
template<class T> void vector<T>::assign(std::initializer_list<T> list){
    int j=0;
    if(list.size()>cap){
        cap=list.size();
        sz=cap;
        T* temp=new T[cap];
        for(auto &i:list){
            elem[j]=i;
            j++;
        }
        delete[]elem;
        elem=temp;
    }
    else{
        sz=list.size();
        for(auto &i:list){
            elem[j]=i;
            j++;
        }
    }
}
//----------------------------------------------------------------------------
//element access
//---------------------------------------------------------------------
//Iterators
//---------------------------------------------------------------------
//capacity
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
    if(cap!=sz&&sz!=0){
        cap=sz;
        T* temp=new T[cap];
        for(int i=0;i<sz;i++){
            temp[i]=elem[i];
        }
        delete[]elem;
        elem=temp;
    }
}
//---------------------------------------------------------------------
//Modifiers
template<class T> typename vector<T>::iterator vector<T>::insert(vector<T>::iterator pos,const T& value){
    int pos_int=pos-begin();
    sz++;
    if(sz>cap)cap=cap*2;
    T* temp= new T[cap];
    for(int i=0;i<pos_int;i++){
            temp[i]=elem[i];
        }
        temp[pos_int]=value;
        for(int i=pos_int;i<sz;i++){
            temp[i+1]=elem[i];
        }
        delete[]elem;
        elem=temp;
        pos=elem+pos_int;
        return pos;
}

template<class T> typename vector<T>::iterator vector<T>::insert(vector<T>::iterator pos,T* first, T* last){
    int pos_int1,pos_int2,size_diff;
    pos_int1=pos-begin();
    pos_int2=((last-first)+pos)-begin();
    size_diff=last-first;
    int new_sz=sz+size_diff;
    if(new_sz>cap)cap=cap*2;
    T* temp= new T [cap];
    for(int i=0;i<pos_int1;i++){
        temp[i]=elem[i];
    }
    T* element=first;
    for(int i=pos_int1;element<last;i++,element++){
        temp[i]=*element;
    }
    for(int i=pos_int2;i<new_sz;i++){
        temp[i]=elem[i-size_diff];
    }
    delete[]elem;
    elem=temp;
    sz=new_sz;
    pos=elem+pos_int1;
    return pos;
}

template <class T>typename vector<T>::iterator vector<T>::insert(vector<T>::iterator pos,int &length,T &value){
    int insert_index=pos-begin();
    int new_sz=sz+length;
    if(new_sz>cap)cap=cap*2;
    T* temp= new T [cap];
    for(int i=0;i<insert_index;i++){
        temp[i]=elem[i];
    }
    for(int i=insert_index;i<(insert_index+length);i++){
        temp[i]=value;
    }
    for(int i=(insert_index+length);i<new_sz;i++){
        temp[i]=elem[i-length];
    }
    delete[]elem;
    elem=temp;
    pos=elem+insert_index;
    sz=new_sz;
    return pos;
}

template <class T> void vector<T>::push_back(T &a){
    if(sz==cap||cap==0){
        // cout<<"B\n";
        int newcap;
        // int newcap=cap == 0 ? 1 : cap * 2;
        if(cap==0)newcap=1;
        else newcap=cap*2;
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
    // cout<<a<<" "<<sz<<" "<<cap<<" push_back || "<<typeid(a).name()<<"\n"; 
}

template<class T> void vector<T>::resize(int &i){
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
template<class T>void vector<T>::resize(T count,T init){
    if(count<=sz){
        sz=count;
        return;
    }
    if(count>cap){
        cap=count;
        T* temp=new T[count];
        for (int j=0;j<sz;j++){
            temp[j]=elem[j];
        }
        std::fill(temp+sz,temp+cap,T{init});
        delete[] elem;
        elem=temp;
    }
    else{
        std::fill(elem+sz,elem+count,T{init});
    }
    sz=count;
}

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
template<class T>typename vector<T>::iterator vector<T>::erase(T* beginning,T* ending){
    int size_diff,pos1,pos2;
    // pos1=((beginning-begin())/sizeof(T));
    pos1=beginning-begin();
    // pos2=((ending-begin())/sizeof(T));
    pos2=ending-begin();
    size_diff=((ending-beginning));
    // cout<<pos1<<" "<<pos2<<" "<<size_diff<<'\n';
    // T* temp=new T[sz-size_diff];
    T* temp=new T[cap];
    int j=0;
    for(int i=0;i<pos1;i++){
        temp[i]=elem[i];
        // cout<<temp[i]<<" ";
    }
    for(int i=pos2;i<sz;i++){
        temp[i-size_diff]=elem[i];
        // cout<<temp[i]<<" ";
    }
    cout<<endl;
    delete[] elem;
    elem=temp;
    sz-=size_diff;
    vector<T>::iterator ret = elem+sz-pos2-size_diff+1;
    return ret;
}
template<class T>typename vector<T>::iterator vector<T>::erase(T* element){
    T* temp=new T[cap];
    int pos1=element-begin();
    for (int i=0;i<pos1;i++){
        temp[i]=elem[i];
        
    }
    for(int i=pos1+1;i<sz;i++){
        temp[i-1]=elem[i];
    }
    
    delete[] elem;
    elem=temp;
    sz--;
    vector<T>::iterator ret = elem+pos1;
    return ret;
}
// template<class T>template<class Args>typename vector<T>::iterator vector<T>::emplace(vector<T>::iterator pos,Args&& args){
//     ptrdiff_t i=pos-begin();
//     if(sz==cap)reserve(cap*2);
//     sz++;
//     for (ptrdiff_t j = sz - 1; j > i; --j) {
//             elem[j] = std::move(elem[j - 1]);
//         }
//     elem[i]=T{args};    
//     return elem+i;
// }
// template<class T>template<class... Args> typename vector<T>::iterator vector<T>::emplace_back(Args... args){
//     if(sz==cap)reserve(cap*2);
//     // elem[sz]=T{args};
//     // elem[sz]=;
//     new (elem+sz) T(std::forward<Args>(args)...);
//     sz++;
//     return end();
// } 
//---------------------------------------------------------------------
//Non-member functions
//comparison operators
template<class T> bool operator==(vector<T> &first,vector<T> &second){
    if(first.size()!=second.size())return false;
    else{
        for(int i=0;i<first.size();i++){
            if(first[i]!=second[i])return false;
        }
    }
    return true;
}
template<class T> bool operator!=(vector<T> &first,vector<T> &second){
    if(first.size()!=second.size())return true;
    else{
        for(int i=0;i<first.size();i++){
            if(first[i]!=second[i])return true;
        }
    }
    return false;
}
template<class T> bool operator<(vector<T>&first,vector<T>&second){
    if(first==second)return false;
    int size1=first.size(),size2=second.size();
    int for_length=size1;
    // bool check=false;
    if(size2<size1)for_length=size2;
    for(int i=0;i<for_length;i++){
        if(second[i]<first[i])return false;
    }
    if(for_length==size1)return true;
    else return false;
}
template<class T> bool operator>(vector<T>&first,vector<T>&second){
    if(first==second)return false;
    int size1=first.size(),size2=second.size();
    int for_length=size1;
    // bool check=false;
    if(size2>size1)for_length=size2;
    for(int i=0;i<for_length;i++){
        if(second[i]>first[i])return false;
    }
    if(for_length==size1)return false;
    else return true;
}
template<class T> bool operator<=(vector<T>&first,vector<T>&second){
    if(first==second)return true;
    else return first<second;
}
template<class T>bool operator>=(vector<T>&first,vector<T>&second){
    if(first==second)return true;
    else return first>second;
}
template<class T>std::strong_ordering operator<=>(vector<T>&first,vector<T>&second){
    if(first==second)return std::strong_ordering::equal;
    else if(first<second)return std::strong_ordering::less;
    else return std::strong_ordering::greater;
}
template <class T> std::size_t erase(vector<T> &from,T &value){
    size_t erased=0;
    for(int i=0;i<from.size();i++){
        if (from[i]==value){
            from.erase(from.begin()+i);
            erased++;
        }
    }
    return erased;
}

template <class T>std::size_t erase(vector<T> &from,T &&value){T val=value; return erase(from,val);}
template<class T,class Pred> std::size_t erase_if(vector<T> &from,Pred pred){
    size_t erased=0;
    for(int i=0;i<from.size();i++){
        if(pred(from[i])==true){
            from.erase(from.begin()+i);
            erased++;
        }
    }
    return erased;
}
template<class U>void swap(vector<U>&a,vector<U>&b){
    std::swap(a.elem,b.elem);
    std::swap(a.sz,b.sz);
    std::swap(a.cap,b.cap);
}
    
//---------------------------------------------------------------------
#endif