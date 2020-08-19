#include <iostream>
#include <ComputationalModel.h>
#include <ArrayAdditionModel.cpp>
#include <random>

#define N 10000
#define EXPERIMENT_COUNT 20
#define RANGE_OF_INT_VALUES 1024

using namespace std;
int main()
{
    int inputA[N];
    int inputB[N];
    int inputC[N];
    int output[N];
    ArrayAdditionModel arrayAdditionModel;

    for(int exp = 0; exp<EXPERIMENT_COUNT; exp++){
        for(int k = 0; k<N; k++){
            inputA[k] = rand()%RANGE_OF_INT_VALUES;
            inputB[k] = rand()%RANGE_OF_INT_VALUES;
            inputC[k] = rand()%RANGE_OF_INT_VALUES;
        }
        arrayAdditionModel.setData(inputB, inputC, output, N);
        arrayAdditionModel.execute();
        /* for(int i=0; i<N; i++)
            cout << output[i] << ", ";
        */
    }
    return 0;
}
