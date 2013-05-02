#include <iostream>
#include <cstdio>

#include "Euler_Primes.hpp"

int main(int argc, char* argv[]){
	
	long long n=2;
	long long result=0;
	while( n < 2000000){
		if( is_prime( n ) )
			result += n;
		++n;
	}
			
	std::cout << result << std::endl;
	
	getchar();
	return 0;
}