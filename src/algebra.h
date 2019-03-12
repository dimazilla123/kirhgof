#ifndef ALGEBRA_H
#define ALGEBRA_H

#include "matrix.h"

template<typename T>
std::vector<T> solve(Matrix<T>& m);

template<typename T>
void solve(Matrix<T>& m, std::vector<T>& res, size_t variables_cnt);

template<typename T>
bool are_equations_equal(const std::vector<T>& a, const std::vector<T>& b);

template<typename T>
bool add_equation(Matrix<T>& m, const std::vector<T>& line);

#endif
