#include <iostream>
#include <cstdio>
#include <cmath>

int main(int argc, char* argv[]){

	int i = 2;
	while(true){
		if( i % 20 == 0 )
			if( i % 19 == 0 )
				if( i % 18 == 0 )
					if( i % 17 == 0 )
						if( i % 16 == 0 )
							if( i % 15 == 0 )
								if( i % 14 == 0 )
									if( i % 13 == 0 )
										if( i % 12 == 0 )
											if( i % 11 == 0 )
												break;
		i+=2;
	}

	std::cout << i << std::endl;

	getchar();
	return 0;
}