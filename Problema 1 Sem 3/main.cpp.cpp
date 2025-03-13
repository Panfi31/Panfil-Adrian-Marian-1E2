#include <iostream>
#include "Math.h"
using namespace std;

int main()
{

    Math prob;
    int x, y, z;
    double a, b, c;
    const char g = 'g', h = 'h';
    cin >> x >> y >> z >> a >> b >> c;

    cout << prob.Add(x, y) << ' ' << prob.Add(x, y, z) << ' ' << prob.Add(a, b) << ' ' << prob.Add(a, b, c) << endl;
    cout << prob.Mul(x, y) << ' ' << prob.Mul(x, y, z) << ' ' << prob.Mul(a, b) << ' ' << prob.Mul(a, b, c) << endl;
    cout << prob.Add(4, 5, 2, 5, 6, 7) << endl;
    cout << prob.Add(g, h);


}
