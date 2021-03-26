#include "pch.h"
#include "Initializer.h"

int main(void) {
	//Config File
	const std::string cfg_path = "src/config.json";
	std::ifstream cfg_file(cfg_path);

	//Check if file exists
	if (!cfg_file) {

		std::cerr << "The config file " << cfg_path << " was not found." << std::endl;
		cfg_file.close();
		return -1;
	}
	else {
		std::cout << "Config file " << cfg_path << " found." << std::endl;
		/*vectorfield::initalizer::config cfg = vectorfield::initalizer::loadConfig(cfg_file);*/
		vectorfield::initalizer::loadConfig(cfg_file);
	}

	return 0;
}