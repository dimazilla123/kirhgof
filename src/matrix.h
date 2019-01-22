#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template<typename T>
class Matrix;

template<typename T>
struct Point
{
    Matrix<T>* mat;
    size_t x, y;
    bool operator!=(const Point& other) const;
    Point& operator++();
    Point& operator--();
    Point operator++(int);
    Point operator--(int);
    T& operator*() {return (*mat)[x][y];};
};

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
    Point<T> begin();
    Point<T> end();
    bool operator!=(const Line& other) const;
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