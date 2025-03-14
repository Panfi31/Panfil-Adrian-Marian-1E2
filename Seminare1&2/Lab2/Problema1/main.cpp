#include <iostream>
#include "NumberList.h"

using namespace std;

int main()
{
	NumberList lista;
	int nrs[10], lungime;
	cin >> lungime;

	for (int i = 0;i < lungime;i++)
		cin >> nrs[i];

	lista.Init();

	for (int i = 0;i < lungime;i++)
		lista.Add(nrs[i]);
	lista.Sort();
	lista.Print();

}


