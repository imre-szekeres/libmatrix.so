#include <simulations/simulation.hpp>

int const MAX_SIMULATION = 5;


int main( void ) {
	std::cout << "Running matrix simulations.." << std::endl;
	crf::simulation<MAX_SIMULATION>::run();
}
