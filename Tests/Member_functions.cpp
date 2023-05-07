#include "../vector.h"
#include <string>
#include <iostream>

 
void print(auto comment, auto&  container)
{
    auto size = std::size(container);
    std::cout << comment << "{ ";
    for (auto const& element: container)
        std::cout << element << (--size ? ", " : " ");
    std::cout << "}\n";
}

template<typename T>
std::ostream& operator<<(std::ostream& s,vector<T>& v) 
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v)
    {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}
 
int main() 
{
    // C++11 initializer list syntax:
    vector<std::string> words1 {"the", "frogurt", "is", "also", "cursed"};
    std::cout << "words1: " << words1 << '\n';
 
    // words2 == words1
    vector<std::string> words2(words1.begin(), words1.end());
    std::cout << "words2: " << words2 << '\n';
 
    // words3 == words1
    vector<std::string> words3(words1);
    std::cout << "words3: " << words3 << '\n';
 
    // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
    vector<std::string> words4(5, "Mo");
    std::cout << "words4: " << words4 << '\n';
        vector<int> x { 1, 2, 3 }, y, z;
    const auto w = { 4, 5, 6, 7 };
 
    std::cout << "Initially:\n";
    print("x = ", x);
    print("y = ", y);
    print("z = ", z);
 
    std::cout << "Copy assignment copies data from x to y:\n";
    y = x;
    print("x = ", x);
    print("y = ", y);
 
    std::cout << "Move assignment moves data from x to z, modifying both x and z:\n";
    z = std::move(x);
    print("x = ", x);
    print("z = ", z);
 
    std::cout << "Assignment of initializer_list w to z:\n";
    z = w;
    print("w = ", w);
    print("z = ", z);
    
    vector<char> characters;
 
    auto print_vector = [&]()
    {
        for (char c : characters)
            std::cout << c << ' ';
        std::cout << '\n';  
    };
 
    characters.assign(5, 'a');
    print_vector();
 
    std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
    print_vector();
 
    characters.assign({'C', '+', '+', '1', '1'});
    print_vector();
}