#include "Initializer.h"

namespace vectorfield { namespace initalizer {
	//Open config.json and extract config settings
	config loadConfig(std::ifstream& cfg_file) {

		//Create json and config objects
		nlohmann::json json_cfg;

		cfg_file >> json_cfg;
		
		std::cout << "Density: " << json_cfg["density"];

		config cfg(json_cfg["density"], json_cfg["dimensions"]);

		for (int i = 0; i < cfg.dimensions; i++) {
			cfg.addMM(json_cfg["grid_range"][i]["min"], json_cfg["grid_range"][i]["max"]);
		}

		return cfg;
	}

	void initalize(std::ifstream& cfg_file, int* err) {
		auto cfg = loadConfig(cfg_file);

		if (cfg.checkDensity()) { std::cout << "Density must be greater than 0" << std::endl;  *err = -1; }
		if (cfg.checkRange()) { std::cout << "Range out of order error" << std::endl; *err = -2; }
		if (cfg.checkOverflow()) { std::cout << "Overflow detected, please reduce range or increase density" << std::endl; *err = -3; }
		
		//End program in initialization if error in config
		if (*err < -1) return;

	}
}}