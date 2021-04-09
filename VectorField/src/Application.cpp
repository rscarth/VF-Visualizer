#include "pch.h"
#include "Error.hpp"

int main(void) {
	const std::string cfg_path = "src/config.json";
	config::Config cfg;
	std::ifstream cfg_file(cfg_path);

	//Check if config file exists
	if (!cfg_file) {
		std::cerr << "The config file " << cfg_path << " was not found." << std::endl;
		cfg_file.close();
		return -1;
	}
	else {
		std::cout << "Config file " << cfg_path << " found." << std::endl;

		config::LoadConfig(cfg_file, cfg);
		if (error::err < 0) return error::err;
		parser::ParserHandler(cfg.function, cfg.dimensions);
		if (error::err < 0) return error::err;
		std::cout << "Config loaded successfully." << std::endl;
	}

	return 0;
}