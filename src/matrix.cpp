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
    Line<T>* l = new Line<T>;
    l->mat = this;
    l->pos = pos;
    return *l;
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
    return mat->arr[mat->getWidth() * pos + inline_pos];
}

template<typename T>
Line<T>& Line<T>::operator++()
{
    ++pos;
    return *this;
}

template<typename T>
Line<T>& Line<T>::operator--()
{
    --pos;
    return *this;
}

template<typename T>
Line<T> Line<T>::operator++(int)
{
    Line<T> ret = *this;
    ++ret.pos;
    return ret;
}

template<typename T>
Line<T> Line<T>::operator--(int)
{
    Line<T> ret = *this;
    --ret.pos;
    return ret;
}

template<typename T>
MatrixIterator<T> Matrix<T>::begin()
{
    return MatrixIterator<T>{ .data_ = Line<T>{
        .mat = this,
        .pos = 0
    }};
}

template<typename T>
MatrixIterator<T> Matrix<T>::end()
{
    return MatrixIterator<T>{ .data_ = Line<T>{
        .mat = this,
        .pos = height
    }};
}

template struct Line<int>;
template class Matrix<int>;