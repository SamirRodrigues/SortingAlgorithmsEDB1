/*!
 * A simple implementation of generic algorithms for array of integers:
 * 
 * \author Samir Rodrigues
 * \date 09/10/2020.
 */

#ifndef GENERIC_H
#define GENERIC_H

/// Generic Functions
namespace ge {

    /// SwapValues
    void swap(int* elementA, int* elementB);

    ///PrintArray
    void printArray(int* first, int* last);

    void printArray(int arr[], int n);
}

#endif // GENERIC_H