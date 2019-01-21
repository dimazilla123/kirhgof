#pragma once
#include <vector>

template<typename T>
class Matrix;

template<typename T>
struct Line
{
    Matrix<T>* mat;
    size_t pos;
    T& operator[](size_t pos);
};

template<typename T>
class Matrix
{
private:
    size_t height, width;
    std::vector<T> arr;
public:
    Matrix(size_t height_, size_t width_);
    size_t getHeight() const;
    size_t getWidth() const;
    Line<T>& operator[](size_t pos);
};