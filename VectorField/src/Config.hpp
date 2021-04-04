#pragma once

#include "pch.h"

namespace config {
	struct Config {
		float density;
		int dimensions;
		std::vector<std::vector<float>> mm_range;
		std::string function;
	};


	void LoadConfig(std::ifstream& cfg_file, Config& cfg, int& err);
}