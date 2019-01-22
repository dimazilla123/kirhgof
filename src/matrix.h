#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template<typename T>
class Matrix;

template<typename T>
struct Line
{
    Matrix<T>* mat;
    size_t pos;
    T& operator[](size_t pos);
    Line& operator--();
    Line& operator++();
    Line operator--(int);
    Line operator++(int);
    Line& operator*() {return *this;};
    bool operator!=(const Line& other) const;
};

template<typename T>
struct MatrixIterator
{
    Line<T> data_;
    Line<T> operator*()
    {
        return data_;
    }
};

template<typename T>
class Matrix
{
private:
    size_t height, width;
public:
    
    std::vector<T> arr;
    Matrix(size_t height_, size_t width_);
    size_t getHeight() const;
    size_t getWidth() const;
    Line<T>& operator[](size_t pos);
    Line<T> begin();
    Line<T> end();
};
#endif /* MATRIX_H */