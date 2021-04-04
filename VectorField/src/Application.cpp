#include "pch.h"

int main(void) {
	const std::string cfg_path = "src/config.json";
	config::Config cfg;
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

		config::LoadConfig(cfg_file, cfg, error);
		parser::parse(cfg.function, cfg.dimensions, error);
		if (error < 0) return error;
		std::cout << cfg.density;

		std::cout << "Config loaded successfully." << std::endl;
	}

	return 0;
}