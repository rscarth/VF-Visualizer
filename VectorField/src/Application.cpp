#include "pch.h"
#include "Initializer.h"

int main(void) {
	//Config File
	const std::string config = "config.json";
	vectorfield::initalizer::loadConfig(config);
}