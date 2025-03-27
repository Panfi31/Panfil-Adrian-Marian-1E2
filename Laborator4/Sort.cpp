#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <stdarg.h>
#include <cstring>
#include "Sort.h"

using namespace std;

Sort::Sort(int n, int min, int max)
{
    nrElem = n;
    lista = new int[nrElem];
    for (int i = 0; i < n; i++)
        lista[i] = min + (rand() % (max - min + 1));
}

Sort::Sort(std::initializer_list<int> list) {
    nrElem = list.size();
    lista = new int[nrElem];

    int i = 0;
    for (int val : list) {
        lista[i++] = val;
    }
}


Sort::Sort (int v[],int n)
{
    nrElem = n;
    lista = new int[nrElem];
    for (int i = 0; i < n; i++)
        lista[i] = v[i];
}

Sort::Sort(int n, ...)
{
    nrElem = n;
    lista = new int[nrElem];

    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++)
        lista[i] = va_arg(args, int);
    va_end(args);
}


Sort::Sort(const char s[100])
{
    nrElem = 0;
    lista = new int[100]; 

    char temp[100];
    strcpy(temp, s);  

    char* p = strtok(temp, ",");
    while (p) {
        lista[nrElem++] = atoi(p);
        p = strtok(NULL, ",");
    }
}
    

    void Sort::InsertSort(bool ascendent)
    {
        for (int i = 1; i < nrElem; i++)
        {
            int key = lista[i];
            int j = i - 1;

            while (j >= 0 && ((ascendent && lista[j] > key) || (!ascendent && lista[j] < key)))
            {
                lista[j + 1] = lista[j];
                j--;
            }
            lista[j + 1] = key;
        }
    }

    int partition(int arr[], int low, int high, bool ascendent)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++)
        {
            if ((ascendent && arr[j] <= pivot) || (!ascendent && arr[j] >= pivot))
            {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

void Sort::QuickSort(bool ascendent) {
    int low = 0, high = nrElem - 1;

    while (low < high) {
        int pi = partition(lista, low, high, ascendent);

        
        if (pi - low < high - pi) {
            high = pi - 1;
        }
        else {
            low = pi + 1;
        }
    }
}




void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < nrElem - 1; i++)
    {
        for (int j = 0; j < nrElem - i - 1; j++)
        {
            if ((ascendent && lista[j] > lista[j + 1]) || (!ascendent && lista[j] < lista[j + 1]))
            {
                std::swap(lista[j], lista[j + 1]);
            }
        }
    }
}


void Sort::Print()
{
    for (int i = 0; i < nrElem; i++)
    {
        cout << lista[i] << " ";
    }
}          

int Sort::GetElementsCount()
{
   
    
        return nrElem;
    

    
}

int Sort::GetElementFromIndex(int index)
{
    return lista[index];
}