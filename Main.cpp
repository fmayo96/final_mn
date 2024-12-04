#include <iostream>
#include "matrix.h"
#include <complex>

int main() {

	Matrix sz({ { 1, 0 }, { 0, -1 } });
	Matrix sx({{ 0, 1 }, { 1, 0 }});
	Matrix sy({ { 0, -std::complex<double>(0,1)}, { std::complex<double>(0,1), 0} });
	std::cout << (sz == sz) << std::endl;
	std::cout << (sx == sz) << std::endl;
	return 0;
}
