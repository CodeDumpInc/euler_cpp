#ifndef _EULER_PRIMES_H
#define _EULER_PRIMES_H

#include "Euler_Helpers.hpp"

bool is_prime(int n ){
	if( n <= 1) return false;
	return ld( n ) == n;
}

#endif