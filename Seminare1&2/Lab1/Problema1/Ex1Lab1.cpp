#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    char cuv[256][256], string[256], * p;
    int nr = 0;
    scanf("%[^\n]", string);
    p = strtok(string, " ");
    while (p != NULL)
    {
        strcpy(cuv[nr], p);
        nr++;
        p = strtok(NULL, " ");
    }
    for (int i = 0; i < nr - 1; i++)
    {
        for (int j = i + 1; j < nr; j++)
        {
            if (strlen(cuv[i]) < strlen(cuv[j])) 
            {
                swap(cuv[i], cuv[j]);
            }
           
        }
    }
    for (int i = 0; i < nr; i++)
    {
        printf("%s \n", cuv[i]);
    }
    return 0;
}