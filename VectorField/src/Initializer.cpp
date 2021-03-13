#include <fstream>

#include "Initializer.h"

namespace vectorfield { namespace initalizer {

	//Open config.json and extract config settings
	void loadConfig(const std::string &config) {
		const std::ifstream cfile(config);
		
		//Check if file exists
		if (!cfile) {
			std::cerr << "The config file, " << config << ", was not found." << std::endl;
		}
		else {
			std::cout << "File found";
		}
	}

	bool fileExist(const std::string& config) {

	}

	bool rangeCheck(const float& min, const float& max) {

	}
}}