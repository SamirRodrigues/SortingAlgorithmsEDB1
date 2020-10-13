#include <iostream>
#include <chrono>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <string>
#include <iomanip>

#include "../include/sorting.h"
#include "../include/generic.h"

using namespace sa;
using namespace ge;

int main( void )
{

    

    

    value_type incrementeValue = 4000;
    value_type baseValue = 101000;

    value_type times = 25;

    std::srand(std::time(0)); //use current time as seed for random generator

    int * A = NULL;
    A = new int[baseValue]; 

    value_type target = -1;

    /*
    //25/50/75% ordenado?
    int temp;
    for (size_t j = 0; j < baseValue; j++)
    {
            A[j] = j;   
    }
    for (size_t k = 0; k < ((3/4) * (baseValue-(incrementeValue * (times - i)))); k+=2)
    {
        temp = A[k];
        A[k] = A[k+1];
        A[k+1] = temp;
    }
    */
    
    /*
    // no decresse and no incresse
    for (size_t j = 0; j < (baseValue-(incrementeValue * (times - i))); j++)
    {
        if (j < (baseValue-(incrementeValue * (times - i)))/5)
        {
            A[j] = 1;
        }
        else if (j >= (baseValue-(incrementeValue * (times - i)))/5 && j < 2 * (baseValue-(incrementeValue * (times - i)))/5)
        {
            A[j] = 2;
        }else if (j >= 2 * (baseValue-(incrementeValue * (times - i)))/5 && j < 3 * (baseValue-(incrementeValue * (times - i)))/5)
        {
            A[j] = 3;
        }
        else if (j >= 3 * (baseValue-(incrementeValue * (times - i)))/5 && j < 4 * (baseValue-(incrementeValue * (times - i)))/5)
        {
            A[j] = 4;
        }
        else if (j >= 4 * (baseValue-(incrementeValue * (times - i)))/5 && j < baseValue-(incrementeValue * (times - i)))
        {
            A[j] = 5;
        }
    }
    */
    
    /*
    //Random elements
    for (size_t j = 0; j < (baseValue-(incrementeValue * (times - i))); j++)
    {
        A[j] = std::rand()%1000;
        //std::cout << A[i] << std::endl;
    }
    */
    
    /*
    //constante
    for (size_t j = 0; j < baseValue; j++)
    {
            A[j] = 1;   
    }
    */
    int temp;
    
    for (size_t j = 0; j < baseValue; j++)
    {
            A[j] = j;   
    }

    float p = 0.25f;
    
    for (size_t l = 1; l < 4; l++)
    {
        

        std::ofstream file ("radixSort"+std::to_string(l*25)+".dat");
        
        for (size_t i = 0; i <= 25; i++)
        {

            std::cout << ">>> Creating a array with size " << (baseValue-(incrementeValue * (times - i))) << ", please WAIT.... <<<\n";
            
        
            for (size_t k = 0; k < ((p*l) * (baseValue-(incrementeValue * (times - i)))); k+=2)
            {
                temp = A[k];
                A[k] = A[k+1];
                A[k+1] = temp;
            }

            std::cout << ">>> STARTING computation that needs timing, please WAIT.... <<<\n";    
        
            auto start = std::chrono::steady_clock::now();
            //================================================================================

                            /* PUT THE CODE WHO WILL BE TESTED HERE */

            radixSort( A, A+(baseValue-(incrementeValue * (times - i))) );

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

            file << (baseValue-(incrementeValue * (times - i))) << "\t\t" << std::chrono::duration <double, std::milli> (diff).count() << std::endl;

        }    
    
        file.close();

    }
    delete [] A;
    
    return EXIT_SUCCESS;
}