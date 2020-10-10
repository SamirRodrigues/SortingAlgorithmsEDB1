#include <iostream>   // cout, endl
#include <iterator>   // std::begin(), std::end()
#include <array>      // std

#include "../include/sorting.h"
#include "../include/generic.h"

using namespace ge;

namespace sa {

    /*!
     * Performs a **quick sort** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param pi recieve the resolt of the partition
     */ 
    /* Function to sort an array using quick sort*/
    value_type* partition (value_type* first, value_type* last)  
    {  
        while(first < last) 
        {
            if (*first > *last)  
            {   
                ge::swap(first, last);  // generic.h
            }  
            first++;        
        }       
        
        return (last);  
    }  

    void quickSort(value_type* first, value_type* last)  
    {  
        if (first < last)  
        {  
            auto pi = partition(first, last);   
            
            quickSort(first, pi - 1);  
            quickSort(pi + 1, last);  
        }  
    }   

    /*!
     * Performs a **insection sort** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param header Pointer to the element to be sorted
     * \param value save the value in element to be sorted
     * \param previous Pointer to the previous element in array to be put in the next element
     * \param next Pointer to the next element who gonna recieve the previous element 
     */     
    /* Function to sort an array using insertion sort*/
    void insertionSort(value_type* first, value_type* last)  
    {          
        value_type* header, *previous, *next; 
        value_type value = 0; 
        
        
        header = first;
        
        while(header < last) 
        {  
            previous    = header-1;
            value       = *header;
            next        = previous+1;

            /* Move elements of arr[first...last], that are  
            greater than key, to one position ahead  
            of their current position */
            while (previous >= first && *previous > value) 
            {                  
                *next       = *previous;
                previous    -= 1;  
                next        = previous+1;
            }  

            *(next)     = value;             
            header      += 1;            
        }  
    } 

    /*!
     * Performs a **selection sort** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     */     
    /* Function to sort an array using selection sort*/
    void selectionSort(value_type* first, value_type* last)  
    {  
        value_type* varifier     = first;
        value_type* minValue     = first;

        while(first < last)
        {
            while (varifier < last)
            {
                if(*varifier < *minValue)
                {
                    minValue = varifier;
                }
                varifier +=1;
            }
            
            swap(minValue, first);

            first        += 1;
            varifier     = first;
            minValue     = first;
        }
    }  
  
    /*!
     * Performs a **bubble sort** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param next Pointer to the next element who gonna recieve the previous element 
     * \param varifier Varifier
     */     
    /* Function to sort an array using bubble sort*/
    void bubbleSort(value_type* first, value_type* last)  
    {          
        value_type* varifier     = first;
        value_type* next         = first+1;   
        value_type* count        = first;   
       

        while(count < last)
        {
            do
            {            
                if(*varifier > *next)
                {
                    swap(varifier, next);                    
                }

                varifier    +=1;
                next        +=1;
                
            } while (next < last);

            count        +=1;
            varifier     = first;
            next         = first+1;
        }
    }

    /*!
     * Performs a **shell sort** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param next Pointer to the next element who gonna recieve the previous element 
     * \param varifier Varifier
     */     
    /* Function to sort an array using shell sort*/
    void shellSort(value_type A[], value_type size)  
    {          
        value_type aux, gapIdx, verifier;
        value_type spaceGap = size/2;

        //aux       = recebe a o valor da variável que vai ser comparada seu par no gap, sendo ela a segunda variável dentre o par.
        //gapIdx    = define qual gap vai ser comparado, pois não se pode comparar todos os pares de uma vez.
        //verifier  = variável que auxilia a comparação dos pares
        
        while ( spaceGap > 0 ) // Esse passo define o tamanho do gap;
        {
            gapIdx = spaceGap;
                
                while ( gapIdx < size ) // Esse passo define qual gap vai ser analisado, começando a partir do mais próximo do **first** até o mais próximo do **last**.
                {                    
                    aux         = A[gapIdx]; // Recebe o valor da SEGUNDA variável do subvetor criado a partir do gap 
                    verifier    = gapIdx; // Recebe o idx do par da SEGUNDA variável do gap                    
                    
                    while ( verifier >= spaceGap /*Verifica se já chegou no primeiro gap*/ 
                            && aux < A[verifier-spaceGap] /*Compara se a váriável mais a esquerda(A[verifier-spaceGap]) é maior que a mais a direita (aux) */ )   // Esse passo imita o Insection Sort considerando os gaps
                    {
                        A[verifier] = A[verifier-spaceGap];
                        verifier    = verifier-spaceGap;
                    }   

                    A[verifier] = aux;

                    gapIdx +=1;
                }
            
            spaceGap /= 2; // spaceGap = spaceGap/2;        
        }
        
    }

