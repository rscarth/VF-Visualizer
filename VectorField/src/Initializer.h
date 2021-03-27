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

		bool checkRange();
		bool checkDensity();
		bool checkOverflow();
	};

	//Evalutes range of min/max verticies to deterimine if min > max
	//Return error if range[i].min >= range[i].max
	bool config::checkRange() {
		for (int i = 0; i < dimensions; i++) {
			if (mmRange[i].min >= mmRange[i].max) {
				return true;
			}
		}
		return false;
	}

	//Evaluates naturalness of density to eliminate infinite range errors
	//Return error if density <= 0.0
	bool config::checkDensity() {
		if (density <= 0.0) {
			return true;
		}

		return false;
	}

	//Evaluates the size of matrix to prevent overflow errors
	//Memory limited to 4,294,967,295 vertices
	//Return error if total of range/density is greater than allowed limit
	bool config::checkOverflow() {
		unsigned long int gridSize = 0;

		for (int i = 0; i < dimensions; i++) {
			gridSize *= (int)(std::fabs(mmRange[i].min) + std::fabs(mmRange[i].min))/density;
		}

		if (gridSize >= 4294967295) {
			return true;
		}

		return false;
	}

	config loadConfig(std::ifstream& cfg_file);

	void initalize(std::ifstream& cfg_file, int* err);
}}