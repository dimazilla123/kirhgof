#ifndef ALGEBRA_H
#define ALGEBRA_H

#include "matrix.h"

template<typename T>
std::vector<T> solve(Matrix<T>& m);

template<typename T>
void solve(Matrix<T>& m, std::vector<T>& res, size_t variables_cnt);

#endif