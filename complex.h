#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex;

complex &
__doapl(complex *ths, const complex &r);

complex &
__doami(complex *ths, const complex &r);

complex &
__doaml(complex *ths, const complex &r);

class complex {
public:
    complex(double r = 0, double i = 0) : re(r), im(i) {}

    double real() const { return re; }

    double imag() const { return im; }

    complex &operator+=(const complex &r);

    complex &operator-=(const complex &r);

    complex &operator*=(const complex &r);

private:
    double re, im;

    friend complex &
    __doapl(complex *ths, const complex &r);

    friend complex &
    __doami(complex *ths, const complex &r);

    friend complex &
    __doaml(complex *ths, const complex &r);
};

inline complex &
__doapl(complex *ths, const complex &r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex &
complex::operator+=(const complex &r) {
    return __doapl(this, r);
}

inline complex &
__doami(complex *ths, const complex &r) {
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

inline complex &
complex::operator-=(const complex &r) {
    return __doami(this, r);
}

inline complex &
__doaml(complex *ths, const complex &r) {
    ths->re = ths->re * r.re - ths->im * r.im;
    ths->im = ths->re * r.im + ths->im * r.re;
    return *ths;
}

inline complex &
complex::operator*=(const complex &r) {
    return __doaml(this, r);
}

inline double
real(const complex &x) {
    return x.real();
}

inline double
imag(const complex &x) {
    return x.imag();
}

inline complex
operator+(const complex &x) {
    return x;
}

inline complex
operator-(const complex &x) {
    return complex(-real(x), -imag(x));
}

inline complex
operator+(const complex &x, const complex &y) {
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline complex
operator+(const complex &x, double y) {
    return x + complex(y, 0);
}

inline complex
operator+(double x, const complex &y) {
    return complex(x, 0) + y;
}

inline complex
operator-(const complex &x, const complex &y) {
    return x + (-y);
}

inline complex
operator-(const complex &x, double y) {
    return x - complex(y, 0);
}

inline complex
operator-(double x, const complex &y) {
    return complex(x, 0) - y;
}

inline complex
operator*(const complex &x, const complex &y) {
    return complex(real(x) * real(y) - imag(x) * imag(y),
                   real(x) * imag(y) + imag(x) * real(y));
}

inline complex
operator*(const complex &x, double y) {
    return x * complex(y, 0);
}

inline complex
operator*(double x, const complex &y) {
    return complex(x, 0) * y;
}

inline complex
operator/(const complex &x, double y) {
    return complex(real(x) / y, imag(x) / y);
}

inline bool
operator==(const complex &x, const complex &y) {
    return real(x) == real(y) && imag(x) == imag(y);
}

inline bool
operator==(const complex &x, double y) {
    return x == complex(y, 0);
}

inline bool
operator==(double x, const complex &y) {
    return complex(x, 0) == y;
}

inline bool
operator!=(const complex &x, const complex &y) {
    return !(x == y);
}

inline bool
operator!=(const complex &x, double y) {
    return x != complex(y, 0);
}

inline bool
operator!=(double x, const complex &y) {
    return complex(x, 0) != y;
}

#include <cmath>

inline complex
polar(double r, double t) {
    return complex(r * cos(t), r * sin(t));
}

inline complex
conj(const complex &x) {
    return complex(real(x), -imag(x));
}

inline double
norm(const complex &x) {
    return real(x) * real(x) + imag(x) * imag(x);
}

#endif
