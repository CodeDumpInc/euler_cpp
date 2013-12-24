#ifndef _EULER_DIGITS_H
#define _EULER_DIGITS_H

#include <cmath>

int get_num_digits( int n ){
	if( n == 0 ){
		return 1;
	}
	return static_cast<int>(log10(n)+1);
}

int get_ith_digit( int n, int i){

	if( i < 0) return -1;
	int k = get_num_digits( n );
	if( i >= k) return -1;

	int upper_exp = static_cast<int>(std::ceil(std::pow(10, k-i)));
	int lower_exp = static_cast<int>(std::ceil(std::pow(10, k-i-1)));
	
	return (n % upper_exp - n % lower_exp)/lower_exp;	
}

#endif