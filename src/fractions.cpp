#include "fractions.h"
#include <utility>

template<typename T>
T gcd(T a, T b)
{
    while (b != 0)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template<typename T>
Fractional<T> Fractional<T>::operator+(const Fractional<T> &other) const
{
    T mul1 = denominator;
    T mul2 = other.denominator;
    denominator *= mul2;
    numerator *= mul2;
    other.denominator *= mul1;
    other.numerator *= mul1;
    Fractional<T> ret(numerator + other.numerator, mul1 * mul2);
    T del = gcd(ret.numerator, ret.denominator);
    ret.denominator /= del;
    ret.numerator /= del;
    return ret;
}

template<typename T>
Fractional<T> Fractional<T>::operator*(const Fractional<T> &other) const
{
    Fractional<T> ret(numerator * other.numerator, denominator * other.denominator);
    T del = gcd(ret.numerator, ret.denominator);
    ret.denominator /= del;
    ret.numerator /= del;
    return ret;
}

template<typename T>
Fractional<T> Fractional<T>::operator-(const Fractional<T> &other) const
{
    return (*this) + Fractional<T>(-1) * other;
}

template<typename T>
Fractional<T> Fractional<T>::operator/(const Fractional<T> &other) const
{
    Fractional<T> mul(other.denominator, other.numerator);
    return (*this) * mul;
}