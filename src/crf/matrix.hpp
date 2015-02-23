#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <vector>

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

namespace crf {

// TODO: ConstraintsPolicy..
template<int N, int K>
class matrix {
public:
	explicit matrix();
	matrix(std::initializer_list<double> &&);
	matrix(matrix const&);
	matrix(matrix &&);

	matrix& operator= (matrix const&);
	matrix& operator= (matrix &&);

	double operator() (int, int) const;

private:
	static int index_of(int, int);
	static void load_identity(std::vector<double>&);

	std::vector<double> _matrix;
};
}

template<int N, int K>
int crf::matrix<N, K>::index_of(int i, int j) {
	i = (i >= 0) ? i : (N + i), j = (j >= 0) ? j : (K + j);
	return i*K + j;
}

template<int N, int K>
void crf::matrix<N, K>::load_identity(std::vector<double>& matrix_) {
	matrix_.reserve( N*K );
//	for(int i = 0, min = std::min(N, K); i < min; ++i) // efficient
//		matrix_[index_of(i, i)] = 1.0;
	for(int i = 0; i < N; ++i) // correct..
		for(int j = 0; j < K; ++j)
			matrix_[index_of(i, j)] = (i == j);
}

template<int N, int K>
crf::matrix<N, K>::matrix( ) {
	load_identity( _matrix );
}

template<int N, int K>
double crf::matrix<N, K>::operator() (int i, int j) const {
	return _matrix[index_of(i, j)];
}


template<int N, int K>
std::ostream& operator<< (std::ostream& os_, crf::matrix<N,K> const& rhs_) {
	os_ << std::endl;
	for(int i = 0; i < N; ++i) {
		os_ << "| ";
		for(int j = 0; j < K; ++j)
			os_ << rhs_(i, j) << " ";
		os_ << "|" << std::endl;
	}
	return os_;
}

#endif
