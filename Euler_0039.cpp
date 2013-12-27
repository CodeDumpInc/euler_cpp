#include <iostream>
#include <algorithm>
#include <map>

int main(){

	//key: p, value: # solutions to a+b+c=p, r.t. a^2+b^2 = c^2
	std::map<int,int> solution_count;

	//a is one side of the triangle
	//b is the second side
	//c is derived from the other ones
	int max_p = 1000;
	for( int a = 1; a <= max_p; ++a){
		for( int b = 1; b < a; ++b){
			int c = static_cast<int>(sqrt(a*a + b*b));
			//we're only interested in integer solutions
			if( ((a*a) + (b*b)) != (c*c) ){
				continue;
			}
			int p = a+b+c;
			if( p > max_p ){
				continue;
			}
			if( p <= 1000){
				++solution_count[p];
			}
		}
	}

	std::map<int,int>::const_iterator it = solution_count.cbegin();
	int p_solution = 0;
	int p_solution_count = 0;
	for( ; it != solution_count.cend(); ++it){
		if( (*it).second > p_solution_count ){
			p_solution_count = (*it).second;
			p_solution = (*it).first;
		}
	}

	std::cout << p_solution << std::endl;

	return 0;
}