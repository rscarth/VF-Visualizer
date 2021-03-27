#pragma once
#include <cmath>

#include "pch.h"

namespace vectorfield { namespace initalizer {
	//Struct to hold value of lower and upper bounds for each set of dimensions
	struct range {
		float min;
		float max;
		range(float& min, float& max) : min(min), max(max) {};
	};

	//Struct to hold config interpreted from config.json
	//Density, Dimensions, and Min/Max range
	//Functions to error check values accordingly
	struct config {
		float density;
		int dimensions;
		std::vector<range> mmRange;

		config(float density, int dimensions) : density{ density }, dimensions{ dimensions } {};
		void addMM(float min, float max) { mmRange.push_back(range(min, max)); };

		bool checkRange(); bool checkDensity(); bool checkOverflow();
	};

	config loadConfig(std::ifstream& cfg_file);

	void initalize(std::ifstream& cfg_file, int& err);
}}