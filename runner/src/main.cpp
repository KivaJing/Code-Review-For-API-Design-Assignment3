// main.cpp
#include "application.hpp"
#include <stdexcept>
#include <print>

int main(int argc, char** argv)
{
	try {
		runner::Application{}.run();
	}
	catch (const std::runtime_error& e) {
		std::print("{}", e.what());
	}
	catch (const std::exception& e) {
		std::print("Exception caught: ", e.what());
	}
	catch (...) {
		std::print("Unknown error occured. Exiting.");
	}
	return 0;
}
