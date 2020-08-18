#include <iostream>
#include<ComputationalModel.h>

using namespace std;

int main()
{
    class ArrayAdditionModel: public ComputationalModel
    {
        virtual void CPUImplementation(int *input, int *output){
            cout << "Hello CPU works world!" << endl;
        }
        virtual void GPUImplementation(int *input, int *output){
            cout << "Hello GPU works world!" << endl;
        }
    } arrayAdditionModel;

    arrayAdditionModel.execute(&a, &b);
    return 0;
}
