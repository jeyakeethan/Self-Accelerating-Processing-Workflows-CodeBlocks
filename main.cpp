#include <iostream>
#include<ComputationalModel.h>
#include "src\ArrayAdditionModel.cpp"

using namespace std;
int main()
{
    int inputA[4] = {2, 2, 1, 2};
    int inputB[4] = {2, 2, 1, 2};
    int inputA1[4] = {1, 1, 1, 1};
    int inputB1[4] = {1, 1, 1, 1};
    int output[4];
    ArrayAdditionModel arrayAdditionModel (inputA, inputB, output, 4);

    arrayAdditionModel.execute();
    for(int i=0; i<4; i++)
        cout << output[i] <<endl;

    arrayAdditionModel.setData(inputA1, inputB1, output, 4).execute();
    for(int i=0; i<4; i++)
        cout << output[i] <<endl;

    return 0;
}
