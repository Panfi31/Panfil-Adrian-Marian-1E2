#include <cstring>
#include <cstdarg>
#include "Math.h"



int Math::Add(int x, int y)
{
    return x + y;
}

int Math::Add(int x, int y, int z)
{
    return x + y + z;
}

int Math::Add(double x, double y) {

    return x + y;
}

int Math::Add(double x, double y, double z)
{
    return x + y + z;
}

int Math::Mul(int x, int y)
{
    return x * y;
}

int Math::Mul(int x, int y, int z)
{
    return x * y * z;
}

int Math::Mul(double x, double y)
{
    return x * y;
}

int Math::Mul(double x, double y, double z)
{
    return x * y * z;
}

int Math::Add(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum = 0;
    while (count != 0)
    {
        int x = va_arg(args, int);
        sum = sum + x;
        count--;

    }
    va_end(args);
    return sum;
}

char* Add(const char* a, const char* b)
{
    int sum;

    if (a == nullptr || b == nullptr)
        return nullptr;
    else
        sum = (int)a + (int)b;
    return (char*)sum;
}
