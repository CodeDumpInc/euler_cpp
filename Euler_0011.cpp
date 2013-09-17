#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]){

	int grid[400];

	//read grid
	std::ifstream grid_file("data/11.txt", std::ios::in);
	std::string line;
	int i=0;
	while( std::getline( grid_file, line) ){
		std::stringstream line_reader(line);
		for( int j=0; j < 20; ++j){
			line_reader >> grid[j+i*20];
  		}
		++i;
	}

	//find maximum product
	unsigned int max_product = 0;
	for(int x = 0; x < 20; x++){
		for(int y = 0; y < 20; y++){
			unsigned int product_x = 0;
			unsigned int product_y = 0;
			unsigned int product_xy = 0;
			unsigned int product_yx = 0;

			int base = grid[y*20 + x];
		
			//horizontally
			if( x <= 16 ){
				product_x = base * grid[y*20 + x + 1] * grid[y*20 + x + 2] * grid[y*20 + x + 3];
				if( product_x > max_product ) max_product = product_x;
			}
			//vertically
			if( y <= 16 ){
				product_y = base * grid[(y+1)*20 + x] * grid[(y+2)*20 + x] * grid[(y+3)*20 + x];
				if( product_y > max_product ) max_product = product_y;
			}
			//diagonal down
			if( x <= 16 && y <= 16 ){
				product_xy = base * grid[(y+1)*20 + x + 1] * grid[(y+2)*20 + x + 2] * grid[(y+3)*20 + x + 3];
				if( product_xy > max_product ) max_product = product_xy;
			}		
			//diagonal up
			if( x >= 3 && y <= 16 ){
				product_yx = base * grid[(y+1)*20 + x - 1] * grid[(y+2)*20 + x - 2] * grid[(y+3)*20 + x - 3];
				if( product_yx > max_product ) max_product = product_yx;
			}
		}
	}

	std::cout << max_product << std::endl;
	return 0;
}
