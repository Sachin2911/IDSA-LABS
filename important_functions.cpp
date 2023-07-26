#include <iostream>
#include <vector>
#include "important_functions.h"

using namespace std;

int answer(){
    return 42;
}

/**
 * @brief absolute Return the absolute value of the parameter
 * @param value
 * @return
 */
unsigned int absolute(int value)
{
    if (value >= 0) {
        return static_cast<unsigned int>(value);
    } else {
        return static_cast<unsigned int>(-value);
    }
}

/**
 * @brief push_front Add a value to the front of a vector.
 * @param myVector
 * @param value
 */
void push_front(vector<int> &myVector, int value){
    myVector.insert(myVector.begin(), value);
}

/**
 * @brief increment Accept a POINTER to an integer. Increase the value of that integer by 1.
 * @param v
 * @return
 */
void increment(int *v)
{
    (*v)++; // Increment the value pointed to by v by 1
}
