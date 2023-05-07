#include <iostream>
#include <string>
#include "../vector.h"
#include<cassert>
using std::cout;

template<class Os, class Co>
Os& operator<<(Os& os, Co& co)
{
    os << "{";
    for (auto& i : co)
        os << ' ' << i;
    return os << " } ";
}
template<typename T>
void print2(T & xs)
{
    std::cout << "[ ";
    for(auto & x : xs) {
        std::cout << x << ' ';
    }
    std::cout << "]\n";
}
void print_container(vector<int>& c) 
{
    for (int i : c)
        std::cout << i << " ";
    std::cout << '\n';
}

 void print1(int id,vector<int>& container)
{
    std::cout << id << ". ";
    for (int x: container)
        std::cout << x << ' ';
    std::cout << '\n';
}
int main()
{
    vector<int> container{1, 2, 3};
 
    auto print = [](int& n) { std::cout << " " << n; };
    cout<<"CLEAR:\n";
    std::cout << "Before clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
 
    std::cout << "Clear\n";
    container.clear();
 
    std::cout << "After clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << ", Capacity=" << container.capacity() << '\n';
    cout<<"INSERT:\n";
    vector<int> c1(3, 100);
    print1(1, c1);
 
    auto it = c1.begin();
    it = c1.insert(it, 200);
    print1(2, c1);
 
    c1.insert(it, 2, 300);
    print1(3, c1);
 
    // `it` no longer valid, get a new one:
    it = c1.begin();
 
    vector<int> c2(2, 400);
    c1.insert(std::next(it, 2), c2.begin(), c2.end());
    print1(4, c1);
 
    int arr[] = {501, 502, 503};
    c1.insert(c1.begin(), arr, arr + std::size(arr));
    print1(5, c1);
 
    c1.insert(c1.end(), {601, 602, 603});
    print1(6, c1);
    cout<<"ERASE:\n";
    vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_container(c);
 
    c.erase(c.begin());
    print_container(c);
 
    c.erase(c.begin() + 2, c.begin() + 5);
    print_container(c);
 
    // Erase all even numbers
    for (vector<int>::iterator it = c.begin(); it != c.end();)
    {
        if (*it % 2 == 0)
            it = c.erase(it);
        else
            ++it;
    }
    print_container(c);
    cout<<"POP_BACK:\n";
    vector<int> numbers;
 
    print2(numbers); 
 
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(4);
 
    print2(numbers); 
 
    numbers.pop_back();
 
    print2(numbers);
    cout<<"RESIZE:\n";
    vector<int> resize = {1, 2, 3};
    std::cout << "The vector holds: ";
    for (auto& el: resize)
        std::cout << el << ' ';
    std::cout << '\n';
 
    resize.resize(5);
    std::cout << "After resize up to 5: ";
    for (auto& el: resize)
        std::cout << el << ' ';
    std::cout << '\n';
 
    resize.resize(2);
    std::cout << "After resize down to 2: ";
    for (auto& el: resize)
        std::cout << el << ' ';
    std::cout << '\n';
 
    resize.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    for (auto& el: resize)
        std::cout << el << ' ';
    std::cout << '\n';
    cout<<"SWAP\n";
    vector<int> a1{1, 2, 3}, a2{4, 5};
 
    auto it1 = std::next(a1.begin());
    auto it2 = std::next(a2.begin());
 
    int& ref1 = a1.front();
    int& ref2 = a2.front();
 
    std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
    a1.swap(a2);
    std::cout << a1 << a2 << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';
}