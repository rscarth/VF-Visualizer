#include "Config.hpp"
#include "Error.hpp"

namespace config {
void LoadConfig(std::ifstream& cfg_file, Config& cfg, int& err) {
		//Parse cfg_file into json object
		nlohmann::json json_cfg;
		cfg_file >> json_cfg;

		//Check if density > 0
		//Insert density to struct cfg if pass
		if (!error::checkPositive(json_cfg["density"], "Density value must be greater than 0.0")) {
			err = -200;
		}
		else {
			cfg.density = (float)json_cfg["density"];
		}

		//Check if dimensions = 2 or 3
		//Insert dimensions to struct cfg if pass
		if (!error::checkDimensions(json_cfg["dimensions"], "Dimensions must be set to 2 or 3")) {
			err = -300;
		}
		else {
			cfg.dimensions = (int)json_cfg["dimensions"];
		}

		//Check if grid_range[i] min > grid_range[i] max for each dimension.
		//Append {grid_range[i] min, grid_range[i] max} to cfg.mmRange if pass.
		for (int i = 0; i < json_cfg["dimensions"]; i++) {
			if (!error::checkRange(json_cfg["grid_range"][i]["min"], json_cfg["grid_range"][i]["max"],
				"Min value greater or equal to max value")) {
				
				err = -400;
			}
			else {
				cfg.mm_range.push_back({ (float)json_cfg["grid_range"][i]["min"], (float)json_cfg["grid_range"][i]["max"] });
			}
		}

		cfg.function = (std::string)json_cfg["function"];

		////Calculates the amount of vertices in mesh grid to determine if overflow exist.
		//uint32_t temp_count = 1;
		//for (auto& range : cfg.mmRange) {
		//	temp_count *= (uint32_t)((std::fabs(range[0]) + std::fabs(range[1])) / cfg.density);
		//}

		//

		//if (!error::checkOverflow(temp_count, -1, "Overflow detected, reduce grid range or increase density")) {
		//	return true;
		//}
	}
}