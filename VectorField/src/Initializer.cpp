#include "Initializer.h"

namespace vectorfield { namespace initalizer {
	//Open config.json and extract config settings
	config loadConfig(std::ifstream& cfg_file) {

		//Create json and config objects
		nlohmann::json json_cfg;

		cfg_file >> json_cfg;

		config cfg(json_cfg["density"], json_cfg["dimensions"]);

		for (int i = 0; i < cfg.dimensions; i++) {
			cfg.addMM(json_cfg["grid_range"][i]["min"], json_cfg["grid_range"][i]["max"]);
		}

		return cfg;
	}

	void initalize(std::ifstream& cfg_file, int& err) {
		auto cfg = loadConfig(cfg_file);

		if (cfg.checkDensity()) { std::cout << "Density must be greater than 0" << std::endl;  err = -1; }
		if (cfg.checkRange()) { std::cout << "Range out of order error" << std::endl; err = -2; }
		if (cfg.checkOverflow()) { std::cout << "Overflow detected, please reduce range or increase density" << std::endl; err = -3; }
		
		//End program in initialization if error in config
		if (err < -1) return;


		//Program continues here
		std::cout << "Density: " << cfg.density << std::endl;
		std::cout << "Dimensions: " << cfg.dimensions << std::endl;
		for (auto& i : cfg.mmRange) {
			std::cout << i.min << " -> " << i.max << std::endl;
		}
	}

	//Error checking methods for struct config

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
			gridSize *= (int)((std::fabs(mmRange[i].min) +
							   std::fabs(mmRange[i].min)) /
							   density);
		}

		if (gridSize >= 4294967295) {
			return true;
		}

		return false;
	}
}}