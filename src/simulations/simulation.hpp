#include <crf/matrix.hpp>


#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

namespace crf {

template<int N>
struct simulation {
	static void run();

private:
	static void simulate();
};

template<>
struct simulation<2> {
	static void run() {
		simulate();
	}

private:
	static void simulate() {
		std::cout << crf::matrix<2, 2>( ) << std::endl;
	}
};

}

template<int N>
void crf::simulation<N>::run() {
	simulation<N - 1>::run(); // N + (N / 3)
	simulate();
}

template<int N>
void crf::simulation<N>::simulate() {
	std::cout << crf::matrix<N, N>( ) << std::endl;
}


#endif
