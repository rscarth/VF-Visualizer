#include "FunctionParser.hpp"
#include "Error.hpp"

namespace parser {

	void Parse(const std::string& s, const int& d, std::unordered_map<std::string, int>& vars, std::string* funcs) {
		unsigned int s_len = s.length();
		std::string temp;
		int c = 0;
		bool var_dup = false, func_dup = false;

		for (unsigned int i = 0; i <= s_len; i++) {
			if (s[i] == '(' && var_dup != true) {
				var_dup = true;
				c = 0;
				i++;
				while (s[i - 1] != ')' && i != s_len) {
					if (s[i] != ',' && s[i] != ')') {
						if (s[i] != ' ') {
							temp += s[i];
						}
					}
					else if (c >= (d - 1) && s[i] == ',') {
						std::cout << s << std::endl;
						error::printError("More variables than dimensions parsed, check delimiters", -300, i);
						break;
					}
					else {
						vars.insert(std::pair<std::string, int>(temp, c));
						temp = "";
						c++;
					}

					i++;
				}

				if (s[i-1] != ')' && s[i] != ',') {
					std::cout << s << std::endl;
					error::printError("No closing bracket found for variables", -310, i);
					break;
				}

				temp = "";
			}
			else if (s[i] == '(' && var_dup == true) {
				std::cout << s << std::endl;
				error::printError("Duplicate '( )' brackets parsed", -340, i);
				break;
			}

			if (s[i] == '<' && func_dup != true) {
				func_dup = true;
				c = 0;
				i++;
				while (s[i - 1] != '>' && i != s_len) {
					if (s[i] != ',' && s[i] != '>') {
						if (s[i] != ' ') {
							temp += s[i];
						}
					}
					else if (c >= (d - 1) && s[i] == ',') {
						std::cout << s << std::endl;
						error::printError("More functions than dimensions parsed, check delimeters", -320, i);
						break;
					}
					else {
						funcs[c] = temp;
						temp = "";
						c++;
					}

					i++;
				}

				if (s[i - 1] != '>') {
					std::cout << s << std::endl;
					error::printError("No closing bracket found for functions", -330, i);
					break;
				}

				temp = "";
			}
			else if (s[i] == '<' && func_dup == true) {
				std::cout << s << std::endl;
				error::printError("Duplicate '< >' brackets parsed", -350, i);
				break;
			}
		}
	}

	void Interpreter(const int& d, std::unordered_map<std::string, int>& vars, std::string* funcs[]) {

	}

	//Takes in Function from config.json and dimension count <2,3>
	void ParserHandler(std::string& s, const int& d) {
		std::unordered_map<std::string, int> vars;
		std::string* funcs = new std::string[d];

		std::cout << "\nDimensions = " << d << std::endl;
		Parse(s, d, vars, funcs);
		if (error::err < 0) return;

		for (auto& x : vars) {
			std::cout << x.first << ": " << x.second << std::endl;
		}

		for (int i = 0; i < d; i++) {
			std::cout << funcs[i] << std::endl;
		}

		delete[] funcs;
	}
}