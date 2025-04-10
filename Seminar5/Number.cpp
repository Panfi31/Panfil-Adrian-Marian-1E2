
#include "Number.h"
#include <iostream>
#include <cstring>
#include <algorithm>

Number::Number(const char* valoareInitiala, int bazaInitiala)
    : base(bazaInitiala) {
    value = new char[strlen(valoareInitiala) + 1];
    strcpy(value, valoareInitiala);
}

Number::Number(int val) : base(10) {
    FromDecimal(val, base);
}

Number::~Number() {
    delete[] value;
}

Number::Number(const Number& other) : base(other.base) {
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}

Number::Number(Number&& other) noexcept : value(other.value), base(other.base) {
    other.value = nullptr;
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        value = new char[strlen(other.value) + 1];
        strcpy(value, other.value);
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        value = other.value;
        base = other.base;
        other.value = nullptr;
    }
    return *this;
}

Number& Number::operator=(int valoareZecimala) {
    FromDecimal(valoareZecimala, base);
    return *this;
}

Number& Number::operator=(const char* valoareNoua) {
    delete[] value;
    value = new char[strlen(valoareNoua) + 1];
    strcpy(value, valoareNoua);
    return *this;
}

void Number::SwitchBase(int newBase) {
    int decimalVal = ToDecimal();
    FromDecimal(decimalVal, newBase);
    base = newBase;
}

void Number::Print() const {
    std::cout << value << '\n';
}

int Number::GetDigitsCount() const {
    return strlen(value);
}

int Number::GetBase() const {
    return base;
}

char Number::operator[](int index) const {
    return value[index];
}

Number operator+(const Number& a, const Number& b) {
    int valoareA = a.ToDecimal();
    int valoareB = b.ToDecimal();
    int bazaRezultat = std::max(a.base, b.base);
    Number rezultat("0", bazaRezultat);
    rezultat.FromDecimal(valoareA + valoareB, bazaRezultat);
    return rezultat;
}

Number operator-(const Number& a, const Number& b) {
    int valoareA = a.ToDecimal();
    int valoareB = b.ToDecimal();
    int bazaRezultat = std::max(a.base, b.base);
    Number rezultat("0", bazaRezultat);
    rezultat.FromDecimal(valoareA - valoareB, bazaRezultat);
    return rezultat;
}

bool Number::operator>(const Number& other) const {
    return ToDecimal() > other.ToDecimal();
}

bool Number::operator<(const Number& other) const {
    return ToDecimal() < other.ToDecimal();
}

bool Number::operator>=(const Number& other) const {
    return ToDecimal() >= other.ToDecimal();
}

bool Number::operator<=(const Number& other) const {
    return ToDecimal() <= other.ToDecimal();
}

bool Number::operator==(const Number& other) const {
    return ToDecimal() == other.ToDecimal();
}

bool Number::operator!=(const Number& other) const {
    return !(*this == other);
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator--() { // prefix
    int len = strlen(value);
    if (len <= 1) {
        delete[] value;
        value = new char[2] {'0', '\0'};
    }
    else {
        char* newValue = new char[len];
        strcpy(newValue, value + 1);
        delete[] value;
        value = newValue;
    }
    return *this;
}

Number Number::operator--(int) { // postfix
    Number copy = *this;
    int len = strlen(value);
    if (len <= 1) {
        delete[] value;
        value = new char[2] {'0', '\0'};
    }
    else {
        value[len - 1] = '\0';
    }
    return copy;
}

int Number::ToDecimal() const {
    int rezultat = 0;
    int len = strlen(value);
    for (int i = 0; i < len; ++i) {
        char c = value[i];
        int digit = (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 10);
        rezultat = rezultat * base + digit;
    }
    return rezultat;
}

void Number::FromDecimal(int valoareZecimala, int bazaNoua) {
    char buffer[100];
    int index = 0;
    do {
        int rest = valoareZecimala % bazaNoua;
        buffer[index++] = (rest < 10) ? ('0' + rest) : ('A' + rest - 10);
        valoareZecimala /= bazaNoua;
    } while (valoareZecimala > 0);
    buffer[index] = '\0';
    std::reverse(buffer, buffer + index);
    delete[] value;
    value = new char[strlen(buffer) + 1];
    strcpy(value, buffer);
}
