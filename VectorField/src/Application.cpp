#include "pch.h"
#include "Initializer.h"

int main(void) {
	//Config File
	const std::string cfg_path = "src/config.json";
	std::ifstream cfg_file(cfg_path);
	int error = 0;

	//Check if config file exists
	if (!cfg_file) {
		std::cerr << "The config file " << cfg_path << " was not found." << std::endl;
		cfg_file.close();
		return -1;
	}
	else {
		std::cout << "Config file " << cfg_path << " found." << std::endl;
		vectorfield::initalizer::initalize(cfg_file, error);

		//End program if error in config
		if(error < 0) return error;
	}

	return 0;
}