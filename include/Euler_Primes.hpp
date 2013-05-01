#ifndef _HELPERS_PRIMES_H
#define _HELPERS_PRIMES_H

#include "Helpers_Primes.hpp"

bool is_prime(int n ){
	if( n <= 1) return false;
	return ld( n ) == n;
}

#endif