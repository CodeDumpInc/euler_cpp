#include <iostream>
#include <cstdio>

#include "Euler_Primes.hpp"

int main(int argc, char* argv[]){
	
	long long int number = 600851475143;
	int max = -1;

	int i=2;
	while( number > 1 ){
		if( is_prime(i) && number % i == 0) {
			number = number / i; 
			if( i > max ) max = i;
			i=2;
		}
		else ++i;
	}

	std::cout << max << std::endl;
	getchar();

	return 0;
}