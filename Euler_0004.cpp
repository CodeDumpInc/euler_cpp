#include <iostream>
#include <cmath>

#include "Euler_Digits.hpp"

bool is_palindrome( int n ){
	int k = get_num_digits( n );

	for( int i=0; i < k/2; ++i){
		if(  get_ith_digit( n, i ) != get_ith_digit( n, k-1-i ) )
			return false;
	}
	return true;
}

int main(int argc, char* argv[]){
	
	int max = 0;
	for(int a=100; a<1000; ++a){
		for(int b=100; b<1000; ++b){
			int prod = a*b;
			if( is_palindrome( prod ) ){
				max = (prod > max ) ? prod : max;
			}
		}
	}
	std::cout << max << std::endl;

	return 0;
}