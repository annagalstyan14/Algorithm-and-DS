#pragma once
#include <cmath>

template<typename T>
T fi_power_n(T n){
    const long double sqrt5 = std::sqrt(5.0L);
    const long double fi = (1.0L + sqrt5)/2.0L;
    return static_cast<T>(std::round(std::pow(fi, n)/sqrt5));
}