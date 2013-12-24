#include <iostream>
#include <cmath>

typedef long long ResultType;

int main(int argc, char* argv[]){

	ResultType sum = 0;	
	for( ResultType a=3; a <= 1000; ++a){
		ResultType r_max = 0;

		ResultType a_ = a-1;
		ResultType b_ = a+1;
		ResultType r;

		for( ResultType n=1 ; n<a*a; ++n ){
			r = (a_ + b_) % (a*a);
			
			if( r > r_max ) 
				r_max = r;
			
			a_ = (a_ * (a-1)) % (a*a);
			b_ = (b_ * (a+1)) % (a*a);
		}

		sum += r_max;
	}
	std::cout << sum << std::endl;	

	return 0;
}
