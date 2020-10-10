#include <iostream>
#include <chrono>
#include <fstream>
#include <iterator>

#include "../include/sorting.h"
#include "../include/generic.h"

using namespace sa;
using namespace ge;

value_type main( void )
{
    //int arr[] = {10, 7, 8, 9, 1, 5};  

    value_type arr[] = {10, 7, 8, 9, 1, 5, 500, 0, 102}; 

    //value_type arr[] = {10, 11, 12, 13, 14, 15, 16, 17, 18}; 

    int n = sizeof(arr) / sizeof(arr[0]);    

    std::cout << "No Sorted array \n";
    printArray(std::begin(arr), std::end(arr)); 

    //shellSort(arr, n);
    //bubbleSort(std::begin(arr), std::end(arr));
    //selectionSort(std::begin(arr), std::end(arr));
    //insertionSort(std::begin(arr), std::end(arr));
    //quickSort(std::begin(arr), std::end(arr)-1);  

    std::cout << "Sorted array: \n";  
    printArray(std::begin(arr), std::end(arr));   

    return EXIT_SUCCESS;
}


/*
int main( void )
{
    std::cout << ">>> Creating a array with size 900.000.000, please WAIT.... <<<\n";

    std::ofstream file ("BSRoutput.dat");

    value_type incrementeValue = 18000000;
    value_type baseValue = 100000000000;

    value_type times = 50;

    int * A = NULL;
    A = new int[1000000000];
    for (size_t i = 0; i < 1000000000; i++)
    {
        A[i] = i;
    }    

    value_type target = -1;

    for (size_t i = 0; i <= 50; i++)
    {
        std::cout << ">>> STARTING computation that needs timing, please WAIT.... <<<\n";    
    
        auto start = std::chrono::steady_clock::now();
        //================================================================================

        auto result = bsearchRecursive( A, A+(baseValue-(incrementeValue * (times - i))), target );

        //================================================================================
        std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
        std::cout << ">>> ENDING computation that needs timing <<<\n";

        //Store the time difference between start and end
        // auto diff = end - start;
        std::chrono::duration<double> diff = end - start;

        // Milliseconds (10^-3)
        //std::cout << "\t\t>>> " <<  std::chrono::duration <double, std::milli> (diff).count();
           // << " ms" << std::endl;

        // Nanoseconds (10^-9)
        //std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count();
            //<< " ns" << std::endl;

        // Seconds
        auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
        std::cout  << i <<" - "<< "\t\t>>> " << diff_sec.count() << " s" << std::endl;

        file << i << "\t\t" << std::chrono::duration <double, std::milli> (diff).count() << std::endl;

        std::cout << result;
    }    
    

    file.close();

    delete [] A;
    
    return EXIT_SUCCESS;
}
*/
