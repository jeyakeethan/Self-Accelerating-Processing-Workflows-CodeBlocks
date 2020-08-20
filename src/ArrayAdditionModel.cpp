#include <iostream>
#include<ComputationalModel.h>

using namespace std;

#define THREATS_PER_BLOCK 1000

 __global__ void Vector_Addition ( const int *dev_a , const int *dev_b , int *dev_c)
{
      //Get the id of thread within a block
      unsigned short tid = threadIdx.x ;

      if ( tid < THREATS_PER_BLOCK ) // check the boundry condition for the threads
            dev_c [tid] = dev_a[tid] + dev_b[tid] ;

}

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
            //Device array
            int *dev_a , *dev_b, *dev_c;
            //Allocate the memory on the GPU
            cudaMalloc((void **)&dev_a , N*sizeof(int));
            cudaMalloc((void **)&dev_b , N*sizeof(int));
            cudaMalloc((void **)&dev_c , N*sizeof(int));
            //Copy Host array to Device array
            cudaMemcpy (dev_a , localA , N*sizeof(int) , cudaMemcpyHostToDevice);
            cudaMemcpy (dev_b , localB , N*sizeof(int) , cudaMemcpyHostToDevice);
            // Execute the kernel
            Vector_Addition <<< N/THREATS_PER_BLOCK, THREATS_PER_BLOCK>>> (dev_a , dev_b , dev_c);
            //Copy back to Host array from Device array
            cudaMemcpy(localC , dev_c , N*sizeof(int) , cudaMemcpyDeviceToHost);
            //Free the Device array memory
            cudaFree (dev_a);
            cudaFree (dev_b);
            cudaFree (dev_c);
        }
};
