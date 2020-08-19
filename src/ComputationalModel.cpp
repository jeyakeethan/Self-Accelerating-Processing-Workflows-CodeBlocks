#include <iostream>
#include <computationalmodel.h>

#include <windows.h>
#include <iomanip>
#include <set>
#include <time.h>
#include <stdlib.h>

using namespace std;

// ComputationalModel::ComputationalModel(){}

// ComputationalModel::~ComputationalModel(){}

void ComputationalModel::execute()
{
    bool bounded = true;
/*    if(tCPU+tGPU==0){
        GPUImplementation();
    } else  */

    LARGE_INTEGER start, stop, freq;
	QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    if(tCPU<=tGPU){
        CPUImplementation();
        QueryPerformanceCounter(&stop);
    }
    else {
        GPUImplementation();
        QueryPerformanceCounter(&stop);
    }


    // To a async function
    double delay = (double)(stop.QuadPart - start.QuadPart) / (double)freq.QuadPart;
    int time = int(delay * 100000 + 0.5);
    if(tCPU<tGPU){
        tCPU = long(time);
        cout << "CPU Time: " << tCPU << " ms" << endl;
    } else {
        tGPU = long(time);
        cout << "GPU Time: " << tGPU << " ms" << endl;
    }

    cout << tCPU <<","<<tGPU << endl;
}
