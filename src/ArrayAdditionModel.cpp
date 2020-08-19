#include <iostream>
#include<ComputationalModel.h>

using namespace std;

class ArrayAdditionModel: public ComputationalModel
{
    public:
        int *localA, *localB, *localC;
        int localL;
        ArrayAdditionModel(){};
        ArrayAdditionModel(int *in1, int *in2, int *out, int length): localA(in1), localB(in2), localC(out), localL(length) { }
        inline ArrayAdditionModel setData(int *in1, int *in2, int *out, int length){
            localA = in1; localB = in2; localC = out; localL = length;
            return *this;
        }

    private:
        virtual void CPUImplementation(){
            cout << "Hello CPU works!" << endl;
            for(int x = 0; x < localL; x++){
                localC[x] = localA[x] + localB[x];
            }
        }
        virtual void GPUImplementation(){
            cout << "Hello GPU works!" << endl;
            for(int x = 0; x < localL; x++){
                localC[x] = localA[x] + localB[x];
            }
        }
};
