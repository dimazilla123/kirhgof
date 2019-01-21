#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

#include "matrix.h"

int main(int argc, char const *argv[])
{
    Matrix<int> mat(10, 10);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            mat[i][j] = i + j;
    
    
    return 0;
}