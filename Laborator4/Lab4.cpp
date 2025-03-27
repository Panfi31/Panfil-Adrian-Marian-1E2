#include <iostream>
#include "Sort.h"

using namespace std;


int main()
{

Sort t1(6,4,23);
t1.Print();
cout << endl;
cout << t1.GetElementsCount() <<' ' << t1.GetElementFromIndex(3) << endl;
t1.InsertSort(false);
t1.Print();
cout << endl;

int v[7] = { 4,23,56,1,9,12,30 };
Sort t2(v, 7);
t2.Print();
cout << endl;
cout << t2.GetElementsCount() << ' ' << t1.GetElementFromIndex(4) << endl;
t2.QuickSort(true);
t2.Print();
cout << endl;

Sort t3(5, 24, 17, 34, 56, 1, 2, 4);
t3.Print();
cout << endl;
cout<< t3.GetElementsCount() << ' ' << t3.GetElementFromIndex(2) << endl;
t3.BubbleSort();
t3.Print();
cout << endl;

Sort t4("10,6,7,24,12");
t4.Print();
cout << endl;
cout << t4.GetElementsCount() << " " << t4.GetElementFromIndex(3) << endl;

}