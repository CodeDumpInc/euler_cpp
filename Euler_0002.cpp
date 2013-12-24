#include <iostream>

int main(int argc, char* argv[]){
	
	int result = 0;
	int a = 1;
	int b = 1;
	int c = a+b;
	while( c < 4000000){
		result += c;
		for(int i=0; i < 3; ++i){
			a = b;
			b = c;
			c = a+b;
		}
	}

	std::cout << result << std::endl;

	return 0;
}