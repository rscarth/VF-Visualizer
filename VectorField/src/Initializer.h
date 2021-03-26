#pragma once

#include "pch.h"

namespace vectorfield { namespace initalizer {
	struct range;

	struct config {
		int density;
		int dimensions;
		std::vector<range> mmRange;

		config(int& density, int& dimensions) : density{ density }, dimensions{ dimensions } {};
		void addMM(float& min, float& max) { mmRange.push_back(range(min, max)); };
	};

	struct range {
		float min;
		float max;
		range(float& min, float& max) : min(min), max(max) {};
	};

	void loadConfig(std::ifstream& cfg_file);
}}