/*!
 * A simple implementation of the following algorithms for array of integers:
 *  + QuickSort
 *  + InsectionSort
 *  + SelectionSort
 *  + BubbleSort
 *  + ShellSort
 *  + MergeSort
 *  + RadixSort
 *
 * \author Samir Rodrigues
 * \date 09/10/2020.
 */

#ifndef SORTING_H
#define SORTING_H

/// Searching Algorithms Namespace
namespace sa {

    /// just an alias for an integer type.
    using value_type = int;

    /// QuickSort Functions
    void quickSort(value_type* first, value_type* last);
    
    value_type* partition (value_type* first, value_type* last);

    /// InsectionSort Functions
    void insertionSort(value_type* first, value_type* last);

    /// SelectionSort Functions
    void selectionSort(value_type* first, value_type* last);

    /// BubbleSort Funtions
    void bubbleSort(value_type* first, value_type* last);

    /// ShellSort Functions
    void shellSort(value_type A[], value_type size);

    /// MergeSort Functions
    void merge(int * first, int * mid, int * last);

    void mergeSort(int first, int * last);

    ///RadixSort Functions

    value_type getMax(int * first, int * last);

    void countSort(value_type *first, value_type * last, value_type exp);

    void radixSort(value_type * first, value_type * last);
  
}

#endif // SORTING_H