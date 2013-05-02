#include <iostream>
#include <cstdio>

int main(int argc, char* argv[]){

	for( int c = 0; c < 1000; ++c){
		for( int b = 0; b < c; ++b){
			for( int a = 0; a < b; ++a){
				if( a+b+c == 1000){
					if( a*a+b*b==c*c ){
						std::cout << a*b*c << std::endl;
					}
				}
			}			
		}
	}
	
	getchar();
	return 0;
}