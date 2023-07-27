#include "myvector.h"
bool Thing::verbose = false;
size_t Thing::last_alloc = 0;

/**
 * @brief MyVector::MyVector Construct a vector with size 0
 *
 * Remember that the data pointer should point to nothing, and
 * counter variables should be initialised.
 */
MyVector::MyVector()
{
    data = nullptr;
    n_items = 0;
    n_allocated = 0;
}

/**
 * @brief MyVector::~MyVector Free any memory that you have allocated do this last
 */
MyVector::~MyVector()
{
    // Do this last - if you have an error in your destructor it can crash your program
    delete[] data;
}

/**
 * @brief MyVector::size
 * @return The number of items in the vector
 */
size_t MyVector::size() const
{
    return n_items;
}

/**
 * @brief MyVector::allocated_length
 * @return The length of the allocated data buffer
 */
size_t MyVector::allocated_length() const
{
    return n_allocated;
}

/**
 * @brief MyVector::push_back
 * @param t The thing to add
 *
 * Add a thing to the back of the vector.
 * Remember to check if there is enough space to insert it first.
 * If there is not enough space, then you should reallocate the buffer
 * and copy each thing across. When expanding the buffer, double the
 * allocated size.
 */
void MyVector::push_back(const Thing &t)
{
    if (n_items == n_allocated) {
        if (n_allocated == 0) {
            data = new Thing[1];
            data[0] = t;
            n_items++;
            n_allocated++;
        } else {
            reallocate(n_allocated * 2);
            data[n_items] = t;
            n_items++;
        }
    } else {
        data[n_items] = t;
        n_items++;
    }
}


/**
 * @brief MyVector::pop_back
 * Remove the last item from the back.
 * Reallocate with half the space if less than a quarter of the vector is used.
 */
void MyVector::pop_back()
{
    n_items--;
    if (n_items < n_allocated / 4) {
        reallocate(n_allocated / 2);
    }
}

/**
 * @brief MyVector::front
 * @return A reference to the first item in the array.
 * I will never call this on an empty list.
 */
Thing &MyVector::front()
{
    return data[0];
}

/**
 * @brief MyVector::back
 * @return A reference to the last item in the array.
 *
 * Note that this might not be the back of the data buffer.
 * I will never call this on an empty list.
 */
Thing &MyVector::back()
{
    return data[n_items - 1];
}

/**
 * @brief MyVector::begin
 * @return A pointer to the first thing.
 */
Thing *MyVector::begin()
{
    if (n_allocated == 0) {
        return nullptr;
    }
    return &data[0];
}

/**
 * @brief MyVector::end
 * @return A pointer to the memory address following the last thing.
 */
Thing *MyVector::end()
{
    if (n_allocated == 0) {
        return nullptr;
    }
    return &data[n_items];
}

/**
 * @brief MyVector::operator []
 * @param i
 * @return A reference to the ith item in the list.
 */
Thing &MyVector::operator[](size_t i)
{
    Thing &temp = data[i];
    return temp;
}

/**
 * @brief MyVector::at
 * @param i
 * @return A reference to the ith item in the list after checking
 * that the index is not out of bounds.
 */
Thing &MyVector::at(size_t i)
{
    if (i < n_items) {
        return data[i];
    } else {
        throw std::out_of_range("Requested index out of bounds.");
    }
}

/**
 * @brief MyVector::reallocate
 * @param new_size
 * Reallocate the memory buffer to be "new_size" length, using new Thing[new_size]
 * Copy all items from the old buffer into the new one.
 * Delete the old buffer using delete[]
 */
void MyVector::reallocate(size_t new_size)
{
    Thing* ptr = new Thing[new_size];
    for (size_t i = 0; i < n_items; i++) {
        ptr[i] = data[i];
    }
    delete[] data;
    data = ptr;
    n_allocated = new_size;
}
