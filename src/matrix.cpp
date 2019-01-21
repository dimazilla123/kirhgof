#include "matrix.h"

template<typename T>
Matrix<T>::Matrix(size_t height_, size_t width_)
{
    height = height_;
    width = width_;
    arr.resize(height * width_);
}

template<typename T>
Line<T>& Matrix<T>::operator[](size_t pos)
{
    Line<T> l;
    l.mat = this;
    l.pos = pos;
    return l;
}

template<typename T>
size_t Matrix<T>::getHeight() const
{
    return height;
}

template<typename T>
size_t Matrix<T>::getWidth() const
{
    return width;
}

template<typename T>
T& Line<T>::operator[](size_t inline_pos)
{
    return mat->operator[](mat->getWidth() * pos + inline_pos);
}