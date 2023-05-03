class ReverseIterator
{
public:
    ReverseIterator(int* ptr) : m_ptr(ptr) {}
    
    ReverseIterator& operator++() // prefix increment operator
    {
        --m_ptr;
        return *this;
    }
    
    ReverseIterator operator++(int) // postfix increment operator
    {
        ReverseIterator temp(*this);
        --m_ptr;
        return temp;
    }
    void operator=(ReverseIterator &other){
        m_ptr=other.m_ptr;
    }
    
    int& operator*() const // dereference operator
    {
        return *m_ptr;
    }
    
    bool operator==(const ReverseIterator& other) const // equality operator
    {
        return m_ptr == other.m_ptr;
    }
    
    bool operator!=(const ReverseIterator& other) const // inequality operator
    {
        return !(*this == other);
    }
    
private:
    int* m_ptr;
};