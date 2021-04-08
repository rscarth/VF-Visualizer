#include "FunctionParser.hpp"
#include "Error.hpp"

namespace parser {

	void Parse(const std::string& s, const int& d, std::unordered_map<std::string, int>& vars, std::string* funcs, int& err) {
		unsigned int s_len = s.length();
		std::string temp;
		int c = 0;

		for (unsigned int i = 0; i <= s_len; i++) {
			if (s[i] == '(') {
				i++;
				while (s[i - 1] != ')' && i != s_len) {
					if (s[i] != ',' && s[i] != ')') {
						if (s[i] != ' ') {
							temp += s[i];
						}
					}
					else {
						if (c < d-1) {
							//std::cout << "Inserting (" << temp << ", " << c << ") into map<> vars" << std::endl;
							vars.insert(std::pair<std::string, int>(temp, c));
						}
						else {
							error::printError("More variables than dimensions parsed, check delimiters"), i;
							err = -210;
							break;
						}

						c++;
						temp = "";
					}
					i++;
				}

				if (s[i - 1] != ')') {
					error::printError("No closing bracket found for variables", i);
					err = -211;
					break;
				}

				temp = "";

			}
			else if (s[i] == '<' && c == d) {
				i++;
				while (s[i - 1] != '>' && i != s_len) {
					if (s[i] != ',' && s[i] != '>') {
						if (s[i] != ' ') {
							temp += s[i];
						}
					}
					else {
						if (c < (d * 2)) {
							//std::cout << "Appending " << temp << " to funcs[" << c - d << "]" << std::endl;
							funcs[c - d] = temp;
						}
						else {
							error::printError("More functions than dimensions parsed, check delimeters", i);
							err = -220;
							break;
						}

						c++;
						temp = "";
					}
					i++;
				}

				if (s[i - 1] != '>') {
					error::printError("No closing bracket found for functions", i);
					err = -221;
					break;
				}
			}
			else if (s[i] == '<' && c != d) {
				error::printError("Functions and variables out of order", i);
				err = -230;
				break;
			}
		}
	}

	void Interpreter(const int& d, std::unordered_map<std::string, int>& vars, std::string* funcs[], int& err) {

	}

	//Takes in Function from config.json and dimension count <2,3>
	void ParserHandler(std::string& s, const int& d, int& err) {
		std::unordered_map<std::string, int> vars;
		std::string* funcs = new std::string[d];

		Parse(s, d, vars, funcs, err);
		if (err < 0) return;

		for (int i = 0; i < d; i++) {
			std::cout << funcs[i] << std::endl;
		}

		delete[] funcs;
	}
}