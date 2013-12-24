#include <iostream>
#include <cmath>

#include "Euler_Primes.hpp"

int main(int argc, char* argv[]){

	int i=0;
	int n=1;

	while( i != 10001 ){
		++n;
		if( is_prime( n ) ) ++i;
	}

	std::cout << n << std::endl;
	return 0;
}