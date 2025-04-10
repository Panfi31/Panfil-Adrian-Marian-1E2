#pragma once

class Number {
private:
    char* value;
    int base;

    int ToDecimal() const;
    void FromDecimal(int val, int base);

public:
    Number(const char* value, int base);
    Number(int val); // base 10 constructor
    Number(const Number& other); // copy constructor
    Number(Number&& other) noexcept; // move constructor
    ~Number();

    Number& operator=(const Number& other); // copy assignment
    Number& operator=(Number&& other) noexcept; // move assignment
    Number& operator=(int val);
    Number& operator=(const char* str);

    char operator[](int index) const;

    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);

    Number& operator+=(const Number& other);

    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;
    bool operator!=(const Number& other) const;

    Number& operator--(); // prefix
    Number operator--(int); // postfix

    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};
