#include "Initializer.h"

namespace vectorfield { namespace initalizer {
	//Open config.json and extract config settings
	void loadConfig(std::ifstream& cfg_file) {

		//Create json and config objects
		nlohmann::json json_cfg;
		cfg_file >> json_cfg;
		
		std::cout << "Density: " << json_cfg["density"];

		/*config cfg(json_cfg["density"], json_cfg["dimensions"]);

		json_cfg["density"];

		cfg.density = json_cfg["density"];
		cfg.dimensions = json_cfg["dimensions"];
		for (int i = 0; i < cfg.dimensions; i++) {
			cfg.mm[i][0] = json_cfg["grid_range"][i]["min"];
			cfg.mm[i][1] = json_cfg["grid_range"][i]["max"];
		}

		cfg(json_cfg["density"], )

		return cfg;*/
	}

	bool rangeCheck(const float& min, const float& max) {
		return 0;
	}
}}