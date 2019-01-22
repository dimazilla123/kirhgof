#ifndef FRACTIONS_H
#define FRACTIONS_H

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
};

#endif