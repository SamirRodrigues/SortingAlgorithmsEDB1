#include <iostream>   // cout, endl

namespace ge {
    
    void printArray(int* first, int* last)  
    {  
        while(first < last)
        {
            std::cout << *first << " "; 
            first++;
        }
        std::cout << std::endl;  
    }  

    
    void printArray(int arr[], int n)  
    {  
        int i;  
        for (i = 0; i < n; i++)  
            std::cout << arr[i] << " ";  
        std::cout << std::endl; 
    }  

    void swap(int* elementA, int* elementB)  
    {  
        auto temp = *elementB;  
        *elementB = *elementA;  
        *elementA = temp;  
    }  
}