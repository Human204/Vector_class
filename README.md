## A reimplementation of c++ std::vector
# Usage
In order for this header file to work, you must compile it with C++20, because of <=> operator

# Working functions
(-) = not implemented

Member functions:

* constructor
* destructor
* operator =
* assign (-)
* assign_range (-)
* get_allocator (-, no allocator is present)

Element access:
* at()
* operator[]
* front()
* back()
* data()

Iterators:
* begin()
* cbegin() (-)
* end()
* cend() (-)
* rbegin()
* crbegin() (-)
* rend()
* crend() (-)

Capacity:
* empty()
* size()
* max_size()
* reserve()
* capacity()
* shrink_to_fit()

Modifiers:
* clear()
* insert()
* insert_range() (-)
* emplace() (-)
* erase()
* push_back()
* emplace_back() (-)
* append_range() (-)
* pop_back()
* resize()
* swap()

Non-member functions:
* operator==
* operator!=
* operator<
* operator<=
* operator>
* operator>=
* operator<=>
* std::swap() (?)
* erase()
* erase_if()
