#include <cstddef>
#include <iostream>
#include <span>
#include "../vector.h"
 
void pointer_func(const int* p, int size)
{
    std::cout << "data = ";
    for (int i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';
}


int main()
{
    vector<int> data = { 1, 2, 4, 5, 5, 6 };
 
    // Set element 1
    data.at(1) = 88;
 
    // Read element 2
    std::cout << "Element at index 2 has value " << data.at(2) << '\n';
 
    std::cout << "data size = " << data.size() << '\n';
 
    try {
        // Set element 6
        data.at(6) = 666;
    } catch (std::out_of_range const& exc) {
        std::cout << exc.what() << '\n';
    }
 
    // Print final values
    std::cout << "data:";
    for (int elem : data)
        std::cout << " " << elem;
    std::cout << '\n';
    vector<char> letters {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> numbers {2, 4, 6, 8};
 
    std::cout << "Second element: " << numbers[1] << '\n';
 
    numbers[0] = 5;
 
    std::cout << "All numbers:";
    for (auto i : numbers) {
        std::cout << ' ' << i;
    }
    std::cout << '\n';
    if (!letters.empty()){
        std::cout << "The first character is '" << letters.front() << "'.\n";
        std::cout << "The last character is '" << letters.back() << "'.\n";
    }
    vector<int> container{1, 2, 3, 4};
 
    // Prefer container.data() over &container[0]
    pointer_func(container.data(), container.size());
 
}
 
// Since C++20 vector can be used in constexpr context:
#if defined(__cpp_lib_constexpr_vector) and defined(__cpp_consteval)
// Gets the sum of all primes in [0, N) using sieve of Eratosthenes
consteval auto sum_of_all_primes_up_to(unsigned N) {
    if (N < 2) return 0ULL;
 
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
 
    auto propagate_non_primality = [&](decltype(N) n) {
        for (decltype(N) m = n + n; m < is_prime.size(); m += n)
            is_prime[m] = false;
    };
 
    auto sum{0ULL};
    for (decltype(N) n{2}; n != N; ++n) {
        if (is_prime[n]) {
            sum += n;
            propagate_non_primality(n);
        }
    }
    return sum;
 
    
}
static_assert(sum_of_all_primes_up_to(42) == 0xEE);
static_assert(sum_of_all_primes_up_to(100) == 0x424);
static_assert(sum_of_all_primes_up_to(1001) == 76127);
#endif