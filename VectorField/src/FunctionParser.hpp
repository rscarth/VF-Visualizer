#pragma once

#include "pch.h"

namespace parser {
	void Parse(const std::string& s, const int& d, std::unordered_map<std::string, int>& vars, std::string* funcs, int& err);
	void Interpreter(const int& d, std::unordered_map<std::string, int>& vars, std::string* funcs[], int& err);
	void ParserHandler(std::string& s, const int& d, int& err);
}