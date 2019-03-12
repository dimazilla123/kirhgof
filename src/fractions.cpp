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
    Fractional<T> ret(numerator * mul2 + other.numerator * mul1, mul1 * mul2);
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

template<typename T>
Fractional<T> Fractional<T>::operator%(const Fractional<T> &other) const
{
    auto [p, q] = *this;
    auto [x, y] = other;
    return Fractional<T>(p * y % q * x, q * y);
}

template<typename T>
Fractional<T>& Fractional<T>::operator%=(const Fractional<T> &other)
{
    *this = (*this) % other;
    return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Fractional<T>& n)
{
    return out << n.numerator << '/' << n.denominator;
}

template<typename T>
std::istream& operator>>(std::istream& in, Fractional<T>& n)
{
    in >> n.numerator;
    n.denominator = 1;
    return in;
}

template<typename T>
Fractional<T>& Fractional<T>::operator+=(const Fractional<T> &other)
{
    *this = *this + other;
    return *this;
}
template<typename T>
Fractional<T>& Fractional<T>::operator-=(const Fractional<T> &other)
{
    *this = *this - other;
    return *this;
}
template<typename T>
Fractional<T>& Fractional<T>::operator*=(const Fractional<T> &other)
{
    *this = *this * other;
    return *this;
}
template<typename T>
Fractional<T>& Fractional<T>::operator/=(const Fractional<T> &other)
{
    *this = *this / other;
    return *this;
}

template<typename T>
bool Fractional<T>::operator==(const Fractional<T> &other) const
{
    return numerator * other.denominator == other.numerator * denominator;
}
template<typename T>
bool Fractional<T>::operator!=(const Fractional<T> &other) const
{
    return numerator * other.denominator != other.numerator * denominator;
}
template struct Fractional<int>;
template std::ostream& operator<<(std::ostream& out, const Fractional<int>& n);
template std::istream& operator>>(std::istream& in, Fractional<int>& n);
