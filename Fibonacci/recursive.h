#pragma once

template<typename T>
T recursive(T n){
    return (n<=1) ? n : recursive<T>(n-1) + recursive<T>(n-2);
}