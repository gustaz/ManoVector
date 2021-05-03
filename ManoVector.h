#ifndef MANOVECTOR_H
#define MANOVECTOR_H

#include <limits>

template <class containerType>
class ManoVector 
{

private:
	containerType* element;
	int _size, _capacity;

public:
    size_type = std::size_t;

// CONSTRUCTOR
    explicit ManoVector(const allocator_type& alloc = allocator_type());
    explicit ManoVector(size_type n);
        ManoVector(size_type n, const value_type& val,
            const allocator_type& alloc = allocator_type());
    ManoVector(const ManoVector& x);
    ManoVector(const ManoVector& x, const allocator_type& alloc);
    ManoVector(ManoVector&& x);
    ManoVector(ManoVector&& x, const allocator_type& alloc);
    ManoVector(initializer_list<value_type> il,
        const allocator_type& alloc = allocator_type());
    
// DESTRUCTOR
    ~ManoVector() {
        delete[] element;
    }

// OPERATOR=
    ManoVector& operator=(const ManoVector<containerType>& vect); //copy
    ManoVector& operator=(ManoVector&& vect); // move
    
// CAPACITY 

    // size
    int size() const { return _size; }
    // max_size
    size_t max_size() const;
    // resize
    void resize(int new_size);
    // capacity
    int capacity() const { return _capacity; }
    // empty
    bool empty() const;
    // reserve
    void reserve(int new_size);
    // shrink_to_fit
    void shrink_to_fit();
    
};

template <class containerType>
size_t ManoVector<containerType>::max_size() const 
{
    return std::numeric_limits<size_type>::max();
}

template<class containerType>
void ManoVector<containerType>::resize(int new_size) 
{
    if (new_size < 0)
        throw std::exception();
    if (new_size < _size)
        _size = new_size;
    if (new_size > _capacity)
    {
        containerType* temp = new containerType[new_size];

        for (int i = 0; i < _size; i++)
            temp[i] = element[i];

        delete[] element;
        element = temp;
        _capacity = new_size;
    }
}

template <class containerType>
bool ManoVector<containerType>::empty() const 
{
    return (_size == 0);
}

template<class containerType>
void ManoVector<containerType>::reserve(int amt) 
{
    if (_capacity < amt)
        resize(amt);
}

template<class containerType>
void ManoVector<containerType>::shrink_to_fit() 
{
    containerType* temp = new containerType[_size];

    for (int i = 0; i < _size; i++)
        temp[i] = element[i];

    delete[] element;
    element = temp;
    _capacity = _size;
}
#endif