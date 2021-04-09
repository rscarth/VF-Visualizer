#pragma once

#include "pch.h"

namespace parser {
	void Parse(const std::string& s, const int& d, std::unordered_map<std::string, int>& vars, std::string* funcs);
	void Interpreter(const int& d, std::unordered_map<std::string, int>& vars, std::string* funcs[]);
	void ParserHandler(std::string& s, const int& d);
}
