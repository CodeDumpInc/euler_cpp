#include <iostream>

#include "Euler_Digits.hpp"

bool is_increasing(int n){
	int k = get_num_digits(n);
	int d = 0;
	for(int i=1; i<k; ++i){
		d = get_ith_digit(n, i);
		if( d > get_ith_digit(n,i-1) ) {
			return false;
		}
	}
	return true;
}

bool is_decreasing(int n){
	int k = get_num_digits(n);
	int d = 0;
	for(int i=k-1; i>0; --i){
		d = get_ith_digit(n, i);
		if( d < get_ith_digit(n,i-1) ) {
			return false;
		}
	}
	return true;
}

int main(){

	int percentage = 0;
	int count = 0;
	int n = 0;
	while(true){
		if( !is_decreasing(n) && !is_increasing(n) ){
			++count;
			percentage = static_cast<int>(count*100/n);
		}
		if( percentage != 99 ){
			++n;	
		}
		else{
			break;
		}
	}

	std::cout << n << std::endl;

	return 0;
}