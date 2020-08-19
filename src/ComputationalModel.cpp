#include <iostream>
#include <computationalmodel.h>
#include <chrono>

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

    auto start_time = chrono::high_resolution_clock::now();
    if(tCPU<=tGPU){
        CPUImplementation();
        auto end_time = chrono::high_resolution_clock::now();
        auto time = end_time - start_time;
        tCPU = time/std::chrono::milliseconds(1);
           cout << "time:" << tCPU <<endl;
    }
    else {
        GPUImplementation();
        auto end_time = chrono::high_resolution_clock::now();
        auto time = end_time - start_time;
        tGPU = time/std::chrono::milliseconds(1);
          cout << "time:" << time/std::chrono::milliseconds(1) <<endl;
    }

    //auto time = end
        //auto end_time = std::chrono::high_resolution_clock::now();
          // tCPU = end_time - start_time;_time - start_time;
    // std::cout << time/chrono::milliseconds(1) << "ms\n";
}
