#include "matrix.h"
#include "fractions.h"

template<typename T>
Matrix<T>::Matrix(size_t height_, size_t width_)
{
    height = height_;
    width = width_;
    arr.resize(height_ * width_);
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
Line<T> Matrix<T>::begin()
{
    return Line<T>{
        .mat = this,
        .pos = 0
    };
}

template<typename T>
Line<T> Matrix<T>::end()
{
    return Line<T>{
        .mat = this,
        .pos = height
    };
}

template<typename T>
bool Line<T>::operator!=(const Line<T>& other) const
{
    return pos != other.pos;
}

template<typename T>
Point<T> Line<T>::begin()
{
    return Point<T>{
        .mat = mat,
        .x = 0,
        .y = pos
    };
}

template<typename T>
Point<T> Line<T>::end()
{
    return Point<T>{
        .mat = mat,
        .x = mat->getWidth(),
        .y = pos
    };
}

template<typename T>
T& Line<T>::back()
{
    return this->operator[](mat->getWidth() - 1);
}

template<typename T>
Point<T>& Point<T>::operator++()
{
    ++x;
    return *this;
}

template<typename T>
Point<T>& Point<T>::operator--()
{
    --x;
    return *this;
}

template<typename T>
Point<T> Point<T>::operator++(int)
{
    ++x;
    return *this;
}

template<typename T>
Point<T> Point<T>::operator--(int)
{
    --x;
    return *this;
}

template<typename T>
bool Point<T>::operator!=(const Point<T>& other) const
{
    return x != other.x;
}

template struct Point<int>;
template struct Line<int>;
template class Matrix<int>;
template struct Point<Fractional<int>>;
template struct Line<Fractional<int>>;
template class Matrix<Fractional<int>>;
template struct Point<std::pair<int, int>>;
template struct Line<std::pair<int, int>>;
template class Matrix<std::pair<int, int>>;