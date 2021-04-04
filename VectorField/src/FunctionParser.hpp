#pragma once

#include <stack>

#include "pch.h"

namespace parser {
	int* parse(std::string& s, const int& d, int& err);
}