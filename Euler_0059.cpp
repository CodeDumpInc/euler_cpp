#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>

unsigned int wordcount( const std::string &text, const std::vector<std::string> &words){

	unsigned int result = 0;

	std::vector<std::string>::const_iterator word_iter = words.begin();
	for( ; word_iter != words.cend(); ++word_iter)
	{
		if( text.find(*word_iter) != text.npos )
		{
			++result;
		}
	}

	return result;
}

int main(){

	std::ifstream cipherFile("data/cipher1.txt");
	if(!cipherFile.is_open())
	{
		std::cout << "Error" << std::endl;
	}

	std::stringstream cipherBuffer;
	cipherBuffer << cipherFile.rdbuf();
	std::string cipherString = cipherBuffer.str();
	
	std::string text;

	std::string::const_iterator char_start = cipherString.cbegin();
	std::string::const_iterator char_current = cipherString.cbegin();

	std::string character;
	for( ;char_current != cipherString.cend(); ++char_current) {
		//skip comma, begin next char
		if( *char_current == ',' ) {
			text.push_back( atoi(character.c_str()) );
			character.clear();
			char_start = char_current;
			continue;
		}

		//next char
		character.push_back(*char_current);
	}

	text.push_back( atoi(character.c_str()) );

	std::vector<std::string> words;
	words.push_back("we");
	words.push_back("they");
	words.push_back("you");
	words.push_back("and");
	words.push_back("this");
	words.push_back("that");
	words.push_back("for");
	words.push_back("when");
	words.push_back("at");

	bool found = false;

	char key[3];
	for(key[0] = 97; key[0] < 127; ++key[0]){
		if(found){
			break;
		}
		for(key[1] = 97; key[1] < 127; ++key[1]){
			if(found){
				break;
			}
			for(key[2] = 97; key[2] < 127; ++key[2]){
				std::string plaintext = text;

				int i = 0;
				int result = 0;
				bool print = true;
				std::string::iterator plaintext_iter = plaintext.begin();

				for(;plaintext_iter!=plaintext.end();++plaintext_iter){
					*plaintext_iter ^= key[i];
					i = (i+1)%3;
					result += *plaintext_iter;
				}

				if( wordcount(plaintext, words) > 5 ){
					std::cout << plaintext << std::endl << std::endl; 
					std::cout << result << std::endl;
					found = true;
					break;
				}
			}
		}
	}

	return 0;
}