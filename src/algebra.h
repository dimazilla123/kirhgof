#ifndef ALGEBRA_H
#define ALGEBRA_H

#include "matrix.h"

template<typename T>
std::vector<T> solve(const Matrix<T>& m);

template<typename T>
std::vector<T>& solve(const Matrix<T>& m, size_t variables_cnt);

#endif