#include <chrono>
#include <iostream>
#include <cmath>

using namespace std::chrono ;

int frequency_of_primes (int n) {
    int freq=n-1;

    for (int i=2; i<=n; ++i) 
        for (int j=sqrt(i);j>1;--j) 
            if (i%j==0) 
            {
                --freq; 
                break;
            }

    return freq;
}

int main ()
{


    std::cout << "Calculating...\n" ;
    
    auto begin = high_resolution_clock::now() ;
    int f = frequency_of_primes (99999);
    auto end = high_resolution_clock::now() ;

    auto ticks = duration_cast<microseconds>(end-begin) ;

    std::cout << "The number of primes lower than 100,000 is: " << f << '\n' ;
    std::cout << "It took me " << ticks.count() << " microseconds.\n" ;
}