#include <iostream>
#include<ComputationalModel.h>
#include "src\ArrayAdditionModel.cpp"
#include <random>

#define N 100
#define RANGE_OF_INT_VALUES 1024

using namespace std;
int main()
{
    int inputA[N];
    int inputB[N];
    int inputC[N];
    int output[N];
    for(int k = 0; k<N; k++){
        inputA[k] = rand()%RANGE_OF_INT_VALUES;
        inputB[k] = rand()%RANGE_OF_INT_VALUES;
        inputC[k] = rand()%RANGE_OF_INT_VALUES;
    }

    ArrayAdditionModel arrayAdditionModel (inputA, inputB, output, N);

    arrayAdditionModel.execute();
    for(int i=0; i<N; i++)
        cout << output[i] << ", ";

    arrayAdditionModel.setData(inputB, inputC, output, N).execute();
    for(int i=0; i<N; i++)
        cout << output[i] << ", ";

    return 0;
}
