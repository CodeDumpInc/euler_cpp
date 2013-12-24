#include <iostream>
#include <cmath>

int get_num_digits( int n ){
	if( n == 0 ){
		return 1;
	}
	return log10(n)+1;
}

int get_ith_digit( int n, int i){

	if( i < 0) return -1;
	int k = get_num_digits( n );
	if( i >= k) return -1;

	int upper_exp = std::ceil(std::pow(10, k-i));
	int lower_exp = std::ceil(std::pow(10, k-i-1));
	
	return (n % upper_exp - n % lower_exp)/lower_exp;	
}

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