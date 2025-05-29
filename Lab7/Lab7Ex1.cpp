#include <iostream>

using namespace std;
float operator"" _Kelvin(unsigned long long k) {
    return static_cast<float>(k - 273.15);
}


float operator"" _Fahrenheit(unsigned long long f) {
    return static_cast<float>((f - 32) * 5.0 / 9.0);
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout << "300 Kelvin in Celsius: " << a << "\n";    
    cout << "120 Fahrenheit in Celsius: " << b << "\n"; 

    return 0;
}