    /*!
     * Performs a **merge sort** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param next Pointer to the next element who gonna recieve the previous element 
     * \param varifier Varifier
     */     
    /* Function to sort an array using merge sort*/
    
    
    void merge(int * first, int * mid, int * last) 
    { 
        int sizeArray1 = mid - first + 1; 
        int sizeArray2 = last - mid; 

        // Create temp arrays
        int * leftArray = new int[sizeArray1];
        int * rightArray = new int[sizeArray2]; 

        // Copy data to temp arrays L[] and R[]
        for(int i = 0; i < sizeArray1; i++) 
        {
            leftArray[i] = *(first+i); 
        }

        for(int j = 0; j < sizeArray2; j++) 
        {
            rightArray[j] = *(mid+1+j); 
        }

        // Merge the temp arrays back into arr[l..r] 

        // Initial index of first subarray 
        int idxArray1 = 0;

        // Initial index of second subarray 
        int idxArray2 = 0;

        // Initial index of merged subarray 
        int idxFinalArray = 0; 

        while (idxArray1 < sizeArray1 && idxArray2 < sizeArray2) 
        { 
            if (leftArray[idxArray1] <= rightArray[idxArray2])
            { 
                *(first+idxFinalArray) = leftArray[idxArray1]; 
                idxArray1 +=1; 
            } 
            else 
            { 
                *(first+idxFinalArray) = rightArray[idxArray2]; 
                idxArray2 +=1; 
            } 
            idxFinalArray +=1; 
        } 

        // Copy the remaining elements of 
        // L[], if there are any
        while (idxArray1 < sizeArray1)
        { 
            *(first+idxFinalArray) = leftArray[idxArray1]; 
            idxArray1 +=1; 
            idxFinalArray +=1; 
        } 

        // Copy the remaining elements of 
        // R[], if there are any
        while (idxArray2 < sizeArray2) 
        { 
            *(first+idxFinalArray) = rightArray[idxArray2]; 
            idxArray2 +=1; 
            idxFinalArray +=1; 
        }

        delete[] leftArray;
        delete[] rightArray;
    } 
    

    
    void mergeSort(int * first, int * last) 
    { 
        if (first < last) 
        { 
            // Same as (l+r)/2, but avoids
            // overflow for large l and h 
            int * m = first + (last - first) / 2; 

            // Sort first and second halves 
            mergeSort(first, m); 
            mergeSort(m+1, last); 

            merge(first, m, last); 
            printArray(first, last);
        } 
    }
    

    /*!
     * Performs a **radix sort** for `value` in `[first;last)` and returns a pointer to the location of the first occurrence of `value` in the range `[first,last]`, or `last` if no such element is found.
     * \param first Pointer to the begining of the data range.
     * \param last Pointer just past the last element of the data range.
     * \param next Pointer to the next element who gonna recieve the previous element 
     * \param varifier Varifier
     */     
    /* Function to sort an array using radix sort*/
    

    /*
    value_type getMax(value_type * first, value_type * last)
    {
        value_type mx = *first;
        value_type i = 1;

        while (first+i < last)
        {
            if (*(first+i) > mx)
                mx = *(first+i);

            i++;
        }

        return mx;
    }
    

    
    void countSort(value_type *first, value_type * last, value_type exp)
    {
        int n = last - first;

        int * output = new int[n]; // output array
        int i, count[10] = { 0 };

        // Store count of occurrences in count[]
        for (i = 0; i < n; i++)
            count[(*(first+i) / exp) % 10]++;

        // Change count[i] so that count[i] now contains actual
        //  position of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = n - 1; i >= 0; i--) {
            output[count[((first+i) / exp) % 10] - 1] = (first+i);
            count[((first+i) / exp) % 10]--;
        }

        // Copy the output array to arr[], so that arr[] now
        // contains sorted numbers according to current digit
        for (i = 0; i < n; i++)
            *(first+i) = output[i];

        delete[] output;
    }
    

    
    void radixSort(value_type * first, value_type * last)
    {
        // Find the maximum number to know number of digits
        int m = getMax(first, last);
    
        // Do counting sort for every digit. Note that instead
        // of passing digit number, exp is passed. exp is 10^i
        // where i is current digit number
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(first, last, exp);
    }
    */
}
