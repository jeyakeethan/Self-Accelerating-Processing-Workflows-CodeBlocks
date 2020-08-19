#include <iostream>
#include <computationalmodel.h>
#include <ctime>


using namespace std;

ComputationalModel::ComputationalModel()
{
    //ctor
}

ComputationalModel::~ComputationalModel()
{
    //dtor
}

void ComputationalModel::execute()
{
    bool bounded = true;
/*    if(tCPU+tGPU==0){
        GPUImplementation();
    } else  */

    auto t_start = clock();
    if(tCPU<=tGPU){
        CPUImplementation();
        auto t_end = clock();
        tCPU = (t_end - t_start)/CLOCKS_PER_SEC;
        cout << "CPUtime:" << tCPU <<endl;
    }
    else {
        GPUImplementation();
        auto t_end = clock();
        tCPU = (t_end - t_start)/CLOCKS_PER_SEC;
        cout << "GPUtime:" << tGPU <<endl;
    }

    //auto time = end
        //auto end_time = std::chrono::high_resolution_clock::now();
          // tCPU = end_time - start_time;_time - start_time;
    // std::cout << time/chrono::milliseconds(1) << "ms\n";
}
