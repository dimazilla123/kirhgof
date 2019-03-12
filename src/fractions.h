#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <ostream>
#include <istream>

template<typename T>
struct Fractional
{
    T numerator = 0, denominator = 1;
    Fractional(T x) : numerator(x), denominator(1) {}
    Fractional(T x, T y) : numerator(x), denominator(y) {}
    Fractional() : numerator(0), denominator(1) {}
    Fractional<T> operator+(const Fractional<T>& other) const;
    Fractional<T> operator-(const Fractional<T>& other) const;
    Fractional<T> operator*(const Fractional<T>& other) const;
    Fractional<T> operator/(const Fractional<T>& other) const;
    Fractional<T> operator%(const Fractional<T>& other) const;
    Fractional<T>& operator+=(const Fractional<T>& other);
    Fractional<T>& operator-=(const Fractional<T>& other);
    Fractional<T>& operator*=(const Fractional<T>& other);
    Fractional<T>& operator/=(const Fractional<T>& other);
    Fractional<T>& operator%=(const Fractional<T>& other);
    bool operator!=(const Fractional<T>& other) const;
    bool operator==(const Fractional<T>& other) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Fractional<T>& n);

template<typename T>
std::istream& operator>>(std::istream& in, Fractional<T>& n);

#endif