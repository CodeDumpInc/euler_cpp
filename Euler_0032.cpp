#include <iostream>
#include <cmath>
#include <set>
#include <array>

#include "Euler_Digits.hpp"

bool add_digits(unsigned long n, std::array<bool, 10>& digit_table){
	int num_digits = get_num_digits(n);
	for(int i = 0; i < num_digits; ++i){
		int digit = get_ith_digit(n, i);
		if( digit_table[digit] || digit == 0){
			return false;
		}
		else{
			digit_table[digit] = true;
		}
	}
	return true;
}

int main(){

	std::set<unsigned long> products;
	unsigned long result = 0;

	//number of digits total must be 9
	//each part of the identity has at least 1 and at most 7 digits

	//multiplicand has at most 7 digits
	for(unsigned long multiplicand = 1; multiplicand < 10000000; ++multiplicand){
		int multiplicand_digits = get_num_digits(multiplicand);
		//digits of multiplier depends on digits of multiplicand and product (which is not known yet)
		for(unsigned long multiplier = 1; multiplier < static_cast<unsigned long>(pow(10,8-multiplicand_digits)); ++multiplier){
			int multiplier_digits = get_num_digits(multiplier);

			int num_digits = multiplicand_digits + multiplier_digits + 
							 (int) (log10(multiplicand) + log10(multiplier) + 1);

			if( num_digits < 9 ){
				continue;
			}
			if( num_digits > 9 ){
				break;
			}
			unsigned long product = multiplicand * multiplier; 
			std::array<bool, 10> digit_table;
			digit_table.fill(false);

			//add digits to digit table. if a digit was already added, continue to next loop
			if(!add_digits(multiplicand, digit_table)){
				continue;
			}
			if(!add_digits(multiplier, digit_table)){
				continue;
			}
			if(!add_digits(product, digit_table)){
				continue;
			}

			//at this point, there are 9 digits in the identity and each one was added
			//also there was no zero added, so there must be all digits in the sum
			if(products.find(product) == products.end()){
				result += product;
				products.insert(product);
			}
		}
	}

	std::cout << result << std::endl;

	return 0;
}
