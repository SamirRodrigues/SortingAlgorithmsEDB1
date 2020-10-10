#include <iostream>
#include <chrono>
#include <fstream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

#include "../include/sorting.h"
#include "../include/generic.h"

using namespace sa;
using namespace ge;

int main( void )
{

    std::ofstream file ("selectionSortRandomElem.dat");

    value_type incrementeValue = 40000;
    value_type baseValue = 1010000;

    value_type times = 25;

    std::srand(std::time(0)); //use current time as seed for random generator

    int * A = NULL;
    A = new int[1010000];
        

    value_type target = -1;

    
    for (size_t i = 0; i <= 25; i++)
    {

        std::cout << ">>> Creating a array with size " << (baseValue-(incrementeValue * (times - i))) << ", please WAIT.... <<<\n";

        for (size_t j = 0; j < (baseValue-(incrementeValue * (times - i))); j++)
        {
            A[j] = std::rand()%1000;
            //std::cout << A[i] << std::endl;
        }

        std::cout << ">>> STARTING computation that needs timing, please WAIT.... <<<\n";    
    
        auto start = std::chrono::steady_clock::now();
        //================================================================================

                        /* PUT THE CODE WHO WILL BE TESTED HERE */

        selectionSort( A, A+(baseValue-(incrementeValue * (times - i))) );

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

    }    
    
    

    file.close();

    delete [] A;
    
    return EXIT_SUCCESS;
}