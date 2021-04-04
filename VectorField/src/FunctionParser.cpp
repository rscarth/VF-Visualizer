#include "FunctionParser.hpp"

#include <regex>

//f(x,y,z) = <1,1,z>+

namespace parser {
	//Takes in Function from config.json and dimension count <2,3>
	int* parse(std::string& s, const int& d, int& err) {
		std::string* functions = new std::string[d];
		int dimCount;

		if (s[0] == 'f') {
			for (int i = 1; i < s.length(); i++) {

			}
		} else {
			std::cout << "Invalid function format";
		}

	}
}