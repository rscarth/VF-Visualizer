#pragma once

#include "pch.h"

#define LOGGING true

namespace error {
	//General Utility Error Checking
	//
	//Takes two numbers as input and returns error if min > max
	template <typename T>
	bool checkRange(const T& min, const T& max, const std::string msg) {
		if (min >= max) {
			if (LOGGING) { std::cout << msg << std::endl; };
			return false;
		}
		return true;
	}

	//Takes a number and returns error if n <= 0.0
	template <typename T>
	bool checkPositive(const T& n, const std::string msg) {
		if (n <= 0.0) {
			if (LOGGING) { std::cout << msg << std::endl; };
			return false;
		}
		return true;
	}

	//Config Loading Error Checking
	//
	//Takes a int as input and returns error if overflow exists
	template <typename T>
	bool checkOverflow(const T& n, const int max_size, const std::string msg) {
		if (n == 0 || n >= max_size) {
			if (LOGGING) { std::cout << msg << std::endl; };
			return false;
		}
		return true;
	}

	//Takes a int as input and returns error if not 2 or 3
	template <typename T>
	bool checkDimensions(const T& n, const std::string msg) {
		if (n == 2 || n == 3) { return true; }

		if (LOGGING) { std::cout << msg << std::endl; };
		return false;
	}
}