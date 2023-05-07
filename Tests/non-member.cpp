#include <algorithm>
#include <iostream>
#include "../vector.h"
#include <iostream>
#include <numeric>
#include <string_view>
 
 void print_container(std::string_view comment,vector<char>& c)
{
    std::cout << comment << "{ ";
    for (auto x : c)
        std::cout << x << ' ';
    std::cout << "}\n";
}
int main()
{
    cout<<"COMPARISON_OPERATORS:\n";
    vector<int> alice{1, 2, 3};
    vector<int> bob{7, 8, 9, 10};
    vector<int> eve{1, 2, 3};
 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << '\n';
    std::cout << "alice != bob returns " << (alice != bob) << '\n';
    std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
    std::cout << "alice != eve returns " << (alice != eve) << '\n';
    std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
    auto print = [](int& n) { std::cout << ' ' << n; };
 
    // Print state before swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';
 
    std::cout << "-- SWAP\n";
    std::swap(alice, bob);
    cout<<"B\n";
 
    // Print state after swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';
    cout<<"STD::SWAP\n";
    // auto print = [](const int& n) { std::cout << ' ' << n; };
 
    // Print state before swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';
 
    std::cout << "-- SWAP\n";
    std::swap(alice, bob);
 
    // Print state after swap
    std::cout << "alice:";
    std::for_each(alice.begin(), alice.end(), print);
    std::cout << "\n" "bob  :";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << '\n';
    cout<<"ERASE AND ERASE_IF:\n";
    vector<char> cnt(10);
    std::iota(cnt.begin(), cnt.end(), '0');
    print_container("Initially, cnt = ", cnt);
 
    erase(cnt, '3');
    print_container("After erase '3', cnt = ", cnt);
 
    auto erased = erase_if(cnt, [](char x) { return (x - '0') % 2 == 0; });
    print_container("After erase all even numbers, cnt = ", cnt);
    std::cout << "Erased even numbers: " << erased << '\n';
}