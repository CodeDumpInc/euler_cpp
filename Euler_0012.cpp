#include <iostream>
#include "Euler_Primes.hpp"

int is_prime_factor( int n, int f ){
	return ( n % f == 0 && is_prime( f ) );
}

/* http://en.wikipedia.org/wiki/Divisor_function */
int num_divisors( int n ){
	int dn = 1;

	int curr_factor = -1;
	int curr_exp = -1;
	while(n>1){
		for( int i=2; i <= n; ++i ){
			//found a prime factor
			if( is_prime_factor( n, i ) ){
				//it's a new one, start counting occurences
				if( curr_factor != i ){
					int add = (curr_exp == -1 ) ? 2 : 1;
					dn *= (curr_exp+add);
					curr_factor = i;
					curr_exp = 1;
				}
				//same one, increment occurence counter
				else ++curr_exp;

				n /= i;
				i = 1;
			}
		}
	}
	
	return dn*(curr_exp+1);
}

int main(int argc, char** argv){

	int triangle_number = 1;
	int i = 1;

	while( num_divisors( triangle_number ) <= 500 ){
		++i;
		triangle_number += i;
	}

	std::cout << triangle_number << std::endl;

	return 0;
}
