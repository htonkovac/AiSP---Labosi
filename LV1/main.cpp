#include <iostream>
#include <stdlib.h>
#define ARRAY_SIZE 50

float slucajanBrojUnutarGranica(float a, float b)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void gen_arr(float V[], int n, float dg, float gg)
{
    for (int i = 0; i < n; i++)
    {
        V[i] = slucajanBrojUnutarGranica(dg, gg);
    }
}

void ispisiPolje(float V[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << V[i] << " ";
    }
    std::cout << std::endl
              << "*********" << std::endl;
}

int sekv_pret(float V[], int n, float x)
{
    for (int i = 0; i < n; i++)
    {
        if (V[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(float V[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (V[j] > V[j + 1])
                swap(&V[j], &V[j + 1]);
}

int bin_pret(float V[], int n, float x)
{
    int dg = 0, gg = n-1;

    while (gg >= dg)
    {
        n = dg + (gg - dg) / 2;
        if (V[n] == x)
        {
            return n;
        }
        if (V[n] > x)
        {
            gg = n - 1;
        }
        else
        {
            dg = n + 1;
        }
    }

    return -1;
}

int binarySearch(float arr[], int l, int r, float x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 

        if (arr[mid] == x)   
            return mid; 

        if (arr[mid] > x)  
            return binarySearch(arr, l, mid-1, x); 
  
        return binarySearch(arr, mid+1, r, x); 
   } 
  
   return -1; 
} 


int main()
{
    float *myArray = new float[ARRAY_SIZE];
    gen_arr(myArray, ARRAY_SIZE, 5.0, 120.5);
    ispisiPolje(myArray, ARRAY_SIZE);
    bubbleSort(myArray, ARRAY_SIZE);
    ispisiPolje(myArray, ARRAY_SIZE);
    std::cout << bin_pret(myArray, ARRAY_SIZE, 66.5346) << std::endl;
    std::cout << binarySearch(myArray, 0,  ARRAY_SIZE -1 , 66.5346) << std::endl;

}